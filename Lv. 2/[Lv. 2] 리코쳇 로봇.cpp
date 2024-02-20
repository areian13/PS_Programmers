#include <vector>
#include <array>
#include <string>
#include <queue>

using namespace std;

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

struct Pos
{
	int y, x;
};

int solution(vector<string> board)
{
	int n = board.size();
	int m = board[0].size();

	Pos s, e;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'R')
				s = { i,j };
			if (board[i][j] == 'G')
				e = { i,j };
		}
	}

	vector<vector<int>> dist(n, vector<int>(m, -1));
	dist[s.y][s.x] = 0;

	queue<Pos> Q;
	Q.push(s);

	while (!Q.empty())
	{
		int y = Q.front().y;
		int x = Q.front().x;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y;
			int nx = x;

			while (true)
			{
				ny += dy[i];
				nx += dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m)
					break;
				if (board[ny][nx] == 'D')
					break;
			} 
			ny -= dy[i];
			nx -= dx[i];

			if (dist[ny][nx] != -1)
				continue;

			dist[ny][nx] = dist[y][x] + 1;
			Q.push({ ny,nx });
		}
	}
	int result = dist[e.y][e.x];
	return result;
}