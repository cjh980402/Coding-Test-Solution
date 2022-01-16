#include <string>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, pair<int, string>> carTime;
    int defaultTime = fees[0], defaultCost = fees[1], unitTime = fees[2], unitCost = fees[3];

    for (const string &r : records)
    {
        istringstream is(r);
        string time, number, type;
        is >> time >> number >> type;

        if (carTime.find(number) == carTime.end())
        {
            // 처음 들어오는 차인 경우: 초기화 수행
            carTime[number] = pair(0, time);
        }
        else if (type == "IN")
        {
            // 입장기록이 있던 차가 재입장 하는 경우: 입장 시간 저장
            carTime[number].second = time;
        }
        else if (type == "OUT")
        {
            // 들어왔던 차가 나가는 경우: 누적 시간 계산 후 입장 시간 초기화
            int inTime = ((carTime[number].second[0] - '0') * 10 + carTime[number].second[1] - '0') * 60 + (carTime[number].second[3] - '0') * 10 + carTime[number].second[4] - '0';
            int outTime = ((time[0] - '0') * 10 + time[1] - '0') * 60 + (time[3] - '0') * 10 + time[4] - '0';
            carTime[number].first += (outTime - inTime);
            carTime[number].second.clear();
        }
    }

    // 그냥 map(ordered)을 사용했기 때문에 차량번호 기준 오름차순 정렬이 되어있음
    for (auto &[number, value] : carTime)
    {
        if (value.second.length() != 0)
        {
            // 입장 시간이 남아있는 경우는 23:59분 출차
            int inTime = ((value.second[0] - '0') * 10 + value.second[1] - '0') * 60 + (value.second[3] - '0') * 10 + value.second[4] - '0';
            int outTime = 23 * 60 + 59;
            value.first += (outTime - inTime);
        }

        // 요금 계산 수행
        answer.push_back(defaultCost + (value.first <= defaultTime ? 0 : ((value.first - defaultTime) / unitTime + ((value.first - defaultTime) % unitTime ? 1 : 0)) * unitCost));
    }

    return answer;
}