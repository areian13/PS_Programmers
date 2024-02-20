#include <array>
#include <string>

using namespace std;

string solution(string s)
{
	int n = s.size();

	array<int, 26> cnt = { 0, };
	for (int i = 0; i < n; i++)
		cnt[s[i] - 'a']++;

	string result = "";
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == 1)
			result += (i + 'a');
	}
	return result;
}