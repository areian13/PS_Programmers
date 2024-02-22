#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end());

    int n = people.size();

    int start = 0;
    int end = n - 1;
    int result = 0;
    while (start <= end)
    {
        if (people[start] + people[end] <= limit)
            start++;

        end--;
        result++;
    }
    return result;
}