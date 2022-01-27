#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    // 시작지점을 변경함으로써 회전을 구현
    for (int start = 0, i; start < s.length(); start++)
    {
        // 스택을 이용한 올바른 괄호 문자열 판별
        stack<char> st;
        for (i = 0; i < s.length(); i++)
        {
            char c = s[(start + i) % s.length()];
            if (st.empty() && (c == ']' || c == '}' || c == ')'))
                break;
            else if (c == '[' || c == '{' || c == '(')
                st.push(c);
            else if ((st.top() == '[' && c == ']') || (st.top() == '{' && c == '}') || (st.top() == '(' && c == ')'))
                st.pop();
            else
                break;
        }
        if (st.empty() && i == s.length())
            answer++;
    }

    return answer;
}