#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Time
{
    int call;
    int run;

    friend bool operator<(const Time& a, const Time& b)
    {
        if (a.call != b.call)
            return a.call < b.call;
        return a.run < b.run;
    }
    friend bool operator>(const Time& a, const Time& b)
    {
        return a.run > b.run;
    }
};

int solution(vector<vector<int>> jobs)
{
    int n = jobs.size();

    vector<Time> times(n);
    for (int i = 0; i < n; i++)
        times[i] = { jobs[i][0],jobs[i][1] };
    sort(times.begin(), times.end());

    priority_queue<Time, vector<Time>, greater<Time>> PQ;
    int result = 0;
    int time = 0;
    int idx = 0;
    while (idx < n || !PQ.empty())
    {
        while (idx < n && times[idx].call <= time)
        {
            PQ.push(times[idx]);
            idx++;
        }

        if (!PQ.empty())
        {
            time += PQ.top().run;
            result += time - PQ.top().call;
            PQ.pop();
        }
        else
            time = times[idx].call;
    }
    result /= n;
    return result;
}