#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'quickSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
vector<int> quickSort(const vector<int> &arr)
{
    vector<int> answer, equal, right;
    int pivot = arr[0];

    // arr을 피봇과의 대소관계에 따라 3곳으로 분할
    for (int n : arr)
    {
        if (n < pivot)
        {
            answer.push_back(n); // 피봇보다 작은 값
        }
        else if (n == pivot)
        {
            equal.push_back(n); // 피봇이랑 같은 값
        }
        else if (n > pivot)
        {
            right.push_back(n); // 피봇보다 큰 값
        }
    }

    // equal과 right를 answer에 합한다.
    answer.insert(answer.end(), equal.begin(), equal.end());
    answer.insert(answer.end(), right.begin(), right.end());

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

    vector<int> result = quickSort(arr);

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