// 二叉树的后继节点

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

Node* leftNode(Node* root)
{
    while (root->left != nullptr)
        root = root->left;

    return root;
}

Node* nextNode(Node* curNode)
{
    if (curNode == nullptr)
        return nullptr;

    if (curNode->right != nullptr)
        return leftNode(curNode->right);

    if (curNode->parent == nullptr)
        return nullptr;

    Node* parent = curNode->parent;
    if (curNode == parent->left)
        return parent;

    do
    {
        curNode = parent;
        parent = curNode->parent;
    } while (parent != nullptr && curNode == parent->left);

    if (parent == nullptr)
        return nullptr;

    return parent;
}






