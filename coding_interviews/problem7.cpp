// 重建二叉树

struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* construct(int* preorder, int* inorder, int len)
{
    if (preorder == nullptr || inorder == nullptr || len <= 0)
        return nullptr;

    Node* root = new Node;
    int t = preorder[0];
    root->val = t;

    int pos = 0;
    for (int i = 0; i < len; ++i)
    {
        if (t == inorder[i])
        {
            pos = i;
            break;
        }
    }

    int leftLen = pos;
    if (pos > 0)
        root->left = construct(preorder + 1, inorder, leftLen);
    else
        root->left = nullptr;

    int rightLen = len - 1 - pos;
    if (pos < len - 1)
        root->right = construct(preorder + pos + 1, inorder + pos + 1, rightLen);
    else
        root->right = nullptr;

    return root;

}


/* 测试代码 */

int main(int argc, char const *argv[])
{
    int preorder1[] = {1,2,4,7,3,5,6,8};
    int inorder1[] = {4,7,2,1,5,3,8,6};
    Node* a = construct(preorder1, inorder1, 8);

    int preorder2[] = {1,2,4,7,3,5,6,8,9};
    int inorder2[] = {4,7,2,1,5,3,8,6};
    Node* b = construct(preorder2, inorder2, 8);

    int preorder3[] = {1,2,4,7,3,9,6,8};
    int inorder3[] = {4,7,2,1,5,3,8,6};
    Node* c = construct(preorder3, inorder3, 8);
    return 0;
}



