#include <iostream>
using std::cout;

int sign(int x)
{
    int offset = sizeof(int) * 8 - 1;
    return 0x1 & (x >> offset);
}

int findMax(int a, int b)
{
    int c = a - b;
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);

    // 如果a,b不同符号，为了防止溢出，直接使用a的符号
    int diff = sa ^ sb;

    int same = 1 ^ diff;

    int k = diff * sa + same * sc;

    return k * b + (1 - k)* a;
}

int main(void)
{
    cout << findMax(10, 5);
}