#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    // 주어진 문제는 최소 신장 트리를 구하는 문제와 동일하다 -> 크루스칼 알고리즘
    int answer = 0;
    vector<int> setID(n);

    for (int i = 0; i < n; i++)
        setID[i] = i;

    sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; }); // 비용 기준으로 오름차순 정렬

    // 최종적으로 모든 정점이 같은 집합이어야함 (같은 집합끼리는 통행 가능, 사이클은 없음)
    for (const vector<int> &e : costs)
    {
        // 같은 집합의 정점을 이으면 사이클이 발생하므로 제외
        if (setID[e[0]] == setID[e[1]])
            continue;
        answer += e[2];
        // 아이디 값이 작은 집합을 기준으로 합친다(집합을 구분하고 합치는 것이 크루스칼 알고리즘의 포인트)
        int first = setID[e[0]], second = setID[e[1]], unionSet = min(first, second);
        for (int &id : setID)
        {
            // 조건식에 현재 배열 값을 참조시 도중에 값이 변경될수 있으므로 해당하는 집합 전체 변경 불가능 -> 그러므로 이전에 저장해둔 변수값 사용
            if (id == first || id == second)
                id = unionSet; // 간선을 추가했으므로 e[0]이 포함된 집합과 e[1]이 포함된 집합을 합친다
        }
    }

    return answer;
}