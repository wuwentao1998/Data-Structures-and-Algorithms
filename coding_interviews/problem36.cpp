// 二叉搜索树转双向链表

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};

Node* convert(Node* root)
{
    if (root == nullptr)
        return nullptr;

    if (root->left == nullptr && root->right == nullptr)
        return root;

    Node* leftNode = convert(root->left);
    Node* rightNode = convert(root->right);
    Node* result = leftNode;

    while (leftNode->right)
        leftNode = leftNode->right;

    leftNode->right = root;
    root->left = leftNode;

    rightNode->left = root;
    root->right = rightNode;

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

    a->right = b;
    a->left = c;
    c->left = d;
    c->right = e;
    e->left = f;
    e->right = g;

    Node* t = convert(a);
    return 0;
}