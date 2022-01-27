#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer(n);

    for (int i = 0; i < n; i++)
    {
        int sum = arr1[i] | arr2[i]; // 비트 or 연산을 이용하여 지도1과 지도2를 합친다.
        for (int k = 1 << (n - 1); k; k >>= 1)
        {
            answer[i] += (k & sum ? '#' : ' '); // k와 같은 자리의 비트가 1이면 벽을 의미
        }
    }

    return answer;
}