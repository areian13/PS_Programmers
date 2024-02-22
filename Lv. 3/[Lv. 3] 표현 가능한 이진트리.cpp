#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool IsFullBinTree(int start, int end, string& binTree)
{
    if (start > end)
        return true;

    int mid = (start + end) / 2;
    if (binTree[mid] == '0')
    {
        for (int i = start; i <= end; i++)
        {
            if (binTree[i] == '1')
                return false;
        }
        return true;
    }

    return IsFullBinTree(mid + 1, end, binTree) && IsFullBinTree(start, mid - 1, binTree);
}

bool CanMakeBinTree(long long num)
{
    string binTree = "";
    while (num > 0)
    {
        binTree += '0' + (num % 2);
        num /= 2;
    }

    int n = binTree.size();
    int r = log2(n) + 1;
    int size = 1 << r;
    for (int i = 0; i < size - n; i++)
        binTree += '0';

    return IsFullBinTree(0, binTree.size() - 1, binTree);
}

vector<int> solution(vector<long long> numbers)
{
    int n = numbers.size();

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = CanMakeBinTree(numbers[i]);
    return result;
}
