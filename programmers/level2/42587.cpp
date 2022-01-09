#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int printCount = 0;
    vector<int> copies(priorities);

    sort(copies.begin(), copies.end(), [](int a, int b)
         { return a > b; });

    for (int i = 0; true; i = (i + 1) % priorities.size())
    {
        if (copies[printCount] == priorities[i])
        {
            printCount++;
            if (i == location)
                return printCount;
        }
    }
}