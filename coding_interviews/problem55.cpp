#include <stack>
#include <assert.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};


// 问题1： 二叉树的深度

int depth(Node* root)
{
    if (root == nullptr)
        return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    return 1 + (left > right) ? left : right;
}


// 问题2：平衡二叉树


// 解法一
bool balance(Node* root)
{
    if (root == nullptr)
        return true;

    int left = depth(root->left);
    int right = depth(root->right);
    int diff = left - right;

    if (diff > 1 || diff < -1)
        return false;
    else
        return balance(root->left) && balance(root->right);
}

// 解法二

bool balance_v2(Node* root, int& depth)
{
    if (root == nullptr)
    {
        depth = 0;
        return true;
    }

    int left, right;
    if (balance_v2(root->left, left) && balance_v2(root->right, right))
    {
        int diff = left - right;
        if (diff <= 1 && diff >= -1)
        {
            depth = 1 + (left > right ? left : right);
            return true;
        }
    }

    return false;
}

bool balance_v2(Node* root)
{
    if (root == nullptr)
        return true;

    int depth = 0;
    return balance_v2(root, depth);
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

    a->right = b;
    a->left = c;
    c->left = d;
    c->right = e;
    e->left = f;
    e->right = g;

    assert(balance_v2(c));
    assert(balance_v2(e));
    assert(balance_v2(b));
    assert(!balance_v2(a));

    return 0;
}
