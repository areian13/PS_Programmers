#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int n = prices.size();

    stack<int> S;
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!S.empty() && prices[i] < prices[S.top()])
        {
            result[S.top()] = i - S.top();
            S.pop();
        }
        S.push(i);
    }
    while (!S.empty())
    {
        result[S.top()] = n - S.top() - 1;
        S.pop();
    }
    return result;
}