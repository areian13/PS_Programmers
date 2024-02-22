#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    int n = participant.size();
    int m = completion.size();

    unordered_map<string, int> isCompleted;
    for (int i = 0; i < m; i++)
        isCompleted[completion[i]]++;

    string result = "";
    for (int i = 0; i < n; i++)
    {
        if (isCompleted[participant[i]] == 0)
        {
            result = participant[i];
            break;
        }
        isCompleted[participant[i]]--;
    }
    return result;
}