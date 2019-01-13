// 树的子结构
#include <assert.h>

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};


bool subTreeHelper(Node* father, Node* son)
{
    if (son == nullptr) // 这个判断必须要在下一个判断之前
        return true;

    if (father == nullptr)
        return false;

    if (father->val != son->val)
        return false;

    return subTreeHelper(father->left, son->left) && subTreeHelper(father->right, son->right);
}


bool subTree(Node* father, Node* son)
{
    if (father == nullptr)
        return false;

    if (son == nullptr)
        return true;

    bool result = false;

    if (father->val == son->val)
        result = subTreeHelper(father, son);

    if (!result)
        result = subTree(father->left, son) || subTree(father->right, son);

    return result;
}

/* 测试代码 */

int main(int argc, char const *argv[])
{
    Node* a = new Node(8);
    Node* b = new Node(7);
    Node* c = new Node(8);
    Node* d = new Node(9);
    Node* e = new Node(2);
    Node* f = new Node(4);
    Node* g = new Node(7);
    Node* h = new Node(8);
    Node* i = new Node(9);
    Node* j = new Node(2);

    a->right = b;
    a->left = c;
    c->left = d;
    c->right = e;
    e->left = f;
    e->right = g;
    h->left = i;
    h->right = j;

    assert(subTree(a, h));

    return 0;
}
