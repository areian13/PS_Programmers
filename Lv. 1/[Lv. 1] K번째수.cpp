#include <vector>
#include <algorithm>

using namespace std;

int CutAndSort(vector<int>& array, vector<int> cmd)
{
    int n = cmd[1] - cmd[0] + 1;

    vector<int> temp(n);
    for (int i = 0; i < n; i++)
        temp[i] = array[i + cmd[0] - 1];
    sort(temp.begin(), temp.end());

    return temp[cmd[2] - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    int n = commands.size();

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = CutAndSort(array, commands[i]);
    return result;
}