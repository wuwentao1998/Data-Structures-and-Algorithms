// 问题1：删除链表的节点

struct Node
{
    int val;
    Node* next;

    Node(int Val):
        val(Val), next(nullptr) {}
};

void deleteNode(Node*& head, Node* del) // 因为头节点也有可能被删除，所以应该使用引用
{
    if (head == nullptr || del == nullptr)
        return;

    if (head == del)
    {
        delete del;
        del = nullptr;
        head = nullptr;
    }

    if (del->next == nullptr)
    {
        Node* root = head;

        while(root->next != del)
            root = root->next;

        root->next = nullptr;
        delete del;
        del = nullptr;
    }

    Node* t = del->next;
    del->val = t->val;
    del->next = t->next;
    delete t;
    t = nullptr;
}


// 问题2：删除链表中重复的节点

void deleteDuplicate(Node*& head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node* prev = nullptr;
    Node* cur = head;

    while(cur != nullptr && cur->next != nullptr)
    {
        if (cur->val == cur->next->val)
        {
            Node* t = cur->next->next;
            int val = cur->val;
            delete cur->next;
            delete cur;

            while (t != nullptr && t->val == val)
            {
                Node* del = t;
                t = t->next;
                delete del;
            }

            if (prev == nullptr)
            {
                if (t == nullptr)
                {
                    head = nullptr;
                    return;
                }

                head = t;
                cur = head;
                continue;
            }

            if (t == nullptr)
            {
                prev->next = nullptr;
                return;
            }

            prev->next = t;
            cur = t;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

}


/* 测试代码 */

int main(int argc, char const *argv[])
{
    Node* a = new Node(4);
    Node* b = new Node(4);
    Node* c = new Node(4);
    Node* d = new Node(4);
    Node* e = new Node(4);
    Node* f = new Node(4);
    Node* g = new Node(4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;

    deleteDuplicate(a);

    return 0;
}



