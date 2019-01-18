// 前序，中序，后续遍历的非递归版本

#include <stack>
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};

void inOrder(Node* root)
{
    if (root == nullptr)
        return;

    stack<Node*> sk;

    while (!sk.empty() || root)
    {
        while (root)
        {
            sk.push(root);
            root = root->left;
        }

        if (!sk.empty())
        {
            root = sk.top();
            sk.pop();
            cout << root->val << endl;
            root = root->right;
        }
    }
}

void preOrder(Node* root)
{
    if (root == nullptr)
        return;

    stack<Node*> sk;

    while (!sk.empty() || root)
    {
        while(root)
        {
            cout << root->val << endl;
            sk.push(root);
            root = root->left;
        }

        if (!sk.empty())
        {
            root = sk.top();
            sk.pop();
            root = root->right;
        }
    }
}

void postOrder(Node* root)
{
    if (root == nullptr)
        return;

    stack<Node*> sk;
    Node* pre = nullptr;

    while (root)
    {
        sk.push(root);
        root = root->left;
    }

    while (!sk.empty())
    {
        root = sk.top();
        sk.pop();

        if (root->right == nullptr || root->right == pre)
        {
            cout << root->val << endl;
            pre = root;
        }
        else
        {
            sk.push(root);
            root = root->right;
            while (root)
            {
                sk.push(root);
                root = root->left;
            }
        }
    }
}
