#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool CanSwap(string& a, string& b)
{
    int cnt = 0;

    int n = a.size();
    for (int i = 0; i < n; i++)
        cnt += (a[i] != b[i]);
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words)
{
    words.push_back(begin);

    unordered_map<string, vector<string>> graph;
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j || !CanSwap(words[i], words[j]))
                continue;

            graph[words[i]].push_back(words[j]);
            graph[words[j]].push_back(words[i]);
        }
    }

    unordered_map<string, int> dist;

    queue<string> Q;
    Q.push(begin);

    while (!Q.empty())
    {
        string cur = Q.front();
        Q.pop();

        for (string nxt : graph[cur])
        {
            if (dist[nxt] != 0)
                continue;

            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    int result = dist[target];
    return result;
}