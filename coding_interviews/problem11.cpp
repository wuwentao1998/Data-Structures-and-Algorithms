// 旋转数组的最小元素
#include <assert.h>

int minInorder(int* array, int first, int last)
{
    int min = array[first];

    for (int i = first + 1; i <= last; ++i)
    {
        if (min > array[i])
            min = array[i];
    }

    return min;
}


int minElement(int* array, int len)
{
    if (array == nullptr || len <= 0)
        throw "invalid parameters!";

    if (len == 1)
        return array[0];

    if (len == 2)
        return (array[0] > array[1]) ? array[1] : array[0];

    int i = 0;
    int j = len - 1;

    if (array[i] < array[j])
        return array[0];

    while (j - i > 1)
    {
        int mid = (i + j) / 2;

        if (array[i] == array[j] && array[j] == array[mid])
            return minInorder(array, i, j);

        if (array[mid] >= array[i])
            i = mid;
        else if (array[mid] <= array[j])
            j = mid;
    }

    return array[j];
}

/* 测试代码 */

int main(int argc, char const *argv[])
{
    int a[] = {3,4,5,1,2};
    int b[] = {1,2,3,4,5};
    int c[] = {1,1,1};
    int d[] = {1,1,1,1};
    int e[] = {3,4,5,3};
    int f[] = {3,4,5,5,2,2};
    int g[] = {1,0,1,1,1};
    int h[] = {1,1,1,0,1};
    assert(minElement(a, 5) == 1);
    assert(minElement(b, 5) == 1);
    assert(minElement(c, 3) == 1);
    assert(minElement(d, 4) == 1);
    assert(minElement(e, 4) == 3);
    assert(minElement(f, 6) == 2);
    assert(minElement(g, 5) == 0);
    assert(minElement(h, 5) == 0);
    return 0;
}
