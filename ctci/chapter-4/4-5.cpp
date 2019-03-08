#include<iostream>
#include<climits>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):val(Val), left(nullptr), right(nullptr) {}
};

bool helper_v1(Node* root, int& lastVal)
{
    if (root == nullptr)
        return true;

    if (!helper_v1(root->left, lastVal))
        return false;

    if (root->val <= lastVal)
        return false;
    else
        lastVal = root->val;

    if (!helper_v1(root->right, lastVal))
        return false;

    return true;
}

bool isBST_v1(Node* root)
{
    if (root == nullptr)
        return true;

    int lastVal = INT_MIN;
    return helper_v1(root, lastVal);
}

bool helper_v2(Node* root, int low, int high)
{
    if (root == nullptr)
        return true;

    if (root->val < low || root->val > high)
        return false;

    return helper_v2(root->left, low, root->val) && helper_v2(root->right, root->val + 1, high);
}

bool isBST_v2(Node* root)
{
    if (root == nullptr)
        return true;

    return helper_v2(root, INT_MIN, INT_MAX);
}

void createMinimalBst(Node* &root, int arr[], int start, int end){
    if(start > end)
        return;

    if(root==nullptr)
    {
        int ind = start + (end-start)/2;
        root = new Node(arr[ind]);
        createMinimalBst(root->left, arr, start, ind - 1);
        createMinimalBst(root->right, arr, ind + 1, end);
    }
}


int main(void)
{
    Node* root = nullptr;
    int arr1[] = {1, 2, 1, 4, 5, 6, 7, 8, 9};    //Not a BST
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};    //is BST
    createMinimalBst(root, arr1, 0, 8);
    cout<<isBST_v1(root) <<endl;
    cout<<isBST_v2(root) <<endl;
    root = nullptr;
    createMinimalBst(root, arr2, 0, 8);
    cout<<isBST_v1(root) <<endl;
    cout<<isBST_v2(root) <<endl;
}