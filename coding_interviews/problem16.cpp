// 浮点数的次方

#include <assert.h>

#define PRECISE 0.001

inline bool equalZero(double base)
{
    return (base - 0) < PRECISE;
}

double power(double base, int exp)
{
    if (equalZero(base) && exp >= 0) // 由于
        return 0;

    if (equalZero(base) && exp < 0)
        throw "invalid input: divided by zero";

    if (exp == 0)
        return 1;

    bool flag = false;
    if (exp < 0)
    {
        exp = -exp;
        flag = true;
    }

    for (int i = 1; i < exp; ++i)
        base *= base;

    if (flag)
        return 1.0 / base;
    else
        return base;
}



/* 测试代码 */

int main(int argc, char const *argv[])
{


    return 0;
}

