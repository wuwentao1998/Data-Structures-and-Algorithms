// 反转链表

struct Node
{
    int val;
    Node* next;

    Node(int Val):
        val(Val), next(nullptr) {}
};

// 方法1：循环

Node* reverse(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* prev = nullptr;
    Node* result = nullptr;
    while(head != nullptr)
    {
        Node* next = head->next;

        if (next == nullptr)
            result = head;

        head->next = prev;
        prev = head;
        head = next;
    }

    return result;
}

// 方法2：递归法

Node* helper(Node* cur, Node* prev)
{
    Node* next = cur->next;
    cur->next = prev;

    if (next == nullptr)
        return cur;
    else
        return helper(next, cur);
}


Node* reverse_r(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    return helper(head, nullptr);
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
    b->next = c;
    c->next = d;
    d->next = e;

    Node* head = reverse_r(a);
    return 0;
}

