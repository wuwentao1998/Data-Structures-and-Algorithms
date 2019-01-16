// 最小的k个数
// 常规的排序解法时间复杂度为O(nlogn),现在我们要寻求O(n)的解法

// 方法一： partition

// 方法二： 创建大小为k的容器存储最小的k个数-->最大堆，或者红黑树等。复杂度为O(nlogk)
#include <queue>
#include <iostream>
using namespace std;

void minK(int* array, int len, int k)
{
    if (array == nullptr || len <=0 || k <=0 || len < k)
        return;

    priority_queue<int> pq;

    for (int i = 0; i < len; ++i)
    {
        if (pq.size() < k)
        {
            pq.push(k);
            continue;
        }
        int max = pq.top();
        int cur = array[i];
        if (cur < max)
        {
            pq.pop();
            pq.push(cur);
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}


/* 测试代码 */

int main(int argc, char const *argv[])
{
    int a[] = {9,8,7,6,5,4,3,2,1};

    minK(a, 9, 4);
    return 0;
}
