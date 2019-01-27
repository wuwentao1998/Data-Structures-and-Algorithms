// 数组中的逆序对
#include <vector>
#include <algorithm>
#include <assert.h>
#include <iostream>
using namespace std;

//#define DEBUG

void merge(int* array, int low, int high, vector<int>& aux, int* sum)
{
    if (low >= high)
        return;

    int left = 0;
    int right = 0;
    int mid = (low + high) / 2;

    merge(array, low, mid, aux, &left);
    merge(array, mid + 1, high, aux, &right);

    *sum += left + right;
    int i = low;
    int j = mid + 1;



    for (int k = low; k <= high; k++)
    {
        if (i > mid)
            aux[k] = std::move(array[j++]);
        else if (j > high)
        {
            aux[k] = std::move(array[i++]);
            *sum += high - mid;
        }
        else if (array[i] <= array[j])
        {
            aux[k] = std::move(array[i++]);
            *sum += j - mid - 1;
        }
        else if (array[i] > array[j])
            aux[k] = std::move(array[j++]);
    }

    copy(aux.begin() + low, aux.begin() + high + 1, array + low);

    #ifdef DEBUG
    cout << array[0] << endl;
    cout << array[1] << endl;
    cout << array[2] << endl;
    cout << array[3] << endl;
    #endif
}

int inversePair(int* array, int len)
{
    if (array == nullptr || len <= 1)
        return 0;

    int sum = 0;
    vector<int> aux(array, array + len);
    merge(array, 0, len - 1, aux, &sum);
    return sum;
}


/* 测试代码 */


int main(int argc, char* argv[])
{
    int array[] = {7,5,6,4};
    assert(inversePair(array, 4) == 5);
    int array2[] = {1,2,3,4};
    assert(inversePair(array2, 4) == 0);
    int array3[] = {4,3,2,1};
    assert(inversePair(array3, 4) == 6);
    int array4[] = {2,1};
    assert(inversePair(array4, 2) == 1);
    return 0;
}
