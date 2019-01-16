// 1-n整数中1出现的次数
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

// 方法一：

int One(unsigned int n)
{
    int number = 0;

    while (n > 0)
    {
        if (n % 10 == 1)
            number++;

        n = n / 10;
    }

    return number;
}

int NumberOfOne(unsigned int n)
{
    int number = 0;

    for (int i = 1; i <= n; ++i)
        number += One(i);

    return number;
}

// 方法二：
int NumberOfOne_v2(const string& str)
{
    if (str.empty() || str[0] < '0' || str[0] > '9')
        return;

    int first = str[0] - '0';
    int len = str.size();

    if (len == 1)
        return first == 0 ? 0 : 1;

    int numOfFirstDigit = 0;
    if (first > 1)
        numOfFirstDigit = pow(10, len - 1);
    else
        numOfFirstDigit = atoi(str.substr(1).c_str()) + 1;

    int numOfOtherDigits = first * (len - 1) * pow(10, len - 2);

    int numOfRecursive = NumberOfOne_v2(str.substr(1));

    return numOfFirstDigit + numOfOtherDigits + numOfRecursive;
}

int NumberOfOne_v2(unsigned int n)
{
    string str = to_string(n);
    return NumberOfOne_v2(str);
}

