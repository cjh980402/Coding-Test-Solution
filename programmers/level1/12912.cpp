using namespace std;

long long solution(int a, int b)
{
    if (a > b)
    {
        return solution(b, a);
    }
    return (long long)(b - a + 1) * (a + b) / 2;
}