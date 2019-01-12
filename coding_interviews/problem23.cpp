// 链表中环的入口节点

struct Node
{
    int val;
    Node* next;

    Node(int Val):
        val(Val), next(nullptr) {}
};

Node* findCycle(Node* head)
{
    if (head == nullptr)
        return nullptr;

    typedef Node* ptr;
    ptr fast = head, slow = head;

    // step 1

    while(fast != nullptr)
    {
        if (fast->next == nullptr || fast->next->next == nullptr)
            return nullptr;

        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            break;
    }

    // step 2

    int count = 1;
    fast = fast->next;
    while (fast != slow)
    {
        count++;
        fast = fast->next;
    }

    // step 3

    slow = head;
    while (count > 0)
    {
        fast = fast->next;
        count--;
    }

    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}


/* 测试代码 */

int main(int argc, char const *argv[])
{
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    //g->next = c;

    Node* t = findCycle(a);
    return 0;
}
