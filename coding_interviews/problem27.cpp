// 二叉树的镜像

#include <assert.h>
#include <stack>
using namespace std;
struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};


Node* mirror_r(Node* root)
{
    if (root == nullptr)
        return nullptr;

    if (root->right == nullptr && root->left == nullptr)
        return root;

    Node* left = root->left;
    root->left = mirror_r(root->right);
    root->right = mirror_r(left);

    return root;
}


Node* mirror(Node* root)
{
    if (root == nullptr)
        return nullptr;

    if (root->right == nullptr && root->left == nullptr)
        return root;

    stack<Node*> sk;
    sk.push(root);
    while(!sk.empty())
    {
        Node* cur = sk.top();
        sk.pop();
        if (cur->left != nullptr)
            sk.push(cur->left);

        if (cur->right != nullptr)
            sk.push(cur->right);

        Node* t = cur->left;
        cur->left = cur->right;
        cur->right = t;
    }

    return root;
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

    Node* x = mirror(h);
    Node* y = mirror(a);

    return 0;
}