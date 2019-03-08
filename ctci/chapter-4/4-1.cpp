#include <algorithm>
using std::max;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):val(Val), left(nullptr), right(nullptr) {}
};

int helper(Node* root)
{
    if (root == nullptr)
        return 0;

    int left = helper(root->left);
    if (left == -1)
        return -1;

    int right = helper(root->right);
    if (right == -1)
        return -1;

    int diff = right > left ? right - left : left - right;

    if (diff > 1)
        return -1;
    else
        return 1 + max(left, right);
}

bool isBalance(Node* root)
{
    if (root == nullptr)
        return true;

    return helper(root) != -1;
}


