#include <assert.h>

bool invalid = false;

int maxSubarray(int* array, int len)
{
    if (array == nullptr || len <= 0)
    {
        invalid = false;
        return 0;
    }

    int max = 0;
    int cur = 0;
    for (int i  = 0; i < len; ++i)
    {
        if (cur <= 0)
            cur = array[i];
        else
            cur += array[i];

        if (cur > max)
            max =cur;
    }
    return max;
}