#include <assert.h>

#define WIDTH 64
// 问题1：数组中只出现一次的两个数字

// 利用的性质：任何一个数字异或其本身都等于0

int findBit(int num)
{
    int index = 1;
    int musk = 1;

    while ((musk & num) == 0) // & 比 == 优先级低
    {
        index++;
        musk = musk << 1;
    }

    return index;
}

inline bool isBitOne(int num, int index)
{
    int musk = 1 << (index - 1);
    return (num & musk);
}

void findOnce(int* array, int len, int* num1, int* num2)
{
    if (array == nullptr || len <2 || num1 == nullptr || num2 == nullptr)
        return;

    int XOR = 0;
    for (int i = 0; i < len ; i++)
        XOR ^= array[i];

    int bitIndex = findBit(XOR);

    *num1 = *num2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (isBitOne(array[i], bitIndex))
            *num1 ^= array[i];
        else
            *num2 ^= array[i];
    }
}


// 问题2：数组中只出现一次的数字

int findSingle(int* array, int len)
{
    if (array == nullptr || len <= 1)
        return;

    int bitSum[WIDTH] = {0};
    for (int i = 0; i < len; i++)
    {
        int musk = 1;
        for (int j = WIDTH - 1; j >=0; j--)
        {
            int bit = array[i] & musk;
            if (bit)
                bitSum[j]++;
            musk = musk << 1;
        }
    }

    int result = 0;
    for (int i = 0; i < WIDTH; i++)
    {
        result = result << 1;
        result += bitSum[i] % 3;
    }
}


/* 测试代码 */

int main(int argc, char const *argv[])
{
    int a, b;
    int c[] = {2,4,3,6,3,2,5,5};
    findOnce(c, 8, &a, &b);
    assert(a == 4 && b == 6 || a == 6 && b == 4);
    return 0;
}
