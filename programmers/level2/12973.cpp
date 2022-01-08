#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int len = s.length();
    stack<char> st;
    st.push(s[0]);

    for (int i = 1; i < len; i++)
    {
        if (!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
            st.push(s[i]);
    }

    return st.empty() ? 1 : 0;
}