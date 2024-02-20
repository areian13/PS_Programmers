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

bool CanSwap(string& a, string& b)
{
	int cnt = 0;

	int n = a.size();
	For(n)
		cnt += (a[i] != b[i]);
	return cnt == 1;
}

int solution(string begin, string target, vector<string> words)
{
	words.push_back(begin);

	unordered_map<string, vector<string>> graph;
	int n = words.size();
	For(n)
	{
		Forj(n)
		{
			if (i <= j || !CanSwap(words[i], words[j]))
				continue;

			graph[words[i]].push_back(words[j]);
			graph[words[j]].push_back(words[i]);
		}
	}

	unordered_map<string, int> dist;

	queue<string> Q;
	Q.push(begin);

	while (!Q.empty())
	{
		string cur = Q.front();
		Q.pop();

		for (string nxt : graph[cur])
		{
			if (dist[nxt] != 0)
				continue;

			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	int result = dist[target];
	return result;
}