#include <climits>
#include <vector>

using namespace std;

void range(vector<int>& arr, int* m, int* n)
{
    int begin = 0;
    int end = arr.size() - 1;

    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            begin = i + 1;
            break;
        }
    }

    for (int j = arr.size() - 1; j > 0; j--)
    {
        if (arr[j] < arr[j - 1])
        {
            end = j - 1;
            break;
        }
    }

    int max = INT_MIN;
    int min = INT_MAX;
    for (int k = begin; k <= end; k++)
    {
        if (arr[k] < min)
            min = arr[k];

        if (arr[k] > max)
            max = arr[k];
    }

    for (int i = begin - 1; i >= 0; i--)
    {
        if (arr[i] < min)
        {
            *m = i + 1;
            break;
        }
    }

    for (size_t j = end + 1; j < arr.size(); j++)
    {
        if (arr[j] > max)
        {
            *n = j - 1;
            break;
        }
    }
}


int main(void)
{
    vector<int> vec{1,2,4,7,10,11,7,12,6,7,16,18,19};
    int m, n;
    range(vec, &m, &n);
    return 0;
}