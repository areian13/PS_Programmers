#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, bool> isCounted;

bool IsSosu(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int BT(int num, vector<bool>& isUsed, vector<int>& nums)
{
    int result = !isCounted[num] && IsSosu(num);
    isCounted[num] = true;

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (!isUsed[i])
        {
            isUsed[i] = true;
            result += BT(num * 10 + nums[i], isUsed, nums);
            isUsed[i] = false;
        }
    }
    return result;
}

int solution(string numbers)
{
    int n = numbers.size();

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = numbers[i] - '0';

    vector<bool> isUsed(n, false);
    int result = BT(0, isUsed, nums);
    return result;
}