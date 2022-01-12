#include <string>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int solution(string dirs)
{
    int x = 0, y = 0;
    set<pair<pair<int, int>, pair<int, int>>> road;

    for (char c : dirs)
    {
        pair<int, int> before = make_pair(x, y);
        switch (c)
        {
        case 'U':
            y = min(5, y + 1);
            break;
        case 'D':
            y = max(-5, y - 1);
            break;
        case 'R':
            x = min(5, x + 1);
            break;
        case 'L':
            x = max(-5, x - 1);
            break;
        }
        pair<int, int> now = make_pair(x, y);
        if (before != now)
            road.insert(make_pair(before, now)), road.insert(make_pair(now, before));
    }

    return road.size() / 2;
}