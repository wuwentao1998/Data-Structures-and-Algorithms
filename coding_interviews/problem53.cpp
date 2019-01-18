// 在数字排序中查找数字
#include <assert.h>

// 问题一：

int firstK(int* data, int len, int k, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;
    if (data[mid] == k)
    {
        if (mid > 0 && data[mid - 1] != k || mid == 0)
            return mid;
        else
            return firstK(data, len, k, start, mid - 1);
    }
    else if (data[mid] > k)
        return firstK(data, len, k, start, mid - 1);
    else
        return firstK(data, len, k, mid + 1, end);
}

int lastK(int* data, int len, int k, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;
    if (data[mid] == k)
    {
        if (mid < len - 1 && data[mid + 1] != k || mid == len - 1)
            return mid;
        else
            return firstK(data, len, k, mid + 1, end);
    }
    else if (data[mid] > k)
        return firstK(data, len, k, start, mid - 1);
    else
        return firstK(data, len, k, mid + 1, end);
}

int count(int* data, int len, int k)
{
    if (data == nullptr || len <= 0)
        return - 1;

    int first = firstK(data, len,k, 0, len - 1);
    int last = lastK(data, len, k, 0, len - 1);

    if (first > -1 && last > -1)
        return last - first + 1;
    else
        return 0;
}

// 问题二：

// 递归解法
int missing(int* array, int len, int begin, int end)
{
    if (begin > end)
        return -1;

    int mid = (begin + end) / 2;
    if (array[mid] > mid)
    {
        if (mid == 0 || array[mid - 1] == mid - 1)
            return mid;
        else
            return missing(array, len, begin, mid - 1);
    }
    else if (array[mid] == mid)
    {
        if (mid == len - 1)
            return len;
        else
            return missing(array, len, mid + 1, end);
    }
    else
        return -1;
}

int missing_v1(int* array, int len)
{
    if (array == nullptr || len <= 0)
        return - 1;

    return missing(array, len, 0, len - 1);
}

// 循环解法

int missing_v2(int* array, int len)
{
    if (array == nullptr || len <= 0)
        return -1;

    int begin = 0, end = len - 1;
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        if (array[mid] > mid)
        {
            if (mid == 0 || array[mid - 1] == mid - 1)
                return mid;
            else
                end = mid - 1;
        }
        else if (array[mid] == mid)
        {
            if (mid == len - 1)
                return len;
            else
                begin = mid + 1;
        }
    }

    return - 1;
}

// 问题三：

int equalIndex(int* array, int len)
{
    if (array == nullptr || len <= 0)
        return -1;

    int begin = 0;
    int end = len - 1;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        if (mid == array[mid])
            return mid;
        else if (mid > array[mid])
        {
            if (mid == 0)
                return - 1;
            else
                end = mid - 1;
        }
        else
        {
            if (mid == len - 1)
                return -1;
            else
                begin = mid + 1;
        }
    }
    return -1;
}



/* 测试代码 */


int main(int argc, char const *argv[])
{
    int a[] = {0,1,2,3};
    int b[] = {1,2,3,4,5};
    int c[] = {1};
    int d[] = {0};
    assert(missing_v1(a, 4) == 4);
    assert(missing_v2(a, 4) == 4);
    assert(missing_v1(b, 5) == 0);
    assert(missing_v2(b, 5) == 0);
    assert(missing_v1(c, 1) == 0);
    assert(missing_v2(c, 1) == 0);
    assert(missing_v1(d, 1) == 1);
    assert(missing_v2(d, 1) == 1);

    return 0;
}
