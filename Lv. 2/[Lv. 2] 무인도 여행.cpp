#include <vector>
#include <string>
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

vector<int> solution(vector<string> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] == 'X' || isVisited[i][j])
                continue;

            int cnt = maps[i][j] - '0';

            isVisited[i][j] = true;

            queue<Pos> Q;
            Q.push({ i,j });

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
                    if (maps[ny][nx] == 'X' || isVisited[ny][nx])
                        continue;

                    cnt += maps[ny][nx] - '0';
                    isVisited[ny][nx] = true;
                    Q.push({ ny,nx });
                }
            }
            result.push_back(cnt);
        }
    }

    if (result.empty())
        result.push_back(-1);

    sort(result.begin(), result.end());
    return result;
}