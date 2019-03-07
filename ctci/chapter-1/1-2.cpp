#include <cstring>
#include <algorithm>
using std::swap;

void reverse(char* str)
{
    if (str == nullptr || strlen(str) <= 1)
        return;

    int end = strlen(str) - 1;
    int begin = 0;
    while (begin < end)
        swap(str[begin++], str[end--]);
}