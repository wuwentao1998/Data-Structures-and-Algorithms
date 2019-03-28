#include <vector>
#include <assert.h>
using namespace std;

int count_v1(int n)
{
    if(n < 0)
        return -1;

    int sum = 0;
    sum += n / 5;
    int five = 25;
    int t = 0;
    while (five < n)
    {
        sum += ++t;
        five *= 5;
    }

    return sum;
}

int count_v2(int n)
{
    if (n < 0)
        return -1;

    int sum = 0;
    for (int i = 5; n / i > 0; i *= 5)
        sum += n / i;

    return sum;
}

int main(void)
{
    assert(count_v1(5) == count_v2(5));
    assert(count_v1(13) == count_v2(13));
    assert(count_v1(22) == count_v2(22));
}