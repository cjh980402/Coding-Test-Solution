#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(const vector<int> &expenditure, int d)
{
    // 이 문제의 핵심은 크기가 d인 transaction의 중앙값을 빠르게 구하는 방법이다. expenditure의 원소의 범위가 0~200으로 작기 때문에 counting sort를 이용하여 빠르게 탐색할 수 있다.
    int notice = 0;
    int countEx[201] = {0}; // 원소의 범위가 0~200이므로 201칸짜리 배열을 선언한다.

    for (int i = 0; i < d; i++)
    {
        // counting sort를 적용하기 위한 계산, O(n)
        countEx[expenditure[i]]++;
    }

    // 중앙값과 소비 금액 비교 수행, O(n-d)
    for (int i = d; i < expenditure.size(); i++)
    {
        int sum = 0, mid1 = 0, mid2 = 0; // 짝수인 경우의 중앙값은 중앙에 있는 두 값의 평균이므로 값 2개를 다 구해둔다.
        for (int j = 0; j < 202; j++)
        {
            // 항상 201번 실행이므로 O(1)
            sum += countEx[j];
            if (mid1 == 0 && sum >= d / 2)
            {
                // d / 2번째에 해당하는 값을 찾은 경우 (중복 대입을 방지하기 위해 mid1이 0일 때만 저장한다.)
                mid1 = j;
            }
            if (mid2 == 0 && sum >= d / 2 + 1)
            {
                // d / 2 + 1번째에 해당하는 값을 찾은 경우 (중복 대입을 방지하기 위해 mid2가 0일 때만 저장한다.), 그 뒤의 값은 필요없으므로 반복을 종료한다.
                mid2 = j;
                break;
            }
        }

        int median2X = d % 2 ? (2 * mid2) : (mid1 + mid2); // 중앙값의 2배에 해당하는 값
        if (expenditure[i] >= median2X)
        {
            // 알림 전송 조건이 성립한 경우
            notice++;
        }

        countEx[expenditure[i - d]]--; // 기간 지난 날짜의 데이터 제거
        countEx[expenditure[i]]++;     // 현재 날짜의 데이터 추가
    }

    return notice;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, d;
    cin >> n >> d;

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++)
    {
        cin >> expenditure[i];
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}