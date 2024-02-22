#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> cnt;

    int n = clothes.size();
    for (int i = 0; i < n; i++)
        cnt[clothes[i][1]]++;

    int result = 1;
    for (auto c : cnt)
        result *= (c.second + 1);
    result--;

    return result;
}