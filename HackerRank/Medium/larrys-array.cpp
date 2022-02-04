#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void makeTargetFirst(vector<int> &A, int target, int i)
{
    if (i + 2 >= A.size())
        return;

    // target을 A[i]로 옮길 때까지 반복한다.
    for (int first = A[i]; first != target; first = A[i])
    {
        A[i] = A[i + 1];
        A[i + 1] = A[i + 2];
        A[i + 2] = first;
    }
}

/*
 * Complete the 'larrysArray' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY A as parameter.
 */

string larrysArray(vector<int> A)
{
    bool isPossible = true;

    for (int target = 1; isPossible && target <= A.size(); target++)
    {
        // A에서의 target의 위치를 탐색한다.
        int targetI = 0;
        for (; A[targetI] != target; targetI++)
            ;

        while (1)
        {
            int moveI = max(targetI - 2, target - 1);

            makeTargetFirst(A, target, moveI);

            if (A[moveI] != target)
            {
                // target이 이동되지 않은 경우는 더 이상 로테이션 수행이 불가능하므로 정렬도 진행할 수 없다.
                isPossible = false;
                break;
            }
            else if (moveI == target - 1)
            {
                // target이 정렬된 자리에 도착한 경우 반복을 종료한다.
                break;
            }
            else
            {
                // target이 정렬된 자리에 도착하지 못했으므로 반복을 진행한다.
                targetI = moveI;
            }
        }
    }

    return isPossible ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split(rtrim(A_temp_temp));

        vector<int> A(n);

        for (int i = 0; i < n; i++)
        {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}