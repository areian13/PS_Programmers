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

struct Song
{
	int idx;
	int play;

	friend bool operator>(const Song& a, const Song& b)
	{
		if (a.play != b.play)
			return a.play > b.play;
		return a.idx < b.idx;
	}
};

struct Genre
{
	vector<Song> songs;
	int sum = 0;

	void Organize()
	{
		for (Song song : songs)
			sum += song.play;
		sort(stoe(songs), greater<Song>());
	}
	friend bool operator>(const Genre& a, const Genre& b)
	{
		return a.sum > b.sum;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
	unordered_map<string, Genre> list;

	int n = genres.size();
	For(n)
		list[genres[i]].songs.push_back({ i,plays[i] });

	vector<Genre> temp;
	for (auto& genre : list)
	{
		genre.second.Organize();
		temp.push_back(genre.second);
	}
	sort(stoe(temp), greater<Genre>());

	vector<int> result;
	For(temp.size())
	{
		Forj(min(2, (int)temp[i].songs.size()))
			result.push_back(temp[i].songs[j].idx);
	}
	return result;
}