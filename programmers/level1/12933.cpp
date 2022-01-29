#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n)
{
    string n_str = to_string(n); // 문자열 변환

    sort(n_str.rbegin(), n_str.rend()); // 내림차순 정렬

    return stoll(n_str); // long long 변환
}