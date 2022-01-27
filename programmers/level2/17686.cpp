#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files)
{
    stable_sort(files.begin(), files.end(), [](const string &a, const string &b)
                {
                    string a_head, b_head;
                    int a_num_count = 0, b_num_count = 0, a_num = 0, b_num = 0;
                    for (char ac : a)
                    {
                        char c = toupper(ac);
                        if (!a_num_count && ('0' > c || c > '9'))
                            a_head += c;
                        else if (a_num_count < 5 && '0' <= c && c <= '9')
                            a_num_count++, a_num = a_num * 10 + (c - '0');
                        else
                            break; // tail 만나면 바로 탈출
                    }
                    for (char bc : b)
                    {
                        char c = toupper(bc);
                        if (!b_num_count && ('0' > c || c > '9'))
                            b_head += c;
                        else if (b_num_count < 5 && '0' <= c && c <= '9')
                            b_num_count++, b_num = b_num * 10 + (c - '0');
                        else
                            break; // tail 만나면 바로 탈출
                    }

                    return (a_head == b_head) ? ((a_num == b_num) ? false : (a_num < b_num)) : (a_head < b_head);
                });
    return files;
}