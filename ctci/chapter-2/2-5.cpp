struct Node
{
    int val;
    Node* next;

    Node(int Val): val(Val), next(nullptr) {} // 一定要初始化为空指针，否则默认初始化不是空指针
};

Node* addLink(Node* a, Node* b)
{
    if (a == nullptr || b == nullptr)
        return nullptr;

    bool carry = false;
    int val = a->val + b->val;
    if (val > 9)
    {
        carry = true;
        val -= 10;
    }
    Node* result = new Node(val);
    Node* ptr = result;
    a = a->next;
    b = b->next;

    while (a != nullptr || b != nullptr)
    {
        val = 0;
        if (a != nullptr)
        {
            val += a->val;
            a = a->next;
        }

        if (b != nullptr)
        {
            val += b->val;
            b = b->next;
        }

        if (carry)
        {
            val++;
            carry = false;
        }

        if (val > 9)
        {
            carry = true;
            val -= 10;
        }

        ptr->next = new Node(val);
        ptr = ptr->next;
    }

    if (carry)
        ptr->next = new Node(1);

    return result;
}

Node* reverse(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* prev = nullptr;

    while (head != nullptr)
    {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
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
    auto t = reverse(a);
    return 0;
}
