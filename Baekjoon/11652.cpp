#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    unordered_map<long long, int> count; // 입력값의 범위가 크기 때문에 map을 이용하여 개수를 저장한다.
    int maxCount = 0;
    for (int i = 0; i < N; i++)
    {
        long long card;
        cin >> card;

        maxCount = max(maxCount, ++count[card]); // 최대 정수 개수 갱신
    }

    long long answer = 1LL << 62LL;
    for (const auto &[key, val] : count)
    {
        // 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다.
        if (val == maxCount && key < answer)
        {
            answer = key;
        }
    }

    cout << answer;

    return 0;
}