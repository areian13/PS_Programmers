#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <random>
#include <type_traits>
#include <numeric>
#include <functional>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;
typedef long double LDOUBLE;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
	for (T& value : vec)
		os << value << ' ';
	return os;
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, array<T, N>& vec)
{
	for (T& value : vec)
		os << value << ' ';
	return os;
}

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
				if (between(y1, i, y2) && between(x1, j, x2))
					map[i][j] = 0;
				elif(map[i][j] != 0)
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

		For(4)
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