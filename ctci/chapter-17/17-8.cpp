#include <climits>

bool error = false;

int sumup(int* arr, int n)
{
    if (arr == nullptr || n <= 0)
    {
        error = true;
        return 0;
    }

    int cur = 0;
    int final = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cur < 0)
            cur = arr[i];
        else
        {
            cur += arr[i];
            if (final < cur)
                final = cur;
        }
    }
    return final;
}