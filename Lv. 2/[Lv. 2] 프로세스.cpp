#include <vector>
#include <queue>

using namespace std;

struct Proc
{
    int priority;
    int idx;
};

int solution(vector<int> priorities, int location)
{
    priority_queue<int> PQ;
    queue<Proc> Q;
    int n = priorities.size();
    for (int i = 0; i < n; i++)
    {
        PQ.push(priorities[i]);
        Q.push({ priorities[i],i });
    }

    int result = 0;
    while (!Q.empty())
    {
        if (Q.front().priority == PQ.top())
        {
            result++;
            if (Q.front().idx == location)
                break;

            Q.pop();
            PQ.pop();
        }
        else
        {
            Q.push(Q.front());
            Q.pop();
        }
    }
    return result;
}