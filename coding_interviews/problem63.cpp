// 股票的最大利润

int maxDiff(int* array, int len)
{
    if (array == nullptr || len < 2)
        return 0;

    int min = array[0];
    int diff = 0;
    for (int i = 1; i < len; i++)
    {
        int cur = array[i];
        int curDiff = array[i] - min;
        if (curDiff < diff)
            diff = curDiff;

        if (cur < min)
            min = cur;
    }

    return diff;
}