#include <string>

using namespace std;

string solution(int a, int b)
{
    // 윤년 기준 1월 ~ 12월의 날짜 수
    int monthCount[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 각 요일 이름 저장, 1월 1일이 금요일이므로 금요일부터 시작
    string dayName[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int sum = b - 1;

    for (int i = 1; i < a; i++)
        sum += monthCount[i - 1]; // 지나온 달의 날짜 합계 계산

    return dayName[sum % 7];
}