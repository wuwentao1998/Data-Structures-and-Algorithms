#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};

// 问题1：按层遍历二叉树
void levelPrint(Node* root)
{
    if (root == nullptr)
        return;

    queue<Node*> qu;
    qu.push(root);

    while(!qu.empty()){
        Node* cur = qu.front();
        qu.pop();
        cout << cur->val << " ";

        if (cur->left)
            qu.push(cur->left);

        if (cur->right)
            qu.push(cur->right);
    }

}

// 问题2：分行按层遍历二叉树

void levelPrint2(Node* root)
{
    if (root == nullptr)
        return;

    queue<Node*> qu;
    qu.push(root);
    int nextLevel = 0;
    int remains = 1;

    while(!qu.empty()){
        Node* cur = qu.front();
        qu.pop();
        cout << cur->val << " ";
        remains--;

        if (cur->left)
        {
            qu.push(cur->left);
            nextLevel++;
        }

        if (cur->right)
        {
            qu.push(cur->right);
            nextLevel++;
        }


        if (remains == 0)
        {
            cout << endl;
            remains = nextLevel;
            nextLevel = 0;
        }
    }
}

// 问题3：之字形分行按层遍历二叉树

void levelPrint3(Node* root)
{
    if (root == nullptr)
        return;

    stack<Node*> sk[2];
    sk[0].push(root);
    int current = 0;
    int next = 1;

    while(!sk[0].empty() || !sk[1].empty()){
        Node* cur = sk[current].top();
        sk[current].pop();
        cout << cur->val << " ";

        if (current == 0)
        {
            if (cur->left)
                sk[next].push(cur->left);

            if (cur->right)
                sk[next].push(cur->right);
        }
        else
        {
            if (cur->right)
                sk[next].push(cur->right);

            if (cur->left)
                sk[next].push(cur->left);
        }

        if (sk[current].empty())
        {
            cout << endl;
            next = 1 - next; // 不能写 next = current; current = next; 因为current在第一句就变了
            current = 1 - current;
        }
    }
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

    levelPrint3(a);
    return 0;
}