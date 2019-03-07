
struct Node
{
    int val;
    Node* next;

    Node(int Val): val(Val), next(nullptr) {} // 一定要初始化为空指针，否则默认初始化不是空指针
};

Node* rearrange(Node* head, int x)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node* smaller = nullptr;
    Node* bigger = nullptr;

    while (head != nullptr)
    {
        auto next = head->next;
        if (head->val < x)
        {
            head->next = smaller;
            smaller = head;
        }
        else
        {
            head->next = bigger;
            bigger = head;
        }
        head = next;
    }

    if (smaller == nullptr)
        return bigger;

    head = smaller;
    while (smaller->next != nullptr)
        smaller = smaller->next;

    smaller->next = bigger;
    return head;
}