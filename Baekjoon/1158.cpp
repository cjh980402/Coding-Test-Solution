#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    // 이중리스트 구현을 위한 다음 노드와 이전 노드의 인덱스를 저장하는 배열
    vector<int> next(N), prev(N);
    for (int i = 0; i < N; i++)
    {
        next[i] = (i + 1) % N;
        prev[i] = (i - 1 + N) % N;
    }

    // 각 노드는 삭제되면 next와 prev 배열을 수정해야한다.
    cout << '<' << K;
    next[prev[K - 1]] = next[K - 1];
    prev[next[K - 1]] = prev[K - 1];
    int index = next[K - 1], count = 0, deadCount = 1;

    while (deadCount < N)
    {
        count++;

        // 루프를 돌면서 K번째 원소를 삭제한다.
        if (count == K)
        {
            count = 0;
            next[prev[index]] = next[index];
            prev[next[index]] = prev[index];
            deadCount++;
            cout << ", " << index + 1;
        }

        index = next[index];
    }
    cout << '>';

    return 0;
}