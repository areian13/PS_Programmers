#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    vector<vector<int>> net(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (computers[i][j] == 1)
                net[i].push_back(j);
        }
    }

    vector<bool> isVisited(n, false);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (isVisited[i])
            continue;

        result++;
        isVisited[i] = true;

        queue<int> Q;
        Q.push(i);

        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();

            for (int nxt : net[cur])
            {
                if (isVisited[nxt])
                    continue;

                isVisited[nxt] = true;
                Q.push(nxt);
            }
        }
    }
    return result;
}