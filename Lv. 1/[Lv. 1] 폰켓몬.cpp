#include <vector>
#include <array>

using namespace std;

#define SIZE 200'000

int solution(vector<int> nums)
{
    int n = nums.size();

    array<int, SIZE + 1> cnt = { 0, };
    for (int i = 0; i < n; i++)
        cnt[nums[i]]++;

    int cntKind = 0;
    for (int i = 1; i <= SIZE; i++)
        cntKind += (cnt[i] != 0);

    int result = min(cntKind, n / 2);
    return result;
}