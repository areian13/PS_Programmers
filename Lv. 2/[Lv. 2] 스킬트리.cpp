#include <string>
#include <vector>
#include <array>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    array<bool, 26> isInSkillTree = { false, };
    for (char sk : skill)
        isInSkillTree[sk - 'A'] = true;

    int result = skill_trees.size();
    for (string tree : skill_trees)
    {
        int idx = 0;
        for (char sk : tree)
        {
            if (isInSkillTree[sk - 'A'])
            {
                if (sk == skill[idx])
                    idx++;
                else
                {
                    result--;
                    break;
                }
            }
        }
    }
    return result;
}