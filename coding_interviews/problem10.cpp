// 斐波那契数列的计算
// 青蛙跳台阶问题实质是一个斐波那契数列问题

#include <assert.h>

//尾递归实现

long fibonacci_R(int first, int second, int n)
{
    if (n == 1)
        return first;

    return fibonacci_R(second, first + second, n - 1);
}

long fibonacci_R(int n)
{
    if (n <= 0)
        throw "invalid input";

    return fibonacci_R(1, 1, n);
}


// 循环实现

long fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;

    int first = 1;
    int second = 1;
    int result = 0;

    for (int i = 2; i < n; i++)
    {
        result = first + second;
        first = second;
        second = result;
    }

    return result;
}




/*测试代码*/

int main(int argc, char const *argv[])
{
    assert(fibonacci(10) == 55);
    assert(fibonacci_R(10) == 55);
    assert(fibonacci(1) == 1);
    assert(fibonacci_R(1) == 1);
    return 0;
}
