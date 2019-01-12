#include <assert.h>

inline bool isEven(int n)
{
    return n % 2 == 0;
}

inline void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void reorder(int*& array, int n)
{
    if (array == nullptr || n <= 1)
        return;

    int i = 0, j = n - 1;

    while ( i < j)
    {
        if(isEven(array[i]))
            swap(array[i], array[j--]);
        else
            i++;
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {2,1,4,3,6,5,8,7};
    int* aa = a;
    int b[] = {2,2,2,2,1,1,1,1};
    int* bb = b;
    int c[] = {1,1,1,2,2};
    int* cc = c;
    int d[] = {1,2,2,1,1};
    int* dd = d;
    reorder(aa, 8);
    reorder(bb, 8);
    reorder(cc, 5);
    reorder(dd, 5);
    return 0;
}

