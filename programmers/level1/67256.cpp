#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int left = 10, right = 12;

    for (int n : numbers)
    {
        if (n == 1 || n == 4 || n == 7)
        {
            answer += "L";
            left = n;
        }
        else if (n == 3 || n == 6 || n == 9)
        {
            answer += "R";
            right = n;
        }
        else
        {
            n = (n == 0 ? 11 : n);
            int leftD = abs((n - 1) / 3 - (left - 1) / 3) + (left % 3 == 1 ? 1 : 0);
            int rightD = abs((n - 1) / 3 - (right - 1) / 3) + (right % 3 == 0 ? 1 : 0);
            if (leftD < rightD)
            {
                answer += "L";
                left = n;
            }
            else if (leftD > rightD)
            {
                answer += "R";
                right = n;
            }
            else if (hand == "left")
            {
                answer += "L";
                left = n;
            }
            else
            {
                answer += "R";
                right = n;
            }
        }
    }

    return answer;
}