#include <vector>
#include <array>

using namespace std;

array<int, 8> dy = { 0,-1,-1,-1,0,1,1,1 };
array<int, 8> dx = { 1,1,0,-1,-1,-1,0,1 };

int solution(vector<vector<int>> board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 1)
                continue;

            for (int k = 0; k < 8; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;
                if (board[ny][nx] == 1)
                    continue;

                board[ny][nx] = 2;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            result += (board[i][j] == 0);
    }
    return result;
}