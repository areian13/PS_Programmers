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

bool CompNum(string& a, string& b)
{
	int n = a.size();
	int m = b.size();

	int size = max(n, m);
	For(size)
	{
		if (a[i % n] != b[i % m])
			return a[i % n] > b[i % m];
	}

	return a[n - 1] > b[m - 1];
}

// 훨씬 간단하나 50% 정도의 속도차이가 나는 것을 확인했다.
/*bool CompNum(string& a, string& b)
{
	return a + b > b + a;
}*/

string solution(vector<int> numbers)
{
	int n = numbers.size();
	
	vector<string> nums(n);
	For(n)
		nums[i] = to_string(numbers[i]);
	sort(stoe(nums), CompNum);

	string result = "";
	For(n)
		result += nums[i];
	if (result[0] == '0')
		result = "0";

	return result;
}