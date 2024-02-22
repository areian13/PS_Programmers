#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());

    int n = phone_book.size();
    bool result = true;
    for (int i = 0; i < n - 1; i++)
        result &= (phone_book[i] != phone_book[i + 1].substr(0, phone_book[i].size()));
    return result;
}