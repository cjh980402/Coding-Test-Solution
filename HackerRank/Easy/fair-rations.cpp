#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'fairRations' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY B as parameter.
 */
string fairRations(vector<int> B)
{
    vector<int> oddIndex;
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] % 2)
        {
            oddIndex.push_back(i); // 홀수가 위치한 인덱스 저장
        }
    }
    if (oddIndex.size() % 2)
    {
        return "NO"; // 홀수가 홀수개 있으면 모두 짝수로 만들 수 없음
    }
    int answer = 0;
    for (int i = 0; i < oddIndex.size(); i += 2)
    {
        answer += 2 * (oddIndex[i + 1] - oddIndex[i]); // 2개의 홀수를 모두 짝수로 만들 때 필요한 비용
    }
    return to_string(answer);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int N;
    cin >> N;

    vector<int> B(N);

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    string result = fairRations(B);

    fout << result << "\n";

    fout.close();

    return 0;
}