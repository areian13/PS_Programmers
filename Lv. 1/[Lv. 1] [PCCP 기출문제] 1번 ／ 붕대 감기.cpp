#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];

    int n = attacks.size();
    int result = health;
    for (int i = 0; i < n; i++)
    {
        int s = attacks[i][0] - (i == 0 ? 0 : attacks[i - 1][0]) - 1;
        int heal = s * x + s / t * y;

        result = min(result + heal, health);

        result -= attacks[i][1];
        if (result <= 0)
        {
            result = -1;
            break;
        }
    }

    return result;
}