#include <vector>
#include <iostream>

using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 삽입정렬의 과정
    for (int i = 1; i < n; i++)
    {
        int now = arr[i], bigThanNow = i;

        // 첫번째로 등장하는 현재 값보다 큰 값의 위치 찾기 -> 현재 값이 삽입될 위치
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > now)
            {
                bigThanNow = j;
                break;
            }
        }

        for (int j = i - 1; j >= bigThanNow; j--)
        {
            arr[j + 1] = arr[j]; // 넣을 위치 뒤에 있는 값들을 1칸씩 이동
        }
        arr[bigThanNow] = now; // 현재 값을 올바른 위치에 삽입
    }

    for (int i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}