#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

struct Info
{
	int rank, idx;

	friend bool operator>(const Info& a, const Info& b)
	{
		return a.rank < b.rank;
	}
};

int solution(vector<int> rank, vector<bool> attendance)
{
	int n = rank.size();

	vector<Info> tier;
	for (int i = 0; i < n; i++)
	{
		if (attendance[i])
			tier.push_back({ rank[i],i });
	}
	sort(tier.begin(), tier.end(), greater<Info>());

	int result = tier[0].idx * 10000 + tier[1].idx * 100 + tier[2].idx;
	return result;
}