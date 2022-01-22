#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    vector<int> basket;

    for (int m : moves)
    {
        int doll = 0;
        for (vector<int> &b : board)
        {
            // m번 위치가 비어있지 않은 경우 인형을 선택
            if (b[m - 1] != 0)
            {
                doll = b[m - 1];
                b[m - 1] = 0;
                break;
            }
        }
        // 선택된 인형이 없으면 다음 동작으로 넘어감
        if (doll == 0)
            continue;
        basket.push_back(doll);
        while (basket.size() >= 2)
        {
            int last = basket[basket.size() - 1];
            int secondLast = basket[basket.size() - 2];

            if (last == secondLast)
            {
                // 위 2개가 같은 경우 인형이 터져서 사라짐
                basket.pop_back();
                basket.pop_back();
                answer += 2;
            }
            else
            {
                break;
            }
        }
    }

    return answer;
}