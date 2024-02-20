#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
	int n = name.size();

	unordered_map<string, int> score;
	for (int i = 0; i < n; i++)
		score[name[i]] = yearning[i];

	int m = photo.size();
	vector<int> result(m, 0);
	for (int i = 0; i < m; i++)
	{
		for (string& p : photo[i])
			result[i] += score[p];
	}
	return result;
}