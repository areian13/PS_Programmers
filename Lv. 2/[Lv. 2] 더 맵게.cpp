#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> PQ;

    int n = scoville.size();
    for (int i = 0; i < n; i++)
        PQ.push(scoville[i]);

    int result = 0;
    while (true)
    {
        if (PQ.size() <= 1 && PQ.top() < K)
        {
            result = -1;
            break;
        }
        else if (PQ.top() >= K)
            break;

        result++;

        int a = PQ.top();
        PQ.pop();
        int b = PQ.top();
        PQ.pop();

        int c = a + 2 * b;
        PQ.push(c);
    }
    return result;
}