#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd)
{
    string answer(n, 'O');                // 모두 존재할 때의 답의 값
    stack<int> deleted;                   // 스택은 되돌리기 작업에 제일 적합한 자료구조임 (LIFO)
    vector<int> prev(n + 2), next(n + 2); // 일종의 이중연결리스트 구현체(이유: 이전 노드와의 연결 정보, 다음 노드와의 연결 정보를 저장하기 때문)
    // 단순 벡터로 처리하기엔 선형작업때문에 시간초과 가능성 존재
    // 삭제와 추가가 빠른 자료구조: 연결리스트 (O(1)), map (O(logn)), set (O(logn))
    // set을 이용했을 때 시간초과 발생 (map도 마찬가지일 것)
    // 연결리스트 이용하는 방법으로 다시 순회

    // n+2개 선언한 이유: 첫 원소의 이전값, 마지막 원소의 다음값까지 포함 목적
    for (int i = 0; i < n + 1; i++)
    {
        prev[i] = i - 1; // 이전 값
        next[i] = i + 1;
    }
    // 위와 같은 경우, prev와 next의 1번째가 데이터의 0번째에 대응된다
    k = k + 1; // 커서 값을 1 증가시켜서 데이터의 0번째를 데이터의 1번째로 간주하게 시작한다.

    for (const string &s : cmd)
    {
        // U와 D는 방향만 다름
        if (s[0] == 'U')
        {
            int dist = stoi(s.substr(2));
            // dist만큼 이전으로 이동
            for (int i = 0; i < dist; i++)
            {
                k = prev[k];
            }
        }
        else if (s[0] == 'D')
        {
            int dist = stoi(s.substr(2));
            // dist만큼 다음으로 이동
            for (int i = 0; i < dist; i++)
            {
                k = next[k];
            }
        }
        else if (s[0] == 'C')
        {
            deleted.push(k);
            // 삭제 후처리 수행, O(1)만에 가능하다
            prev[next[k]] = prev[k]; // 삭제된 값의 다음 원소의 이전 원소를 삭제된 값의 이전 원소로 설정
            next[prev[k]] = next[k]; // 삭제된 값의 이전 원소의 다음 원소를 삭제된 값의 다음 원소로 설정
            // 즉, 이중연결리스트에서의 위치 변경
            if (next[k] == n + 1)
                k = prev[k]; // 단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다.
            else
                k = next[k];
        }
        else if (s[0] == 'Z')
        {
            int latestD = deleted.top();
            deleted.pop();
            // 추가 후처리 수행, O(1)만에 가능하다
            prev[next[latestD]] = latestD; // 삭제된 값의 다음 원소의 이전 원소를 삭제된 값으로 재설정
            next[prev[latestD]] = latestD; // 삭제된 값의 이전 원소의 다음 원소를 삭제된 값으로 재설정
            // 즉, 이중연결리스트에서의 위치 복원
        }
    }

    // 답문자열 계산해야함
    while (!deleted.empty())
    {
        answer[deleted.top() - 1] = 'X'; // 삭제 표시, 스택에 들어간 값은 1부터 시작하는 인덱싱
        deleted.pop();
    }

    return answer;
}