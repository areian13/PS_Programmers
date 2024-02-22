#include <vector>
#include <string>
#include <array>
#include <algorithm>

#define SIZE 3

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<string> pattern = { "12345","21232425","3311224455" };

    array<int, SIZE> cnt = { 0, };
    int n = answers.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cnt[j] += (answers[i] == pattern[j][i % pattern[j].size()] - '0');
    }


    int maxScore = *max_element(cnt.begin(), cnt.end());
    vector<int> result;
    for (int i = 0; i < SIZE; i++)
    {
        if (cnt[i] == maxScore)
            result.push_back(i + 1);
    }
    return result;
}