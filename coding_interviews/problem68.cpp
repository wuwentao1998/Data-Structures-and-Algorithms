// 树中两个节点的最低公共祖先
#include <algorithm>
#include <assert.h>
#include <stack>
#include <vecotr>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* parent;

    vector<Node*> chilren;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr), parent(nullptr) {}
};

// 条件一：二叉搜索树

Node* findAncestor_1(Node* root, Node* a, Node* b)
{
    if (root == nullptr || a == nullptr || b == nullptr)
        return nullptr;

    if (a == b)
        return a;

    if (a->val > b->val)
        swap(a, b);

    while (root)
    {
        int rootVal = root->val;
        int aVal = a->val;
        int bVal = b->val;

        if (rootVal > aVal && rootVal < bVal)
            return root;
        else if (rootVal < aVal)
            root = root->right;
        else
            root = root->left;
    }

    return nullptr;
}

// 条件二：含有指向父节点指针的普通树

Node* findAncestor_2(Node* root, Node* a, Node* b)
{
    if (root == nullptr || a == nullptr || b == nullptr)
        return nullptr;

    int lenA = 0;
    int lenB = 0;
    Node* aTemp = a;
    Node* bTemp = b;

    while (aTemp->parent != root)
    {
        lenA++;
        aTemp = aTemp->parent;
    }

    while (bTemp->parent != root)
    {
        lenB++;
        bTemp = bTemp->parent;
    }

    int diff= lenA - lenB;

    if (diff > 0)
    {
        while (diff > 0)
        {
            a = a->parent;
            diff--;
        }
    }
    else
    {
        while (diff < 0)
        {
            b = b->parent;
            diff++;
        }
    }

    while (a != b)
    {
        a = a->parent;
        b = b->parent;
    }

    return a;
}

// 条件三：不含后指向父节点指针的普通树

//解法一： 递归

bool findChildren(Node* root, Node* a, Node* b, Node*& ancestor)
{
    if (root == nullptr)
        return false;

    if (root == a || root == b)
        return true;

    bool left = findChildren(root->left, a, b, ancestor);
    bool right = findChildren(root->right, a, b, ancestor);
    if (left && right)
        ancestor = root;

    if (left || right)
        return true;
    else
        return false;
}

Node* findAncestor_3(Node* root, Node* a, Node* b)
{
    if (root == nullptr || a == nullptr || b == nullptr)
        return nullptr;

    Node* result;
    findChildren(root, a, b, result);

    return result;
}

// 解法二：使用栈，转换为两个链表的最后公共节点

bool getPath(Node* root, Node* dest, stack<int>& path)
{
    if (root == dest)
        return true;

    bool found = false;

    auto ptr = root->chilren.begin();
    while (!found && ptr != root->chilren.end())
    {
        found = getPath(*ptr, dest, path);
        ++i;
    }

    if (!found)
        path.pop_back();

    return found;
}

Node* findAncestor_4(Node* root, Node* a, Node* b)
{
    if (root == nullptr || a == nullptr || b == nullptr)
        return nullptr;

    stack<int> pathA;
    getPath(root, a, pathA);

    stack<int> pathB;
    getPath(root, b, pathB);

    auto itA = pathA.begin();
    auto itB = pathB.begin();


    while (itA != pathA.end() && itB != pathB.end())
    {
        if (*itA == *itB)
            return *itA;

        itA++;
        itB++;
    }

    return nullptr;
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

    Node* t = findAncestor_3(a, d, g);
    Node* p = findAncestor_3(a, f, b);

    assert(t == c);
    assert(p == a);
    return 0;
}

