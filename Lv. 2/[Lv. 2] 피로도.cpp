#include <vector>

using namespace std;

int BT(int k, vector<bool>& isVisited, vector<vector<int>>& dungeons)
{
	int n = dungeons.size();

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (!isVisited[i] && k >= dungeons[i][0])
		{
			isVisited[i] = true;
			result = max(result, BT(k - dungeons[i][1], isVisited, dungeons) + 1);
			isVisited[i] = false;
		}
	}
	return result;
}

int solution(int k, vector<vector<int>> dungeons)
{
	int n = dungeons.size();
	vector<bool> isVisited(n, false);

	int result = BT(k, isVisited, dungeons);
	return result;
}