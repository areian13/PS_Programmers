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

int Dist(Pos& a, Pos& b)
{
	return abs(a.y - b.y) + abs(a.x - b.x);
}

int CompLR(int num, Pos& l, Pos& r)
{
	Pos n = { (num - 1) / 3, (num - 1) % 3 };
	return Dist(n, l) - Dist(n, r);
}

bool SelectHand(int num, Pos& l, Pos& r, string& hand)
{
	if (num == 1 || num == 4 || num == 7)
		return true;
	if (num == 3 || num == 6 || num == 9)
		return false;

	int lr = CompLR(num, l, r);
	if (lr < 0)
		return true;
	if (lr > 0)
		return false;
	return (hand == "left");
}

string solution(vector<int> numbers, string hand)
{
	Pos l = { 3, 0 };
	Pos r = { 3, 2 };

	string result = "";
	for (int num : numbers)
	{
		if (num == 0)
			num = 11;

		bool h = SelectHand(num, l, r, hand);
		result += (h ? 'L' : 'R');
		(h ? l : r) = { (num - 1) / 3, (num - 1) % 3 };
	}
	return result;
}