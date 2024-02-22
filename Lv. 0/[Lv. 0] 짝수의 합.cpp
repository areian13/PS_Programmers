using namespace std;

int solution(int n)
{
    n /= 2;

    int result = n * (n + 1);
    return result;
}