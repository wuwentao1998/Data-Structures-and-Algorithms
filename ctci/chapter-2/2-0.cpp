// 题目：a1->a2->a3->...an->b1->b2->b3->...bn ==> a1->b1->a2->b2..->an->bn
struct Node
{
    int val;
    Node* next;

    Node(int Val): val(Val), next(nullptr) {} // 一定要初始化为空指针，否则默认初始化不是空指针
};


void rearrange(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node* slow = head;
    Node* fast = head->next;

    while (fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = slow->next;
    slow = head;

    while (fast->next != nullptr)
    {
        auto t = slow->next;
        slow->next = fast;
        auto p = fast->next;
        fast->next = t;
        slow = t;
        fast = p;
    }
    slow->next = fast;
}

int main(void)
{
    Node* a = new Node(1);
    auto b = new Node(2);
    auto c = new Node(3);
    auto d = new Node(4);
    auto e = new Node(5);
    auto f = new Node(6);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    rearrange(a);
    return 0;
}

