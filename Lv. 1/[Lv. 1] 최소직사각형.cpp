#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int n = sizes.size();
    int maxW = 0;
    int maxH = 0;
    for (int i = 0; i < n; i++)
    {
        int w = max(sizes[i][0], sizes[i][1]);
        int h = min(sizes[i][0], sizes[i][1]);

        maxW = max(maxW, w);
        maxH = max(maxH, h);
    }
    int result = maxW * maxH;
    return result;
}