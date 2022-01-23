#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toTimeString(int hour, int min)
{
    return (hour > 9 ? to_string(hour) : "0"s + (char)(hour + '0')) + ":" + (min > 9 ? to_string(min) : "0"s + (char)(min + '0'));
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer, time_str;

    sort(timetable.begin(), timetable.end()); // 시간순 정렬

    int lastIndex = 0;
    for (int i = 0, time = 540; i < n; i++, time += t)
    {
        // 셔틀의 도착시간 09:00 ~ 09:00 + t * (n-1)까지 t마다
        time_str = toTimeString(time / 60, time % 60);

        // 시간을 고려 안 했을 때 현재 버스에 탈 수 있는 인원의 구간
        auto endIter = min(timetable.end(), timetable.begin() + lastIndex + m);
        // 시간을 고려했을 때 현재 차에 탑승 가능한 마지막 사람의 다음 사람
        auto lastCrew = upper_bound(timetable.begin() + lastIndex, endIter, time_str);
        int nowBus = lastCrew - (timetable.begin() + lastIndex); // 현재 버스의 탑승 인원
        lastIndex += nowBus;

        if (nowBus >= m && i == n - 1)
        {
            // 마지막 버스에 남는 자리가 없는 경우
            string last = *(endIter - 1);                                                                         // 마지막 버스 탑승자 중 제일 늦은 사람
            int conTime = ((last[0] - '0') * 10 + last[1] - '0') * 60 + (last[3] - '0') * 10 + last[4] - '0' - 1; // 제일 늦은 사람보다 1분 일찍 도착해야함

            answer = toTimeString(conTime / 60, conTime % 60);
        }
    }

    if (answer.length() == 0)
        answer = time_str; // 모든 버스에 자리가 남는 경우는 마지막 버스 도착 시간

    return answer;
}