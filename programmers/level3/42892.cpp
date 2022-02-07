#include <vector>
#include <algorithm>

using namespace std;

class node
{
    // 트리를 구성할 노드 클래스 정의
public:
    int x;
    int y;
    int number;
    node *left = nullptr;
    node *right = nullptr;

    node(int x, int y, int number) : x(x), y(y), number(number) {}
};

void preorder(node *n, vector<int> &path)
{
    // 전위 순회를 수행하는 재귀 함수
    if (n == nullptr)
        return;

    path.push_back(n->number);
    preorder(n->left, path);
    preorder(n->right, path);
}

void postorder(node *n, vector<int> &path)
{
    // 후위 순회를 수행하는 재귀 함수
    if (n == nullptr)
        return;

    postorder(n->left, path);
    postorder(n->right, path);
    path.push_back(n->number);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer(2);
    vector<node *> nodes(nodeinfo.size());

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        // 들어온 정보를 이용하여 노드 생성 (동적할당)
        nodes[i] = new node(nodeinfo[i][0], nodeinfo[i][1], i + 1);
    }

    sort(nodes.begin(), nodes.end(), [](const node *a, const node *b)
         { return (a->y) > (b->y); }); // 트리는 위에서부터 순차적으로 만들어져야 하므로 y좌표의 내림차순으로 정렬한다.

    node *head = nullptr; // 트리의 루트노드

    for (node *n : nodes)
    {
        if (head == nullptr)
        {
            // 헤드가 비어있는 경우 값을 설정해준다.
            head = n;
        }
        else
        {
            node *now = head;
            while (1)
            {
                // 위에서부터 x좌표를 비교하면서 아래로 내려간다.
                if (n->x < now->x)
                {
                    // 탐색된 자리가 비어있으면 값을 설정해주고 반복을 종료한다.
                    if (now->left == nullptr)
                    {
                        now->left = n;
                        break;
                    }
                    // 비어있지 않은 경우는 탐색을 계속 진행한다.
                    now = now->left;
                }
                else
                {
                    // 탐색된 자리가 비어있으면 값을 설정해주고 반복을 종료한다.
                    if (now->right == nullptr)
                    {
                        now->right = n;
                        break;
                    }
                    // 비어있지 않은 경우는 탐색을 계속 진행한다.
                    now = now->right;
                }
            }
        }
    }

    preorder(head, answer[0]);  // 전위 순회 수행
    postorder(head, answer[1]); // 후위 순회 수행

    // 동적할당된 노드를 delete
    for (node *&n : nodes)
    {
        delete n;
        n = nullptr;
    }

    head = nullptr;

    return answer;
}