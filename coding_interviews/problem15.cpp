// 位运算

// 问题1：计算一个整数的二进制中1的个数

int countOne_v1(int n)
{
    int count = 0;
    int mask = 1;

    while (mask != 0)
    {
        if (n & mask)
            count++;

        mask = mask << 1;
    }

    return count;
}


int countOne_v2(int n)
{
    int count = 0;

    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }

}

// 问题而：用一条语句判断一个整数是不是2的整数次方

inline bool isPower(int n)
{
    return (n - 1) & n == 0;
}
