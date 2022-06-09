#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); // 입출력을 빠르게 하기 위한 동기화 제거

    int N;
    cin >> N;

    // 입력값의 범위가 작으므로 counting sort의 원리를 이용한다.
    int count[10001] = {0};
    for (int i = 0, temp; i < N; i++)
    {
        cin >> temp;
        count[temp]++;
    }

    // 정렬한 배열을 저장할 필요가 없으므로 누적합 배열, 정렬 결과 배열이 필요가 없다.
    for (int i = 1; i < 10001; i++)
    {
        // 존재하는 개수만큼 출력을 한다.
        for (int j = 0; j < count[i]; j++)
        {
            cout << i << '\n'; // std::endl은 버퍼 flush까지 수행해서 동작이 느리므로 '\n'을 사용한다.
        }
    }

    return 0;
}