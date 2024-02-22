#include <vector>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    array<int, 26> cnt;
    fill(cnt.begin(), cnt.end(), 101);

    int n = keymap.size();
    for (int i = 0; i < n; i++)
    {
        int m = keymap[i].size();
        for (int j = 0; j < m; j++)
            cnt[keymap[i][j] - 'A'] = min(cnt[keymap[i][j] - 'A'], j + 1);
    }

    int t = targets.size();
    vector<int> result(t, 0);
    for (int i = 0; i < t; i++)
    {
        int c = targets[i].size();
        for (int j = 0; j < c; j++)
        {
            if (cnt[targets[i][j] - 'A'] <= 100)
                result[i] += cnt[targets[i][j] - 'A'];
            else
            {
                result[i] = -1;
                break;
            }
        }
    }
    return result;
}