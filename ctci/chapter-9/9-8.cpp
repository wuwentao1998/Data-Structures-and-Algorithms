#include <vector>
#include <iostream>
using namespace std;

int helper(int n, int denom)
{
    if (n < 5)
        return 1;

    int next = 0;
    switch (denom)
    {
        case 25:
            next = 10;
            break;
        case 10:
            next = 5;
            break;
        case 5:
            next = 1;
            break;
        default:
            return 1;
    }

    int ways = 0;
    for (int i = 0; i * denom <= n; i++)
        ways += helper(n - i * denom, next);

    return ways;
}

int countN(int n)
{
    if (n < 0)
        return 0;

    return helper(n, 25);
}

int main()
{
	cout << countN(100);
	return 0;
}
