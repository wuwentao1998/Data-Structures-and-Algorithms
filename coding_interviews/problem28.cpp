// 树的子结构
#include <assert.h>
#include <stack>

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};


bool symmetrical(Node* a, Node* b)
{
    if (a == nullptr && b == nullptr)
        return true;

    if (a == nullptr || b == nullptr)
        return false;

    if (a->left->val != b->right->val)
        return false;

    return symmetrical(a->left, b->right) && symmetrical(a->right, b->left);
}


bool symmetrical(Node* root)
{
    return symmetrical(root, root);
}


