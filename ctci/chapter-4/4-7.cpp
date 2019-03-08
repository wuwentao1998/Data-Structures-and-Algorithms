struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):val(Val), left(nullptr), right(nullptr) {}
};

bool cover(Node* root, Node* p)
{
    if (root == nullptr)
        return false;

    if (root == p)
        return true;

    return cover(root->left, p) || cover(root->right, p);
}

Node* helper_v1(Node* root, Node* a, Node* b)
{
    if (root == nullptr || a == root || b == root)
        return root;

    bool is_a_left = cover(root->left, a);
    bool is_b_left = cover(root->left, b);

    if (is_a_left != is_b_left)
        return root;

    Node* side = is_a_left ? root->left : root->right;

    return helper_v1(side, a, b);
}

Node* common_v1(Node* root, Node* a, Node* b)
{
    if (root == nullptr || a == nullptr || b == nullptr || !cover(root, a) || !cover(root, b))
        return nullptr;

    return helper_v1(root, a, b);
}

Node* helper_v2(Node* root, Node* a, Node* b) // 待验证
{
    if (root == nullptr)
        return root;

    auto x = helper_v2(root->left, a, b);
    if (x != nullptr && x != a && x != b)
        return x;

    auto y = helper_v2(root->right, a, b);
    if (y != nullptr && y != a && y != b)
        return y;

    if (x == nullptr && y == nullptr)
        return nullptr;

    if ((x == a && y == b) | (x == b && y == a))
        return root;

    if (root == a || root == b)
        return root;

    return x == nullptr ? y : x;
}

Node* common_v2(Node* root, Node* a, Node* b)
{
    if (root == nullptr || a == nullptr || b == nullptr || !cover(root, a) || !cover(root, b))
        return nullptr;

    return helper_v2(root, a, b);
}

