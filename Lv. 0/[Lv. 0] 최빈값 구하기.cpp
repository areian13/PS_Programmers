#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1'000

int solution(vector<int> array)
{
    vector<int> cnt(MAX, 0);

    int n = array.size();
    for (int i = 0; i < n; i++)
        cnt[array[i]]++;

    int maxValue = *max_element(cnt.begin(), cnt.end());
    int result = -1;
    for (int i = 0; i < MAX; i++)
    {
        if (cnt[i] == maxValue)
        {
            if (result == -1)
                result = i;
            else
            {
                result = -1;
                break;
            }
        }
    }
    return result;
}