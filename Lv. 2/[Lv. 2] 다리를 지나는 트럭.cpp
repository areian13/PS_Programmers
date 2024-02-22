#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weight)
{
    int n = truck_weight.size();

    queue<int> Q;
    for (int i = 0; i < bridge_length; i++)
        Q.push(0);

    int result = 0;
    int sum = 0;
    int idx = 0;
    while (!Q.empty())
    {
        result++;
        if (idx == n)
        {
            Q.pop();
            continue;
        }

        sum -= Q.front();
        Q.pop();

        if (sum + truck_weight[idx] <= weight && Q.size() < bridge_length)
        {
            sum += truck_weight[idx];
            Q.push(truck_weight[idx]);
            idx++;
        }
        else if (idx < n)
            Q.push(0);

    }
    return result;
}