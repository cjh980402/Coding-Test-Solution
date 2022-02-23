#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'beautifulTriplets' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */
int beautifulTriplets(int d, vector<int> arr)
{
    int answer = 0;
    vector<bool> visit(arr.size(), false);

    for (int i = 0; i < arr.size(); i++)
    {
        // 이미 d간격에 해당하는 경우를 계산한 경우는 제외한다.
        if (visit[i])
            continue;
        visit[i] = true; // 계산 완료 표시

        for (int j = i + 1, before = arr[i]; j < arr.size(); j++)
        {
            if (arr[j] - before > d)
                break; // arr은 오름차순이므로 d보다 차이가 커진 순간 계산할 필요가 없다.
            if (arr[j] - before == d)
            {
                visit[j] = true; // 계산 완료 표시

                if (arr[j] - arr[i] > d)
                {
                    // 답에 해당하는 경우는 d간격을 만족하는 3개의 값을 찾았을 때이므로 2개만 찾아졌을 때는 계산에서 제외해야한다.
                    answer++;
                }
                before = arr[j]; // 계속해서 d간격을 만족하는지 찾아야 하므로 비교할 값을 갱신한다.
            }
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, d;
    cin >> n >> d;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = beautifulTriplets(d, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}