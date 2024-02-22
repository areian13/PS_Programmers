#include <vector>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int solution(vector<vector<int>> land)
{
    int n = land.size();
    int m = land[0].size();

    vector<int> oilAmount;
    vector<vector<int>> oilMap(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == 0 || oilMap[i][j] != -1)
                continue;

            int idx = oilAmount.size();
            oilMap[i][j] = idx;

            queue<Pos> Q;
            Q.push({ i,j });

            int amount = 1;
            while (!Q.empty())
            {
                int y = Q.front().y;
                int x = Q.front().x;
                Q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;
                    if (land[ny][nx] != 1 || oilMap[ny][nx] != -1)
                        continue;

                    amount++;
                    oilMap[ny][nx] = idx;
                    Q.push({ ny,nx });
                }
            }
            oilAmount.push_back(amount);
        }
    }

    int k = oilAmount.size();
    int result = 0;
    for (int j = 0; j < m; j++)
    {
        vector<bool> isExtracted(k, false);
        int amount = 0;
        for (int i = 0; i < n; i++)
        {
            if (land[i][j] != 1)
                continue;

            int idx = oilMap[i][j];
            amount += oilAmount[idx] * !isExtracted[idx];
            isExtracted[idx] = true;
        }
        result = max(result, amount);
    }
    return result;
}