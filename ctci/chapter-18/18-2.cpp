#include <algorithm>
#include <vector>
#include <random>
using namespace std;

inline int randBetween(int low, int high)
{
    return low + rand() % (low - high + 1);
}

void shuffle(vector<int> vec)
{
    for (int i = vec.size() - 1; i > 0; i--)
    {
        int k = randBetween(0, i);
        swap(vec[k], vec[i]);
    }
}

