#include <vector>

using namespace std;

double solution(vector<int> numbers)
{
    int n = numbers.size();

    double result = 0;
    for (int i = 0; i < n; i++)
        result += numbers[i];
    result /= n;

    return result;
}