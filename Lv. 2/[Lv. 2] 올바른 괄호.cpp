#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> S;
    int n = s.size();
    bool result = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            S.push('(');

        else if (s[i] == ')')
        {
            if (S.empty() || S.top() != '(')
            {
                result = false;
                break;
            }
            else
                S.pop();
        }
    }
    result &= S.empty();
    return result;
}