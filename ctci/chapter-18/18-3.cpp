#include <random>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pickRandomly(vector<int> arr, int m)
{
    if (arr.size() < m)
        return vector<int>();

    if (arr.size() == m)
        return arr;

    vector<int> subset(m);
    copy(arr.begin(), arr.begin() + m, subset.begin());

    for (int i = m; i < arr.size(); i++)
    {
        int k = rand() % i;
        if (k < m)
            subset[k] = arr[i];
    }

    return subset;
}

int main(void)
{

}