#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> cntTicket;
unordered_map<string, vector<string>> graph;

void BT(int k, int n, string cur, bool& isFound, vector<string>& result)
{
    result.push_back(cur);
    if (k == n)
    {
        isFound = true;
        return;
    }

    for (auto& nxt : graph[cur])
    {
        string ticket = cur + ' ' + nxt;
        if (cntTicket[ticket] == 0)
            continue;

        cntTicket[ticket]--;
        BT(k + 1, n, nxt, isFound, result);

        if (isFound)
            return;

        result.pop_back();
        cntTicket[ticket]++;
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    int n = tickets.size();

    for (int i = 0; i < n; i++)
    {
        graph[tickets[i][0]].push_back(tickets[i][1]);
        cntTicket[tickets[i][0] + ' ' + tickets[i][1]]++;
    }
    for (auto& node : graph)
        sort(node.second.begin(), node.second.end());

    vector<string> result;
    bool isFound = false;
    BT(0, n, "ICN", isFound, result);

    return result;
}