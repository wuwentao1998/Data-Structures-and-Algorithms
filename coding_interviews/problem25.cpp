

// 合并链表
struct Node
{
    int val;
    Node* next;

    Node(int Val):
        val(Val), next(nullptr) {}
};


Node* merge(Node* a, Node* b)
{
    if (a == nullptr)
        return b;

    if (b == nullptr)
        return a;

    Node* merged = nullptr;
    if (a->val < b->val)
    {
        merged = a;
        merged->next = merge(a->next, b);
    }
    else
    {
        merged = b;
        merged->next = merge(a, b->next);
    }

    return merged;
}

/* 测试代码 */

int main(int argc, char const *argv[])
{
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    a->next = b;
    c->next = d;
    d->next = e;

    Node* head = merge(a, c);

    return 0;
}