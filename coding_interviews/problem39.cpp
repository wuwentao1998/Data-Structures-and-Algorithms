// 数组中出现次数超过一半的数字
#include <random>

// 解法一：快排中的partition函数
// 因为出现次数超过一半的数字一定是中位数，而我们有办法在O(n)时间内找到第K大的数，这就是partition函数

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b= t;
}

int Partition(int* array, int low, int high)
{
    int random = rand() % (high - low + 1) + low;
    swap(array[low], array[random]);
    int partition = array[low];

    int i = low, j = high + 1;

    while (true)
    {
        while (array[++i] < partition)
            if (i == high)
                break;

        while (array[--j] > partition)
            if (j == low)
                break;

        if (i >= j)
            break;

        swap(array[i], array[j]);
    }

    swap(array[j], array[low]);
    return j;
}

int moreThanHalf_v1(int* array, int low, int high, int half)
{
    int par = Partition(array, low, high);
    if (par == half)
        return array[par];
    else if (par < half)
        return moreThanHalf_v1(array, par + 1, high, half);
    else
        return moreThanHalf_v1(array, low, par - 1, half);
}

int moreThanHalf_v1(int* array, int len)
{
    if (array == nullptr)
        return 0;

    int half = len / 2 - 1;
    return moreThanHalf_v1(array, 0 ,len - 1, half);
}

// 解法二：

int moreThanHalf_v2(int* array, int len)
{
    if (array == nullptr)
        return 0;

    int result = array[0];
    int times = 1;

    for (int i = 1; i < len; ++i)
    {
        if (times == 0)
        {
            result = array[i];
            times = 1;
            continue;
        }

        if (result != array[i])
            times--;
        else
            times++;
    }

    return result;
}

/* 测试代码 */

int main(int argc, char const *argv[])
{
    srand(10);
    int a[] = {3,3,3,3,1,2,4,3,9,3};
    //int j = Partition(a, 0, 9);

    int k = moreThanHalf_v2(a, 10);

    return 0;
}


