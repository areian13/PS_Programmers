#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Pos
{
    int y, x;
};

int Dist(Pos& a, Pos& b)
{
    return abs(a.y - b.y) + abs(a.x - b.x);
}

int CompLR(int num, Pos& l, Pos& r)
{
    Pos n = { (num - 1) / 3, (num - 1) % 3 };
    return Dist(n, l) - Dist(n, r);
}

bool SelectHand(int num, Pos& l, Pos& r, string& hand)
{
    if (num == 1 || num == 4 || num == 7)
        return true;
    if (num == 3 || num == 6 || num == 9)
        return false;

    int lr = CompLR(num, l, r);
    if (lr < 0)
        return true;
    if (lr > 0)
        return false;
    return (hand == "left");
}

string solution(vector<int> numbers, string hand)
{
    Pos l = { 3, 0 };
    Pos r = { 3, 2 };

    string result = "";
    for (int num : numbers)
    {
        if (num == 0)
            num = 11;

        bool h = SelectHand(num, l, r, hand);
        result += (h ? 'L' : 'R');
        (h ? l : r) = { (num - 1) / 3, (num - 1) % 3 };
    }
    return result;
}