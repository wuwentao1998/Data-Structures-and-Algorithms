#include <vector>
using std::vector;
const int MAX = 32;

int fetch(int bit, int index)
{
    if (bit & (1 << index))
        return 1;
    else
        return 0;
}

int findMissHelper(vector<int> arr, int index)
{
    if (index >= MAX)
        return 0;

    vector<int> oneBits;
    vector<int> zeroBits;

    for (auto bit: arr)
    {
        if (fetch(bit, index) == 0)
            zeroBits.push_back(bit);
        else
            oneBits.push_back(bit);
    }

    if (zeroBits.size() <= oneBits.size())
    {
        int v = findMissHelper(zeroBits, index + 1);
        return (v << 1) | 0;
    }
    else
    {
        int v = findMissHelper(oneBits, index + 1);
        return (v << 1) | 1;
    }
}

int findMiss(vector<int> arr)
{
    if (arr.empty())
        return 0;

    return findMissHelper(arr, 0);
}

int main(void)
{
    vector<int> a{1,2,4};
    int b = findMiss(a);
}