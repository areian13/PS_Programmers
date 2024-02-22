#include <vector>

using namespace std;

int solution(vector<int> sales, vector<vector<int>> links)
{
	int n = sales.size();
	vector<vector<int>> graph(n + 1);

	int m = links.size();
	for (size_t i = 0; i < m; i++)
		graph[links[i][0]].push_back(links[i][1]);
}