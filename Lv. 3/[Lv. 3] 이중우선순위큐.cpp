#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

template <typename T>
struct DoublePriorityQueue
{
private:
    priority_queue<T> maxHeap;
    priority_queue<T, vector<T>, greater<T>> minHeap;
    unordered_map<T, int> cnt;

public:
    void push(T data)
    {
        maxHeap.push(data);
        minHeap.push(data);
        cnt[data]++;
    }
    void popMax()
    {
        if (maxHeap.empty())
            return;

        cnt[maxHeap.top()]--;
        maxHeap.pop();
        Clean();
    }
    T topMax()
    {
        if (maxHeap.empty())
            return (T)0;

        return maxHeap.top();
    }
    void popMin()
    {
        if (minHeap.empty())
            return;

        cnt[minHeap.top()]--;
        minHeap.pop();
        Clean();
    }
    T topMin()
    {
        if (minHeap.empty())
            return (T)0;

        return minHeap.top();
    }
    void Clean()
    {
        while (!maxHeap.empty() && cnt[maxHeap.top()] == 0)
            maxHeap.pop();
        while (!minHeap.empty() && cnt[minHeap.top()] == 0)
            minHeap.pop();
    }
};

vector<int> solution(vector<string> operations)
{
    DoublePriorityQueue<int> DPQ;

    for (string oper : operations)
    {
        if (oper[0] == 'I')
        {
            int value = stoi(oper.substr(2, oper.size() - 2));
            DPQ.push(value);
        }
        else if (oper == "D 1")
            DPQ.popMax();
        else if (oper == "D -1")
            DPQ.popMin();
    }

    vector<int> result = { DPQ.topMax(),DPQ.topMin() };
    return result;
}