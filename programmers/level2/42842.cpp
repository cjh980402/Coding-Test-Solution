#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer(2);
    int all = brown + yellow;

    for (int h = 3; h * h <= all; h++)
    {
        if (all % h)
            continue;
        int w = (brown - 2 * h) / 2 + 2;
        if ((w - 2) * (h - 2) == yellow)
        {
            answer[0] = w;
            answer[1] = h;
            break;
        }
    }

    return answer;
}