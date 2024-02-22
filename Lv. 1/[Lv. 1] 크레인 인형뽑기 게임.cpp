#include <vector>
#include <stack>

using namespace std;

int GetDoll(int x, vector<vector<int>>& board)
{
    int n = board.size();
    int y = 0;
    while (y < n - 1 && board[y][x] == 0)
        y++;
    int doll = board[y][x];
    board[y][x] = 0;
    return doll;
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    int n = board.size();
    int m = moves.size();

    stack<int> S;
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        int x = moves[i] - 1;

        int doll = GetDoll(x, board);
        if (doll == 0)
            continue;
        else if (S.empty() || S.top() != doll)
            S.push(doll);
        else
        {
            S.pop();
            result += 2;
        }
    }
    return result;
}