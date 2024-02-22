#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CompNum(string& a, string& b)
{
    int n = a.size();
    int m = b.size();

    int size = max(n, m);
    for (int i = 0; i < size; i++)
    {
        if (a[i % n] != b[i % m])
            return a[i % n] > b[i % m];
    }

    return a[n - 1] > b[m - 1];
}

// 훨씬 간단하나 50% 정도의 속도차이가 나는 것을 확인했다.
/*bool CompNum(string& a, string& b)
{
    return a + b > b + a;
}*/

string solution(vector<int> numbers)
{
    int n = numbers.size();

    vector<string> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = to_string(numbers[i]);
    sort(nums.begin(), nums.end(), CompNum);

    string result = "";
    for (int i = 0; i < n; i++)
        result += nums[i];

    if (result[0] == '0')
        result = "0";

    return result;
}