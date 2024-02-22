#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int n = arr.size();
    arr.push_back(-1);

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[i + 1])
            result.push_back(arr[i]);
    }
    return result;
}