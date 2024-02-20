#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
	long long result = 0;

	long long cntDeli = 0;
	long long cntPick = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		cntDeli += deliveries[i];
		cntPick += pickups[i];

		while (cntDeli > 0 || cntPick > 0)
		{
			cntDeli -= cap;
			cntPick -= cap;
			result += (i + 1) * 2;
		}
	}
	return result;
}