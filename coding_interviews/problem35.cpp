// 复制复杂链表
#include <unordered_map>

using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;

    Node(int Val):
        val(Val), next(nullptr), random(nullptr) {}
};


// 方法一：哈希表

Node* copyList(Node* head)
{
    if (head == nullptr)
        return nullptr;

    unordered_map<Node*, Node*> nodeMap;

    Node* result = new Node(*head);
    nodeMap.insert(make_pair(head, result)); //insert只能插入pair

    Node* copyHead = head;
    Node* copyResult = result;
    copyHead = copyHead->next;
    while (copyHead != nullptr)
    {
        copyResult->next = new Node(*copyHead);
        nodeMap.insert(make_pair(copyHead, copyResult->next));
        copyResult = copyResult->next;
        copyHead = copyHead->next;
    }

    copyHead = head;
    copyResult = result;

    while (copyHead != nullptr)
    {
        if (copyHead->random != nullptr)
            copyResult->random = nodeMap.find(copyHead->random)->second; // map的返回值为一个迭代器

        copyHead = copyHead->next;
        copyResult = copyResult->next;
    }


    return result;
}

// 方法二

void cloneNodes(Node* head)
{
    while (head != nullptr)
    {
        Node* clone = new Node(*head);
        clone->next = head->next;
        head->next = clone;
        head = clone->next;
    }
}

void connetNodes(Node* head)
{
    while (head != nullptr)
    {
        Node* connect = head->random;
        if (connect)
            head->next->random = connect->next;

        head = head->next->next;
    }
}

Node* splitNodes(Node* head)
{
    Node* result = head->next;
    Node* copyResult = result;
    head->next = result->next;
    head = head->next;

    while (head != nullptr)
    {
        copyResult->next = head->next;
        head->next = head->next->next;
        head = head->next;
        copyResult = copyResult->next;
    }

    return result;
}

Node* copyList2(Node* head)
{
    cloneNodes(head);
    connetNodes(head);
    return splitNodes(head);
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
    a->random = d;
    b->next = c;
    c->next = d;
    c->random = b;
    d->next = e;

    Node* t = copyList2(a);
    return 0;
}