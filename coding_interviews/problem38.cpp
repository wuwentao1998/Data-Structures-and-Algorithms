// 字符串全排列和组合
#include <cstring>
#include <iostream>
using namespace std;

void swap(char& a, char& b)
{
    char t = a;
    a = b;
    b = t;
}

// 全排列

void permutation(string str,string out, int len)
{
    if (len == 0)
    {
        cout << out <<endl;
        return;
    }

    int length = str.size();
    permutation(str.substr(1), out + str[0], len - 1);
    for (int i = 1; i < length; ++i)
    {
        swap(str[0], str[i]);
        permutation(str.substr(1), out + str[0], len - 1);
        swap(str[0], str[i]);
    }
}

void permutation(string str)
{
    int len = str.size();
    if (len == 0)
        return;

    permutation(str, "", len);
}

// 组合

void combination(string str, int m, int len, string out)
{
    if (m == len)
    {
        cout << out << endl;
        return;
    }

    if (str.empty())
        return;

    combination(str.substr(1), m, len, out);
    combination(str.substr(1), m, len + 1, out + str[0]);
}


void combination(string str)
{
    int len = str.size();
    if (len == 0)
        return;

    for (int i = 1; i <= len; i++)
        combination(str, i, 0, "");
}


/* 测试代码 */

int main(int argc, char const *argv[])
{
    //permutation("abc");
    combination("abc");
    return 0;
}

