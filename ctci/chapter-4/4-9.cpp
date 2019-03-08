#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):val(Val), left(nullptr), right(nullptr) {}
};

int depth(Node* root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    int left = depth(root->left);
    int right = depth(root->right);

    return 1 + max(left, right);
}

void print(int* path, int low, int high)
{
    for (int i = low; i <= high; i++)
        cout << path[i];

    cout << endl;
}

void printHelper(Node* root, int val, int* path, int level)
{
    if (root == nullptr)
        return;

    path[level] = root->val;
    int sum = 0;
    for (int i = level; i >= 0; i--)
    {
        sum += path[i];
        if (sum == val)
            print(path, i, level);
    }

    if (root->left != nullptr)
        printHelper(root->left, val, path, level + 1);

    if (root->right != nullptr)
        printHelper(root->right, val, path, level + 1);
}

void printPath(Node* root, int val)
{
    if (root == nullptr)
        return;

    int n = depth(root);
    int* path = new int[n];
    printHelper(root, val, path, 0);
    delete[] path;
}