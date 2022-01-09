#include <string>
#include <vector>

using namespace std;

string recursive(const char *num, int k, int originLen, int nowLen)
{
    if (num[0] == 0 || k < 1)
        return string(num);
    if (nowLen >= originLen - k)
        return "";

    int nowRange = k + 1;
    int maxIndex = 0;
    char max = num[0];
    for (int i = 1; i < nowRange; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
            maxIndex = i;
        }
    }

    return max + recursive(num + maxIndex + 1, k - maxIndex, originLen, nowLen + 1);
}

string solution(string number, int k)
{
    return recursive(number.c_str(), k, number.length(), 0);
}