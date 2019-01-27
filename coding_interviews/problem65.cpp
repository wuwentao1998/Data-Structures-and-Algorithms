// 不用加减乘除做加法

int add(int a, int b)
{
    int sum, carry;

    do
    {
        sum = a ^ b;
        carry = (a & b) << 1;
        a = sum;
        b = carry;
    } while (b != 0);

    return a;
}

// 不使用新变量而交换两个变量的值

void swap(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}