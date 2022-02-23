#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'howManyGames' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER d
 *  3. INTEGER m
 *  4. INTEGER s
 */
int howManyGames(int p, int d, int m, int s)
{
    // Return the number of games you can buy
    int answer = 0;

    // 잔액으로 구매 가능한 경우 반복 진행
    while (s >= p)
    {
        answer++;
        s -= p;            // 구매 후 잔액 계산
        p = max(p - d, m); // 게임의 가격은 m미만으로 내려가지 않음
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int p, d, m, s;
    cin >> p >> d >> m >> s;

    int answer = howManyGames(p, d, m, s);

    fout << answer << "\n";

    fout.close();

    return 0;
}