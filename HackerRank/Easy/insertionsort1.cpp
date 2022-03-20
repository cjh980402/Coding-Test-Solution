#include <bits/stdc++.h>

using namespace std;

void printArray(const vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

/*
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */
void insertionSort1(int n, vector<int>& arr)
{
    // 루프를 돌 때마다 i번째 값이 정렬된다.
    for (int i = 0; i < n - 1; i++)
    {
        int min = 1000000, minI = i;
        // 최솟값과 위치 탐색
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[minI = j];
            }
        }
        if (minI == i)
            continue; // 현재 단계에서 최솟값이 맨 앞인 경우 이동 연산 생략 가능

        for (int j = minI - 1; j >= i; j--)
        {
            arr[j + 1] = arr[j]; // 최솟값 앞에 있는 값들을 1칸씩 이동
            printArray(arr);
        }

        arr[i] = min; // 최솟값을 맨 앞에 삽입
        printArray(arr);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort1(n, arr);

    return 0;
}