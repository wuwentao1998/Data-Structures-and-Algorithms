// 圆圈中最后剩下的数字
#include <list>
#include <assert.h>
using namespace std;


// 解法一：链表

int lastNumber(int n, int m)
{
    if (n < 1 || m < 1)
        return -1;

    list<int> numList;
    for (int i = 0; i < n; ++i)
        numList.push_back(i);

    auto cur = numList.begin();
    while (numList.size() > 1)
    {
        for (int i = 1; i < m; i++)
        {
            cur++;
            if (cur == numList.end())
                cur = numList.begin();
        }

        cur = numList.erase(cur);
        if (cur == numList.end())
            cur = numList.begin();
    }

    return *cur;
}



/* 测试代码 */

int main(int argc, char const *argv[])
{
    assert(lastNumber(5,3) == 3);
    return 0;
}
