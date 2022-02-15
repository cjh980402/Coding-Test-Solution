#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(const vector<int> &arr)
{
    // 문제에서 요구하는 beautiful array는 오름차순 또는 내림차순으로 정렬된 배열을 의미한다.
    int ascending = 0, descending = 0;
    unordered_map<int, int> asc_indexing, desc_indexing;
    vector<int> asc(arr), asc_temp(arr), desc(arr), desc_temp(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        asc_indexing[arr[i]] = desc_indexing[arr[i]] = i; // 원래 배열에서의 각 값의 인덱스를 저장
    }

    sort(asc.begin(), asc.end());     // 오름차순 정렬
    sort(desc.rbegin(), desc.rend()); // 내림차순 정렬

    for (int i = 0; i < arr.size(); i++)
    {
        if (asc_indexing[asc[i]] != i)
        {
            // 오름차순으로 정렬된 값이 아닌 경우
            ascending++;
            // 정렬했을 때 i번째여야할 값과 실제로 i번째에 있는 값의 인덱스 교환
            int temp_index = asc_indexing[asc[i]];
            asc_indexing[asc[i]] = i;
            asc_indexing[asc_temp[i]] = temp_index;

            // 실제 asc_temp에서 두 값 교환
            asc_temp[temp_index] = asc_temp[i];
            asc_temp[i] = asc[i];
        }
        if (desc_indexing[desc[i]] != i)
        {
            // 내림차순으로 정렬된 값이 아닌 경우
            descending++;
            // 정렬했을 때 i번째여야할 값과 실제로 i번째에 있는 값의 인덱스 교환
            int temp_index = desc_indexing[desc[i]];
            desc_indexing[desc[i]] = i;
            desc_indexing[desc_temp[i]] = temp_index;

            // 실제 desc_temp에서 두 값 교환
            desc_temp[temp_index] = desc_temp[i];
            desc_temp[i] = desc[i];
        }
    }

    return min(ascending, descending); // 더 작은 swap 횟수를 반환한다.
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

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
