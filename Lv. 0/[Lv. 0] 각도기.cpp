using namespace std;

int solution(int angle)
{
    int result = (angle / 90) + (angle > 90) + 1;
    return result;
}