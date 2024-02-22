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

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int n = 101;

    characterY *= 2;
    characterX *= 2;
    itemY *= 2;
    itemX *= 2;

    vector<vector<int>> map(n, vector<int>(n, -1));
    for (vector<int> pos : rectangle)
    {
        int y1 = pos[1] * 2;
        int x1 = pos[0] * 2;
        int y2 = pos[3] * 2;
        int x2 = pos[2] * 2;

        for (int i = y1; i <= y2; i++)
        {
            for (int j = x1; j <= x2; j++)
            {
                if ((y1 < i && i < y2) && (x1 < j && j < x2))
                    map[i][j] = 0;
                else if (map[i][j] != 0)
                    map[i][j] = 1;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(n, -2));
    dist[characterY][characterX] = 0;

    queue<Pos> Q;
    Q.push({ characterY,characterX });

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            if (dist[ny][nx] != -2 || map[ny][nx] != 1)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            Q.push({ ny,nx });
        }
    }
    int result = dist[itemY][itemX] / 2;
    return result;
}