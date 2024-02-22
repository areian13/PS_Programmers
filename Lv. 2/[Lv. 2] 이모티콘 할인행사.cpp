#include <vector>
#include <array>

using namespace std;

const array<int, 4> discount = { 10,20,30,40 };

void BT(int k, vector<int>& discountList, vector<int>& result, vector<vector<int>>& users, vector<int>& emoticons)
{
    int n = users.size();
    int m = emoticons.size();

    if (k == m)
    {
        int join = 0;
        int cost = 0;

        for (int i = 0; i < n; i++)
        {
            int used = 0;
            for (int j = 0; j < m; j++)
            {
                if (users[i][0] <= discountList[j])
                    used += (100 - discountList[j]) * emoticons[j] / 100;
            }
            if (used >= users[i][1])
                join++;
            else
                cost += used;
        }
        if (join > result[0] || (join == result[0] && cost > result[1]))
            result = { join,cost };
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        discountList[k] = discount[i];
        BT(k + 1, discountList, result, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    int m = emoticons.size();

    vector<int> discountList(m, 0);
    vector<int> result(2, 0);
    BT(0, discountList, result, users, emoticons);
    return result;
}