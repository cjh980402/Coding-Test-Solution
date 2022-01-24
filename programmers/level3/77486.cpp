#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;
    unordered_map<string, string> parent;
    unordered_map<string, int> moneys;

    for (int i = 0; i < enroll.size(); i++)
    {
        // 각 판매원의 추천인 저장
        parent[enroll[i]] = referral[i];
    }

    for (int i = 0; i < seller.size(); i++)
    {
        int money = amount[i] * 100;
        // 위로 타고 올라가면서 수익금 분배를 수행, 분배할 돈이 0원이 되면 바로 종료(시간 절약)
        for (string now = seller[i]; money && now != "-"; now = parent[now])
        {
            int parmoney = money / 10;
            money -= parmoney;
            moneys[now] += money;
            money = parmoney;
        }
    }

    // 답 배열에 저장
    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(moneys[enroll[i]]);

    return answer;
}