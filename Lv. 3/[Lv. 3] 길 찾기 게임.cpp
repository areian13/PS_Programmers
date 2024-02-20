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

typedef struct Node
{
	int idx;
	int x, y;

	Node* l = nullptr;
	Node* r = nullptr;

	Node(int idx, int x, int y)
	{
		this->idx = idx;
		this->x = x;
		this->y = y;
	}

	friend bool operator<(const Node& a, const Node& b)
	{
		if (a.y != b.y)
			return a.y < b.y;
		return a.x < b.x;
	}
};

class BinaryTree
{
public:
	Node* root = nullptr;

	void Push(const Node& data)
	{
		root = Push(root, data);
	}
	Node* Push(Node* node, const Node& data)
	{
		if (node == nullptr)
			return new Node(data.idx, data.x, data.y);

		if (data.x < node->x)
			node->l = Push(node->l, data);
		else
			node->r = Push(node->r, data);
		return node;
	}
	void Preorder(Node* node, vector<int>& result)
	{
		if (node == nullptr)
			return;

		result.push_back(node->idx);
		Preorder(node->l, result);
		Preorder(node->r, result);
	}
	void Preorder(vector<int>& result)
	{
		Preorder(root, result);
	}
	void Postorder(Node* node, vector<int>& result)
	{
		if (node == nullptr)
			return;

		Postorder(node->l, result);
		Postorder(node->r, result);
		result.push_back(node->idx);
	}
	void Postorder(vector<int>& result)
	{
		Postorder(root, result);
	}
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	priority_queue<Node> PQ;

	int n = nodeinfo.size();
	For(n)
	{
		int idx = i + 1;
		int x = nodeinfo[i][0];
		int y = nodeinfo[i][1];

		PQ.push({ idx,x,y });
	}

	BinaryTree tree;
	while (!PQ.empty())
	{
		tree.Push(PQ.top());
		PQ.pop();
	}

	vector<vector<int>> result(2);
	tree.Preorder(result[0]);
	tree.Postorder(result[1]);
	return result;
}