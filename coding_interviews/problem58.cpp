// 问题1：翻转字符串
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

inline void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

inline void reverse(char* str, int begin, int end)
{
    while(begin < end)
            swap(str[begin++], str[end--]);
}

char* reverse(char* str)
{
    if (str == nullptr)
        return nullptr;

    int len = strlen(str);
    if (len == 0)
        return str;

    reverse(str, 0, len - 1);

    int preBlank = -1;
    for (int i = 0; i < len; i++)
    {
        if (!isspace(str[i]))
            continue;

        reverse(str, preBlank + 1, i - 1);
        preBlank = i;
    }

    return str;
}


// 问题二：左旋转字符串

char* leftRoate(char* str, int n)
{
    if (str == nullptr ||n < 0)
        return nullptr;

    int len = strlen(str);
    if (len == 0 || n >= len)
        return str;

    reverse(str, 0, n - 1);
    reverse(str, n, len - 1);
    reverse(str, 0, len - 1);
    return str;
}

/* 测试代码 */

int main(int argc, char const *argv[])
{
    char* a = new char[100];
    strcpy(a, "abcdefg");

    cout << leftRoate(a, 2);
    return 0;
}
