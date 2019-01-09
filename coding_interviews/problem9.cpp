#include <stack>
#include <queue>
#include <assert.h>
using namespace std;


// 用两个栈实现队列

template <typename T>
class QU
{
public:
    void appendTail(const T& element)
    {
        stack_1.push(element);
    }

    T deleteHead()
    {
        if (!stack_2.empty())
            {
                T head = stack_2.top();
                stack_2.pop();
                return head;
            }

        while(!stack_1.empty())
        {
            T head = stack_1.top();
            stack_1.pop();
            stack_2.push(std::move(head));
        }

        if (stack_2.empty())
            throw "empty queue!";

        T head = stack_2.top();
        stack_2.pop();
        return head;
    }

private:

    stack<T> stack_1;
    stack<T> stack_2;

};


// 用两个队列实现一个栈

template<typename T>
class SK
{
public:
    void appendTail(const T& element)
    {
        if (queue_1.empty())
            queue_2.push(element);
        else
            queue_1.push(element);
    }

    T deleteHead()
    {
        if (queue_1.empty() && queue_2.empty())
            throw "empty queue!";
        else if (queue_1.empty())
            return deleteHelper(queue_1, queue_2);
        else
            return deleteHelper(queue_2, queue_1);

    }

private:
    T deleteHelper(queue<T>& qu_1, queue<T>& qu_2) // 应该使用引用
    {
        int n = qu_2.size();

        while(n > 1)
        {
            T head = qu_2.front();
            qu_2.pop();
            qu_1.push(std::move(head));
            n--;
        }

        T head = qu_2.front();
        qu_2.pop();
        return head;
    }

    queue<T> queue_1;
    queue<T> queue_2;
};


/* 测试代码 */

int main(int argc, char const *argv[])
{
    QU<int> a;
    a.appendTail(1);
    a.appendTail(2);
    a.appendTail(3);
    a.appendTail(4);
    assert(a.deleteHead() == 1);
    assert(a.deleteHead() == 2);
    a.appendTail(5);
    assert(a.deleteHead() == 3);
    assert(a.deleteHead() == 4);
    assert(a.deleteHead() == 5);

    SK<int> b;
    b.appendTail(1);
    b.appendTail(2);
    b.appendTail(3);
    b.appendTail(4);
    b.appendTail(5);
    assert(b.deleteHead() == 5);
    assert(b.deleteHead() == 4);
    b.appendTail(6);
    b.appendTail(7);
    assert(b.deleteHead() == 7);
    assert(b.deleteHead() == 6);
    assert(b.deleteHead() == 3);

    return 0;
}

