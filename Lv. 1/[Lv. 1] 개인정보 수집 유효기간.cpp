#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int MakeDay(string& date)
{
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8, 2));

    return y * 12 * 28 + m * 28 + d;
}

int DateGap(string& a, string& b)
{
    return MakeDay(a) - MakeDay(b);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    unordered_map<char, int> term;

    int n = terms.size();
    for (int i = 0; i < n; i++)
    {
        char type = terms[i][0];
        int period = stoi(terms[i].substr(2, terms[i].size() - 2));

        term[type] = period * 28;
    }

    int m = privacies.size();
    vector<int> result;
    for (int i = 0; i < m; i++)
    {
        string date;
        char type;

        stringstream ss(privacies[i]);
        ss >> date;
        ss >> type;

        if (DateGap(today, date) >= term[type])
            result.push_back(i + 1);
    }
    return result;
}