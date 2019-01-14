// 二叉树的路径
#include <assert.h>
#include <vector>
#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};


void print(vector<int>& path)
{
    for(auto a: path)
        cout << a;

    cout <<endl;
}

void printPath(Node* root, int expectedSum, int curSum, vector<int>& path)
{
    bool isLeaf = root->left == nullptr && root->right == nullptr;
    curSum += root->val;
    path.push_back(root->val);

    if (curSum  == expectedSum && isLeaf)
    {
        print(path);
        path.pop_back();
        return;
    }

    if (root->left != nullptr)
        printPath(root->left, expectedSum, curSum, path);

    if (root->right != nullptr)
        printPath(root->right, expectedSum, curSum, path);

    path.pop_back();
}


void printPath(Node* root, int expectedSum)
{
    if (root == nullptr)
        return;

    vector<int> path;
    printPath(root, expectedSum, 0, path);
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

    printPath(a, 15);
    printPath(a, 25);
    printPath(a, 18);
    return 0;
}