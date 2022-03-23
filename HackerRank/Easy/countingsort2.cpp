#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'countingSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
vector<int> countingSort(const vector<int> &arr)
{
    int count[100] = {0}, n = arr.size();
    vector<int> answer(n);

    // O(n)
    for (int i : arr)
    {
        count[i]++; // 각 원소의 빈도를 계산한다.
    }

    // O(1)
    for (int i = 1; i < 100; i++)
    {
        count[i] += count[i - 1]; // 빈도를 저장한 배열을 누적합 배열로 변환한다.
    }

    // O(n)
    for (int i = n - 1; i >= 0; i--)
    {
        answer[--count[arr[i]]] = arr[i];
        // 배열의 원소가 들어갈 정렬된 위치는 누적합과 같다. 또한 1개를 사용했으므로 값을 1 감소시킨다.
        // 반복문을 뒤에서부터 실행하는 이유: 정렬된 배열에서 같은 값은 뒤쪽부터 들어가기 때문에 stable한 정렬을 할 수 있게 된다.
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = countingSort(arr);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}