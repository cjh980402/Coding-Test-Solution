#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'countSort' function below.
 *
 * The function accepts 2D_STRING_ARRAY arr as parameter.
 */

void countSort(vector<pair<int, string>> arr, int maxX)
{
    // 정렬 목표: 각 pair의 int 값을 기준으로 stable한 정렬 (counting sort 이용)
    int n = arr.size();
    vector<int> counting(maxX + 1);
    vector<string> sorted(n);

    for (int i = 0; i < n; i++)
    {
        // 정렬의 기준값인 first 멤버값의 빈도를 계산한다.
        counting[arr[i].first]++;
    }

    for (int i = 1; i < maxX + 1; i++)
    {
        // 계산된 빈도를 이용하여 누적합을 계산한다.
        counting[i] += counting[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        // arr의 뒤부터 순회하면서 sorted를 채워간다. sorted에서의 현재 원소의 위치는 누적값과 동일하다.
        sorted[counting[arr[i].first] - 1] = arr[i].second;
        // 현재 원소를 sorted에 추가했으므로 누적값을 1만큼 감소시킨다.
        counting[arr[i].first]--;
        // 위와 같이 arr의 뒤 쪽 원소부터 같은 정렬 순위의 뒤쪽에 추가되므로 stable한 정렬을 수행하게 된다.
    }

    for (const string &s : sorted)
    {
        cout << s << ' ';
    }
}

int main()
{
    int n, maxX = 0;
    cin >> n;

    vector<pair<int, string>> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;

        if (maxX < arr[i].first)
            maxX = arr[i].first;
        // 문제에서 주어진 요구사항
        if (i < n / 2)
            arr[i].second = "-";
    }

    countSort(arr, maxX);

    return 0;
}