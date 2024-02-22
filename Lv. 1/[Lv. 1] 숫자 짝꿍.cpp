#include <string>
#include <array>
#include <algorithm>

using namespace std;

string solution(string X, string Y)
{
    int n = X.size();
    int m = Y.size();

    array<int, 10> cntX = { 0, };
    for (int i = 0; i < n; i++)
        cntX[X[i] - '0']++;

    string result = "";
    for (int i = 0; i < m; i++)
    {
        if (cntX[Y[i] - '0'] > 0)
        {
            cntX[Y[i] - '0']--;
            result += Y[i];
        }
    }
    sort(result.begin(), result.end(), greater<char>());

    if (result == "")
        result = "-1";

    int idx = 0;
    while (result[idx] == '0' && idx < result.size() - 1)
        idx++;
    result = result.substr(idx, result.size() - idx);

    return result;
}