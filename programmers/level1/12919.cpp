#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul)
{
    int index = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin(); // 이터레이터 연산을 통한 위치 계산
    return "김서방은 " + to_string(index) + "에 있다";
}