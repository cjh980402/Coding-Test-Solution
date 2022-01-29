#include <cmath>

using namespace std;

long long solution(long long n)
{
    long long root = sqrt(n);
    return root * root == n ? (root + 1) * (root + 1) : -1;
}