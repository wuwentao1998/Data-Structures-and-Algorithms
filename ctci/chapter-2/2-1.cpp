#include <unordered_set>
using namespace std;

struct Node
{
    int val;
    Node* next;

    Node(int Val): val(Val), next(nullptr) {} // 一定要初始化为空指针，否则默认初始化不是空指针
};

void remove_v1(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    unordered_set<Node*> table;
    Node* prev = nullptr;
    while (head != nullptr)
    {
        if(table.find(head) != table.end())
        {
            prev->next = head->next;
            auto temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            table.insert(head);
            prev = head;
            head = head->next;
        }
    }
}

void remove_v2(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    while (head->next != nullptr)
    {
        auto runner = head;
        int headVal = head->val;
        while (runner->next != nullptr)
        {
            if (runner->next->val == headVal)
            {
                auto temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            }
            else
                runner = runner->next;
        }

        head = head->next;
    }
}