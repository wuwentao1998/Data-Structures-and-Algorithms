// 找出数组中的重复数字


// 问题1

// 找出重复数字的常规解法有两种
// 第一种为排序法，空间复杂度为O(1),时间复杂度为O(nlogn); 或者使用桶排序，空间复杂度为O(n),时间复杂度为O(n)
// 第二种解法为哈希法，空间复杂度为O(n),时间复杂度为O(n)
// 但是本题还有特殊解法，主要思路为：如果没有重复数字，第 i 个数应该出现在下标为 i 的位置， 空间复杂度为O(1),时间复杂度为O(n)

#include <utility>
#include <assert.h>
using namespace std;

pair<bool, int> duplicate(int array[], int num)
{
    if (array == nullptr || num <= 1)
        return make_pair(false, 0);

    for (int i = 0; i < num; ++i)
    {
        int t = array[i];
        if (t < 0 || t > num - 1)
            return make_pair(false, 0);
    }

    for (int i = 0; i < num; ++i)
    {
        while (array[i] != i)
        {
            int t = array[i];
            if (array[t] == t)
                return make_pair(true, t);
            else
                swap(array[i], array[t]);
        }
    }

    return make_pair(false, 0);
}

// 问题2

// 主要思路为：如果在在 m~n 范围内的数字在数组中出现的次数多余 n - m + 1 次，那么数组一定存在这个范围内的重复数字
// 因此可以结合二分搜索，在不修改原数组的情况下找到重复数字
// 空间复杂度为O(1),时间复杂度为O(nlogn)


int duplicate_2(int array[], int num)
{
    if (array == nullptr || num <= 1)
        return -1;

    for (int i = 0; i < num; ++i)
    {
        int t = array[i];
        if (t < 1 || t > num - 1)
            return -1;
    }

    if (num == 2)
        return 1;

    int low = 1;
    int high = num - 1;
    int mid = (low + high) / 2;
    int sum = mid - low + 1;

    while(low <= high)
    {
        int count = 0;
        for (int j = 0; j < num; ++j)
        {
            if (array[j] >= low && array[j] <= mid)
                ++count;
        }

        if (count == 2 && low == high)
            return low;

        if (count > sum)
            high = mid;
        else
            low = mid + 1;

        mid = (low + high) / 2;
        sum = mid - low + 1;
    }

    return -1;
}



/* 测试代码 */

int main(int argc, char const *argv[])
{
    // 问题1
    int arr[10] = {5, 9, 7, 5, 3, 5, 4, 2, 8, 2};
    assert(duplicate(arr, 10).first == true);
    int array[5] = {4, 2, 1, 3, 0};
    assert(duplicate(array, 5).first == false);
    assert(duplicate(nullptr, 5).first == false);

    // 问题2
    int a1[3] = {1, 1, 2};
    assert(duplicate_2(a1, 3) == 1);
    int a2[3] = {2, 1, 2};
    assert(duplicate_2(a2, 3) == 2);
    int a3[5] = {4, 2, 1, 1, 2};
    int a = duplicate_2(a3, 5);
    assert(a == 1 || a == 2);
    int a4[6] = {4, 5, 3, 3, 1, 2};
    assert(duplicate_2(a4, 6) == 3);

    return 0;
}
