#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */
int minimumNumber(int n, const string &password)
{
    // Return the minimum number of characters to make the password strong
    int leakLen = max(6 - n, 0); // 부족한 길이의 값
    int hasNum = 0, hasLower = 0, hasUpper = 0, hasSpecial = 0;

    for (char c : password)
    {
        if (isdigit(c))
        {
            hasNum = 1;
        }
        else if (islower(c))
        {
            hasLower = 1;
        }
        else if (isupper(c))
        {
            hasUpper = 1;
        }
        else
        {
            hasSpecial = 1;
        }
    }
    int leakStrong = 4 - hasNum - hasLower - hasUpper - hasSpecial; // 부족한 요소의 개수

    return max(leakLen, leakStrong); // 실제로 추가해야할 글자 수는 둘 중 더 큰 값을 따라가게 된다.
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.get();

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}