#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, value;
    cin >> n;

    priority_queue<int> maxHeap;                            // 최댓값이 top에 있는 최대힙
    priority_queue<int, vector<int>, greater<int>> minHeap; // 최솟값이 top에 있는 최소힙

    cin >> value;
    maxHeap.push(value); // 중앙값을 maxHeap에 포함시킬 것이므로 첫 원소를 maxHeap에 넣고 기준값으로 사용한다.

    for (int i = 1; i < n; i++)
    {
        cin >> value;
        // 기준값과 비교하여 작은 값은 minHeap, 그렇지 않은 값은 maxHeap에 넣는다.
        if (value > maxHeap.top())
        {
            minHeap.push(value); // O(logn)
        }
        else
        {
            maxHeap.push(value); // O(logn)
        }

        // maxHeap과 minHeap의 크기의 균형을 맞춰야한다. 단, maxHeap은 기준을 포함하므로 원소를 1개 더 가질 수 있다.
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top()); // O(logn)
            maxHeap.pop();               // O(logn)
        }
        else if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top()); // O(logn)
            minHeap.pop();               // O(logn)
        }
    }

    fout << maxHeap.top() << "\n";

    fout.close();

    return 0;
}