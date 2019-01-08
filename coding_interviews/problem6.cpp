// 反向打印链表

#include <stack>
#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class List
{
    struct Node
    {
        T val;
        Node* next;
    };

public:
    void rePrint_stack()
    {
        std::stack<Node*> sk;
        Node* t = head;

        while(t != nullptr)
        {
            sk.push(t);
            t = t->next;
        }

        while (!sk.empty())
        {
            T val = sk.top()->val;
            cout << val << endl;
            sk.pop();
        }
    }

    void rePrint_recur() { rePrint_recur(head); }

private:
    void rePrint_recur(Node* head)
    {
        if (head == nullptr)
            return;

        rePrint_recur(head->next);

        T val = head->val;
        cout << val << endl;
    }

    Node* head;
};


