#include <string>
#include <cmath>
using namespace std;

int countHelper(int num, int n, int digit)
{
    int powerOf10 = (int)pow(10, digit);
    int nextPowerOf10 = 10 * powerOf10;

    int roundDown = num - num % nextPowerOf10;
    int roundUp = roundDown + nextPowerOf10;

    int digit = (num / powerOf10) % 10;
    if (digit < n)
        return roundDown / 10;
    else if (digit == n)
        return roundDown / 10 + num % powerOf10 + 1;
    else
        return roundUp % 10;
}

int countN(int num, int n)
{
    int count = 0;
    int len = to_string(n).size(); // 计算n为几位数
    for (int i = 0; i <len; i++)
        count += countHelper(num, n, i);

    return count;
}