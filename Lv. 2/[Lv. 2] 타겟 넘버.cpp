#include <vector>

using namespace std;

int BT(int k, int sum, int target, vector<int>& numbers)
{
    int n = numbers.size();

    if (k == n)
        return sum == target;

    int result = BT(k + 1, sum + numbers[k], target, numbers) + BT(k + 1, sum - numbers[k], target, numbers);
    return result;
}

int solution(vector<int> numbers, int target)
{
    int result = BT(0, 0, target, numbers);
    return result;
}