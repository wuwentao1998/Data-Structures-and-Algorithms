// 二叉搜索树的第k大节点

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};

Node* maxKhelper(Node* root, int k)
{
    Node* result = nullptr;
    if (root->left != nullptr)
        result = maxKhelper(root->left, k);

    if (result == nullptr)
    {
        if (k == 1)
            result = root;
        else
            k--;
    }

    if (result == nullptr && root->right != nullptr)
        result = maxKhelper(root->right, k);

    return result;
}

Node* maxK(Node* root, int k)
{
    if (root == nullptr)
        return nullptr;

    return maxKhelper(root, k);
}