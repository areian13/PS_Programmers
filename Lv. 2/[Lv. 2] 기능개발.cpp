#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    int n = progresses.size();

    vector<int> result;
    int idx = 0;
    while (idx < n)
    {
        while (progresses[idx] < 100)
        {
            for (int i = 0; i < n; i++)
                progresses[i] += speeds[i];
        }
        int cnt = 0;
        while (idx < n && progresses[idx] >= 100)
        {
            idx++;
            cnt++;
        }
        result.push_back(cnt);
    }
    return result;
}