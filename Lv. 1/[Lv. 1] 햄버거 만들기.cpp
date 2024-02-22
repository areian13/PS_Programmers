#include <vector>

using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size();
    vector<int> stack;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int m = stack.size();
        if (nums[i] == 1 && m >= 3)
        {
            if (stack[m - 1] == 3 && stack[m - 2] == 2 && stack[m - 3] == 1)
            {
                for (int j = 0; j < 3; j++)
                    stack.pop_back();

                result++;
                continue;
            }
        }
        stack.push_back(nums[i]);
    }
    return result;
}