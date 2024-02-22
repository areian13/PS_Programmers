#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    sort(citations.begin(), citations.end());

    int n = citations.size();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= citations[i]; j++)
        {
            if (j <= n - i)
                result = max(result, j);
        }
    }
    return result;
}