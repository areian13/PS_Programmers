#include <vector>
#include <array>

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

vector<vector<int>> solution(int n) 
{
	vector<vector<int>> result(n, vector<int>(n, 0));

	int y = 0;
	int x = 0;
	int dir = 0;

	int num = 1;
	while (num <= n * n)
	{
		result[y][x] = num++;

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n || result[ny][nx] != 0)
			dir = (dir + 1) % 4;

		y += dy[dir];
		x += dx[dir];
	}
	return result;
}