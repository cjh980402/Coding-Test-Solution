#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0, pass_count = 0, bridge_sum = 0;
    queue<int> bridge;

    for (int i = 0; i < bridge_length; i++)
        bridge.push(0); // 길이만큼 빈 공간으로 채우기

    for (int i = 0; true;)
    { // 매 반복마다 pop, push 반복 -> 길이 유지
        answer++;
        if (bridge.front() > 0)
        {
            // 트럭이 통과한 경우
            bridge_sum -= bridge.front(); // 합계 갱신
            pass_count++;
            if (pass_count == truck_weights.size())
                break;
        }
        bridge.pop();
        if (i < truck_weights.size() && bridge_sum + truck_weights[i] <= weight)
        {
            // 트럭이 올라갈 수 있는 경우
            bridge_sum += truck_weights[i]; // 합계 갱신
            bridge.push(truck_weights[i]);
            i++;
        }
        else
        {
            // 트럭이 올라갈 수 없는 경우
            bridge.push(0);
        }
    }

    return answer;
}