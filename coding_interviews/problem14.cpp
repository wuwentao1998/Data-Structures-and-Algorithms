// 剪绳子

// 适用动态规划算法问题的特点：
// 1. 求最优解
// 2. 大问题可以分解为小问题
// 3. 小问题之间有重叠

// 一般思路：
// 1. 从大往小思考，从小往大构建
// 2. 一般用一维或者二维数组储存小问题的答案

#include <assert.h>
int maxProduct(int len)
{
    if (len < 2)
        return 0;
    if (len == 2)
        return 1;
    if (len == 3)
        return 2;

    int* product = new int[len + 1];
    product[0] = 0;
    product[1] = 1;
    product[2] = 2;
    product[3] = 3; // 这里其实是从maxProduct(4)开始的计算，此时我们遇到长度为3的绳子还有不继续切割这个选项

    for (int i = 4; i <= len; ++i)
    {
        int max = 0;
        for (int j = 1; j <= i / 2; ++j) // 由于对称性，j不用加到i
        {
            int t = product[j] * product[i - j];
            if (t > max)
                max = t;
        }
        product[i] = max;
    }

    int result = product[len];
    delete[] product;
    return result;
}




/* 测试代码 */

int main(int argc, char const *argv[])
{
    assert(maxProduct(8) == 18);
    assert(maxProduct(9) == 27);
    assert(maxProduct(10) == 36);
    assert(maxProduct(50) == 86093442);

    return 0;
}
