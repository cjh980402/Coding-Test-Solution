using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum += price * (i + 1);
    }

    return (sum - money) > 0 ? (sum - money) : 0;
}