#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'countDistance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

long long countDistance(vector<int> &arr, vector<int> &temp, int start, int end)
{
    // 삽입정렬은 O(n^2)으로 오래걸리기 때문에 병합정렬을 이용하여 삽입정렬에서의 이동거리 합을 구한다.
    // 삽입정렬: 원소 하나의 이동거리가 한 번에 구해진다.
    // 병합정렬: 분할정복을 이용하기 때문에 원소 하나의 이동거리가 단계에 따라 분할되어 구해진다. 최종 이동거리는 그러한 거리들의 합이기 때문에 결국 삽입정렬의 경우와 동일한 값이 나온다.
    long long sum = 0; // 배열의 길이가 길면 값이 크게 나오기 때문에 long long으로 선언한다.

    // 분할을 수행할 수 있는 경우만 진행한다.
    if (start < end)
    {
        int mid = (start + end) / 2;                   // 부분배열은 정확히 중간을 기준으로 나눈다.
        sum += countDistance(arr, temp, start, mid);   // 왼쪽 부분배열
        sum += countDistance(arr, temp, mid + 1, end); // 오른쪽 부분배열

        // 두 부분배열 합치는 과정
        int i = start, j = mid + 1, k = start;
        while (i <= mid && j <= end)
        {
            // 두 배열을 합치는 과정에서 작은 값들을 차례대로 가져오기 때문에 정렬이 수행된다. 또한 값이 같은 경우 왼쪽 부분배열에서 값을 가져오기 때문에 stable한 정렬이다.
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                sum += (j - k); // 오른쪽 부분배열의 원소가 이동한 거리를 더해준다. 이러한 경우는 삽입정렬의 각 단계에서 탐색된 최솟값이 앞부분에 들어가는 것에 대응된다.
                temp[k++] = arr[j++];
            }
        }

        if (i > mid)
        {
            // 왼쪽 부분배열은 다 들어간 경우 남아있는 오른쪽 부분배열의 값을 넣어준다.
            while (j <= end)
            {
                temp[k++] = arr[j++];
            }
        }
        else
        {
            // 오른쪽 부분배열은 다 들어간 경우 남아있는 왼쪽 부분배열의 값을 넣어준다.
            while (i <= mid)
            {
                temp[k++] = arr[i++];
            }
        }

        // 원본 배열에 정렬된 결과를 넣어준다.
        while (start <= end)
        {
            arr[start] = temp[start];
            start++;
        }
    }

    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int n;
        cin >> n;

        vector<int> arr(n), temp(n); // temp에는 임시로 정렬된 결과가 들어간다.

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long result = countDistance(arr, temp, 0, n - 1);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}