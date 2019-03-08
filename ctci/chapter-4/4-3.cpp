#include <vector>
#include <iostream>
using std::cout;
using std::vector;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):val(Val), left(nullptr), right(nullptr) {}
};

Node* helper(vector<int>& vec, int low, int high)
{
    if (low == high)
        return new Node(vec[low]);

    int mid = (low + high) / 2;
    Node* root = new Node(vec[mid]);
    if (mid > low)
        root->left = helper(vec, low, mid - 1);

    if (mid < high)
        root->right = helper(vec, mid + 1, high);

    return root;
}

Node* createBST(vector<int>& vec)
{
    int size = vec.size();
    if (size == 0)
        return nullptr;

    return helper(vec, 0, size - 1);
}
