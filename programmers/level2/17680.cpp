#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    vector<pair<string, int>> lru;
    map<string, bool> cache;

    for (int i = 0; i < cities.size(); i++)
    {
        string &city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::toupper); // 대문자 변환

        if (cache[city])
        {
            answer++;
            for (auto &[cached, time] : lru)
            {
                if (cached == city)
                    time = i; // 기존에 캐시에 저장된 시간을 갱신
            }
        }
        else
        {
            answer += 5;
            if (cacheSize)
            {
                if (lru.size() == cacheSize)
                {
                    // 캐시가 포화된 경우 삭제 수행
                    cache[lru.back().first] = false;
                    lru.pop_back();
                }
                // 새로운 캐시 삽입
                cache[city] = true;
                lru.push_back(make_pair(city, i));
            }
        }

        sort(lru.begin(), lru.end(), [](const pair<string, int> &a, const pair<string, int> &b)
             { return a.second > b.second; }); // lru를 삽입 시간 순(내림차순)으로 정렬
    }

    return answer;
}