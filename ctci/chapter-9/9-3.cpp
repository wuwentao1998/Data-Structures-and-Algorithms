#include <vector>
#include <iostream>
using namespace std;

int helper(vector<int>& vec, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (vec[mid] == mid)
        return mid;

    if (vec[mid] > mid)
    {
        int left = helper(vec, low, mid - 1);
        if (left > -1)
            return left;
        else
            return helper(vec, vec[mid], high);
    }
    else
    {
        int left = helper(vec, low, vec[mid]);
        if (left > -1)
            return left;
        else
        return helper(vec, mid + 1, high);
    }
}

int magicIndex(vector<int>& vec)
{
    if (vec.empty())
        return -1;

    return helper(vec, 0, vec.size() - 1);
}

int main(void)
{
	vector<int> arr{-40, -30, -1, 1, 2, 3, 5, 7, 9, 12, 13};
	vector<int> arr1{-10, -5, 2, 2, 2, 3, 4, 8, 9, 12, 13};
    cout << magicIndex(arr);
    cout << magicIndex(arr1);
}