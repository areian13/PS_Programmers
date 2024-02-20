#include <vector>
#include <array>
#include <string>

using namespace std;

char KMBTI(string& Kmbti, array<int, 26>& score)
{
	int a = score[Kmbti[0] - 'A'];
	int b = score[Kmbti[1] - 'A'];
	if (a > b)
		return Kmbti[0];
	if (a < b)
		return Kmbti[1];
	return min(Kmbti[0], Kmbti[1]);
}

string solution(vector<string> survey, vector<int> choices)
{
	array<int, 26> score = { 0, };
	int n = survey.size();
	for (int i = 0; i < n; i++)
	{
		int value = choices[i] - 4;
		score[survey[i][value > 0] - 'A'] += abs(value);
	}

	array<string, 4> Kmbti = { "RT","CF","JM","AN" };
	string result = "";
	for (int i = 0; i < 4; i++)
		result += KMBTI(Kmbti[i], score);
	return result;
}