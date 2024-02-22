#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

struct User
{
    string name;
    int point;
    unordered_map<string, int> cnt;
};

int solution(vector<string> friends, vector<string> gifts)
{
    int n = friends.size();
    int m = gifts.size();

    unordered_map<string, User> users;
    for (int i = 0; i < n; i++)
        users[friends[i]].name = friends[i];

    for (int i = 0; i < m; i++)
    {
        stringstream ss(gifts[i]);
        string a, b;
        ss >> a;
        ss >> b;

        users[a].cnt[b]++;
        users[a].point++;
        users[b].point--;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        User& a = users[friends[i]];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            User& b = users[friends[j]];
            cnt += (a.cnt[b.name] > b.cnt[a.name]
                || (a.cnt[b.name] == b.cnt[a.name] && a.point > b.point));
        }
        result = max(result, cnt);
    }

    return result;
}