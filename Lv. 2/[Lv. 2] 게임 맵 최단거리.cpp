#include <vector>
#include <queue>
#include <array>

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[0][0] = 1;

    queue<Pos> Q;
    Q.push({ 0,0 });

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (dist[ny][nx] != -1 || maps[ny][nx] == 0)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            Q.push({ ny,nx });
        }
    }

    int result = dist[n - 1][m - 1];
    return result;
}