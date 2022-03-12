#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'stones' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER a
 *  3. INTEGER b
 */
vector<int> stones(int n, int a, int b)
{
    // a가 더 큰 경우 a와 b를 바꾸어서 호출
    if (a > b)
        return stones(n, b, a);

    // b는 a보다 크거나 a랑 같은 값
    vector<int> answer;

    // a가 많은 경우부터 계산하므로 answer는 자동으로 오름차순
    for (int countA = n - 1; countA >= 0; countA--)
    {
        // 0부터 시작하므로 마지막 돌의 번호는 각 돌의 차이의 누적합과 같음
        // answer에는 중복된 값이 없어야 하므로 a와 b의 개수만 중요함
        int sum = (countA * a) + ((n - 1 - countA) * b); // 각 돌의 차이에서 a가 countA개 있는 경우
        if (answer.empty() || answer.back() != sum)
        {
            // 비어있거나 중복된 값이 아니면 값을 넣어준다.
            answer.push_back(sum);
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;

    for (int T_itr = 0; T_itr < T; T_itr++)
    {
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> result = stones(n, a, b);

        for (size_t i = 0; i < result.size() - 1; i++)
        {
            fout << result[i] << " ";
        }
        fout << result.back() << "\n";
    }

    fout.close();

    return 0;
}