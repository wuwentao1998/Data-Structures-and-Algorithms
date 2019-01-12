// 求链表的倒数第K个节点

struct Node
{
    int val;
    Node* next;
};

Node* lastKnode(Node* root, int k)
{
    if (root == nullptr or k <= 0)
        return nullptr;

    Node *front = root;
    Node *back;

    for(int i = 0; i < k - 1; i++)
    {
        if (front ->next != nullptr)
            front = front->next;
        else
            return nullptr;
    }

    back = front;

    while (front->next != nullptr)
    {
        front = front->next;
        back = back->next;
    }

    return back;
}



/* 测试代码 */

int main(int argc, char const *argv[])
{

    return 0;
}