#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

int operRank(char oper, int i)
{
    int multiply[6] = {2, 2, 1, 0, 1, 0};
    int add[6] = {1, 0, 2, 2, 0, 1};
    int minus[6] = {0, 1, 0, 1, 2, 2};
    switch (oper)
    {
    case '*':
        return multiply[i];
    case '+':
        return add[i];
    case '-':
        return minus[i];
    }
}

long long solution(string expression)
{
    int len = expression.length();
    long long answer = 0;

    for (int a = 0; a < 6; a++)
    {
        string num;
        stack<char> opers;
        stack<long long> nums;

        for (int i = 0; i < len; i++)
        {
            char c = expression[i];
            if ('0' <= c && c <= '9')
            {
                num += c;
            }
            if (i == len - 1 || '0' > c || c > '9')
            {
                nums.push(stoi(num));
                num.clear();
                if (opers.empty())
                    opers.push(c);
                else
                {
                    while (!opers.empty() && (i == len - 1 || nums.size() >= 2 && operRank(opers.top(), a) >= operRank(c, a)))
                    {
                        char last = opers.top();
                        opers.pop();
                        long long num2 = nums.top();
                        nums.pop();
                        long long num1 = nums.top();
                        nums.pop();

                        switch (last)
                        {
                        case '*':
                            nums.push(num1 * num2);
                            break;
                        case '+':
                            nums.push(num1 + num2);
                            break;
                        case '-':
                            nums.push(num1 - num2);
                            break;
                        }
                    }
                    opers.push(c);
                }
            }
        }
        long long now = llabs(nums.top());
        if (now > answer)
            answer = now;
    }

    return answer;
}