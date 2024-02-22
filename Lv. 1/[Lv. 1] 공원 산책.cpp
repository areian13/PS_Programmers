#include <vector>
#include <string>
#include <array>

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

bool IsValidCmd(int y, int x, int dist, int dir, vector<string>& park)
{
    int n = park.size();
    int m = park[0].size();

    for (int i = 0; i < dist; i++)
    {
        y += dy[dir];
        x += dx[dir];

        if (y < 0 || y >= n || x < 0 || x >= m)
            return false;
        if (park[y][x] == 'X')
            return false;
    }
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes)
{
    int n = park.size();
    int m = park[0].size();

    int y = 0;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (park[i][j] == 'S')
            {
                y = i;
                x = j;

                goto OUT;
            }
        }
    }
OUT:

    string eswn = "ESWN";
    for (string& cmd : routes)
    {
        int dir = 0;
        while (cmd[0] != eswn[dir])
            dir++;

        int dist = stoi(cmd.substr(2, cmd.size() - 2));
        if (IsValidCmd(y, x, dist, dir, park))
        {
            y += dist * dy[dir];
            x += dist * dx[dir];
        }
    }
    return { y,x };
}