// 打印1到最大的n位数

// 这道题要考虑到n位数可能超过int甚至Long的上限
// 所以正确的做法应该是用字符串操作模拟加法

#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;


// 方法一：循环

bool plusOne(char* number);

void printNum(char* num);

void printLargeNum(int n)
{
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while(plusOne(number))
    {
        printNum(number);
    }

    delete[] number;
    return;
}

bool plusOne(char* number)
{
    int carry = 0;
    int len = strlen(number);

    for (int i = len - 1; i >= 0; --i)
    {
        int digit = number[i] - '0' + carry;
        carry = 0;

        if (i == len - 1)
            ++digit;

        if (digit == 10)
        {
            if (i == 0)
                return false;

            number[i] = '0';
            carry = 1;
        }
        else
        {
            number[i] = digit + '0';
            break;
        }
    }

    return true;
}

void printNum(char* num)
{
    int len = strlen(num);

    bool begin = false;
    for (int i = 0; i < len; ++i)
    {
        if(num[i] == '0' && !begin)
            continue;

        begin = true;
        cout << num[i];
    }
    cout << endl;
}

// 方法二：递归

void print_r(char* number, int index)
{
    int len = strlen(number);
    if (index == len)
    {
        printNum(number);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        number[index] = i + '0';
        print_r(number, index + 1);
    }

}

void printLargeNum_r(int n)
{
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    print_r(number, 0);
}


/* 测试代码 */

int main(int argc, char const *argv[])
{
    printLargeNum(1);
    printLargeNum(2);
    printLargeNum(3);

    printLargeNum_r(1);
    printLargeNum_r(2);
    printLargeNum_r(3);

    return 0;
}

