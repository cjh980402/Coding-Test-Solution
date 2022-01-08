#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
    if (s[0] == ')')
        return false;

    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (!st.empty() && s[i] == ')')
            st.pop();
        else
            st.push(s[i]);
    }

    return st.empty();
}

string solution(string w)
{
    if (w.length() == 0)
        return "";

    int left = 0, right = 0;
    string u, v;
    bool f = false;

    for (int i = 0; i < w.length(); i++)
    {
        if (w[i] == '(')
            left++;
        else
            right++;
        if (f)
            v += w[i];
        else
        {
            u += w[i];
            if (left == right && left > 0)
                f = true;
        }
    }

    if (isValid(u))
        return u + solution(v);
    else
    {
        string tmp = "(" + solution(v) + ")";
        string afterU;
        for (int i = 1; i < u.length() - 1; i++)
            afterU += (u[i] == '(' ? ')' : '(');
        return tmp + afterU;
    }
}