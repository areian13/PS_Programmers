#include <vector>

using namespace std;

int solution(vector<int> array, int height)
{
    int result = 0;
    for (int h : array)
        result += (h > height);
    return result;
}