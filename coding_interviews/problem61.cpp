// 扑克牌中的顺子
#include <algorithm>
#include <assert.h>
using namespace std;

bool isContinuous(int* array, int num)
{
    if (array == nullptr || num < 1)
        return false;

    if (num == 1)
        return true;

    sort(array, array + num);
    int numZero = 0;
    int numGap = 0;

    for (int i = 0; i < num && array[i] == 0; i++)
        numZero++;

    for (int i = 0; i < num - 1; i ++)
    {
        if (array[i] == array[i + 1])
            return false;

        if (array[i + 1] > array[i] + 1)
            numGap +=   array[i + 1] - array[i] - 1;
    }

    return numZero >= numGap;
}


/* 测试代码 */

int main(int argc, char const *argv[])
{
    int a[]  = {1,2,4,5,5,0};
    assert(!isContinuous(a, 6));
    return 0;
}
