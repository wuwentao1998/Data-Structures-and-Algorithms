// 二叉树中节点的最距离
#include <algorithm>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
};

struct Result
{
    int maxDistance;
    int maxDepth;
};

Result findMaxLenHelper(Node* root)
{
    if (root == nullptr)
    {
        Result empty = {0, -1};
        return empty;
    }

    auto leftResult = findMaxLenHelper(root->left);
    auto rightResult = findMaxLenHelper(root->right);

    Result result;
    result.maxDepth = max(leftResult.maxDepth + 1, rightResult.maxDepth + 1);
    result.maxDistance = max(max(leftResult.maxDistance, rightResult.maxDistance), rightResult.maxDepth + rightResult.maxDepth + 2);

    return result;
}


int  findMaxLen(Node* root)
{
    if (root == nullptr)
        return 0;

    auto result = findMaxLenHelper(root);

    return result.maxDistance;
}