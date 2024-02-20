#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
	int n = id_list.size();
	int m = report.size();

	unordered_map<string, vector<string>> ump;
	unordered_map<string, bool> isReported;
	unordered_map<string, int> cnt;
	for (int i = 0; i < m; i++)
	{
		if (isReported[report[i]])
			continue;

		isReported[report[i]] = true;

		stringstream ss(report[i]);
		string reping, reped;
		ss >> reping;
		ss >> reped;

		ump[reping].push_back(reped);
		cnt[reped]++;
	};

	vector<int> result(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (string reported : ump[id_list[i]])
		{
			if (cnt[reported] >= k)
				result[i]++;
		}
	}
	return result;
}