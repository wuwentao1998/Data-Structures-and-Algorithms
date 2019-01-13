// 栈的压入弹出序列
#include <stack>
#include <assert.h>
using namespace std;

bool isPopOrder(const int* push, const int* pop, int len)
{
    if (push == nullptr || pop == nullptr || len <= 0)
        return false;

    stack<int> sk;
    int j = 0;
    for(int i = 0; i < len; ++i)
    {
        if (!sk.empty() && sk.top() == pop[i])
        {
            sk.pop();
            continue;
        }

        while (j < len && push[j] != pop[i] )
            sk.push(push[j++]);

        if (j >= len)
            return false;
        else
            j++;
    }
    return true;
}


/* 测试代码 */


int main(int argc, char const *argv[])
{
    int push[] = {1,2,3,4,5};
    int pop1[] = {4,5,3,2,1};
    int pop2[] = {4,3,5,1,2};
    assert(isPopOrder(push, pop1, 5));
    assert(!isPopOrder(push, pop2, 5));
    return 0;
}

