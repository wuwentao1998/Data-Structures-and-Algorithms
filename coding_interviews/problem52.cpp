// 两个链表的第一个公共界定啊
#include <stack>
#include <assert.h>
using namespace std;

struct Node
{
    int val;
    Node* next;

    Node(int Val):
        val(Val), next(nullptr) {}
};

//方法一：辅助栈

Node* commonNode_v1(Node* a, Node* b)
{
    if (a == nullptr || b == nullptr)
            return nullptr;

    stack<Node*> stackA;
    stack<Node*> stackB;

    while (a != nullptr)
    {
        stackA.push(a);
        a = a->next;
    }

    while (b != nullptr)
    {
        stackB.push(b);
        b = b->next;
    }

    Node* prev = nullptr;
    while (!stackA.empty() && !stackB.empty())
    {
        Node* ta = stackA.top();
        Node* tb = stackB.top();
        if (ta != tb)
            return prev;

        prev = ta;
        stackA.pop();
        stackB.pop();
    }

    return prev;
}

// 方法二：两个指针

Node* commonNode_v2(Node* a, Node* b)
{
    if (a == nullptr || b == nullptr)
        return nullptr;

    int lenA = 0, lenB = 0;
    while (a != nullptr)
    {
        lenA++;
        a = a->next;
    }

    while (b != nullptr)
    {
        lenB++;
        b = b->next;
    }
    int diff = lenA - lenB;

    Node* long = nullptr;
    Node* short = nullptr;
    if (diff > 0)
    {
        long = a;
        short = b;
    }
    else
    {
        long = b;
        short = a;
    }

    for (int i = 0; i < diff; i++)
        long = long->next;

    while(long != nullptr && long != short)
    {
        long = long->next;
        short = short->next;
    }

    return long;
}






