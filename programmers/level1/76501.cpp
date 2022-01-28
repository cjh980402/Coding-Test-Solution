#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
    int answer = 0, len = signs.size();

    for (int i = 0; i < len; i++)
        answer += signs[i] ? absolutes[i] : -absolutes[i];

    return answer;
}