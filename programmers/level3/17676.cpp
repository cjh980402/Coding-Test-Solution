#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<string> lines)
{
    int answer = 0;
    vector<vector<double>> times;

    // 시간 정보 파싱
    for (const string &s : lines)
    {
        double hour, min, second, process;
        string temp1;
        char temp2;
        istringstream is(s);

        is >> temp1 >> hour >> temp2 >> min >> temp2 >> second >> process;
        double end = hour * 3600 + min * 60 + second;
        double start = end - process + 0.001;
        times.push_back({start, end});
    }

    for (int i = 0; i < times.size(); i++)
    {
        double nowStart = times[i][1]; // 종료 시간에 구간을 시작을 해야 최대한 많은 처리시간을 담을 수 있음
        double nowEnd = nowStart + 1;
        int nowCount = 1;

        // 현재 처리시간의 다음 처리시간들부터 구간 내에 존재하는지 탐색
        for (int j = i + 1; j < times.size(); j++)
        {
            // 구간 설정을 위한 부등호에 특히 유의해야 한다.
            if ((nowStart <= times[j][0] && times[j][0] < nowEnd)     // 구간 내에서 시작하는 경우
                || (nowStart <= times[j][1] && times[j][1] < nowEnd)  // 구간 내에서 끝나는 경우
                || (nowStart > times[j][0] && times[j][1] >= nowEnd)) // 구간 이전에 시작해서 구간 밖에서 끝나는 경우
                nowCount++;
        }

        // 큰 값으로 답 갱신
        if (answer < nowCount)
            answer = nowCount;
    }

    return answer;
}