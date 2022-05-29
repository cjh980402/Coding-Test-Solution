#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // 현재 위치의 최대 증가 부분수열 길이 = 이전위치 중에서 현재값보다 작은 값으로 끝나는 증가 부분수열의 최대 길이 + 1(현재값)
    // 증가 수열: n번째 값은 무조건 1~(n-1)번째 값보다 크다.
    // 각 위치에서의 최대 증가 부분수열 길이를 count에 저장한다.
    vector<int> count(N, 1); // 기본적으로 부분수열의 길이는 자신만 존재하는 1이다.
    for (int i = 1; i < N; i++)
    {
        int maxBeforeSub = 0; // 이전위치 중에서 현재값보다 작은 값으로 끝나는 증가 부분수열의 최대 길이
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                maxBeforeSub = max(maxBeforeSub, count[j]); // 현재값보다 작은 값인 경우에 대해 값 갱신
            }
        }
        count[i] += maxBeforeSub;
    }

    cout << *max_element(count.begin(), count.end()); // 최대 길이 출력

    return 0;
}