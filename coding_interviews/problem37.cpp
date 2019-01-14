// 序列化和反序列化二叉树
#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};


// 序列化

void Serialize(Node* root, ostream& out)
{
    if (root == nullptr)
    {
        out << "$ ";
        return;
    }

    out << root->val << " ";
    Serialize(root->left, out);
    Serialize(root->right, out);
}

// 反序列化
void Unserialize(Node*& root, istream& in)
{
    string num;
    if (in >> num && num != "$")
    {
        root = new Node(atoi(num.c_str()));

        Unserialize(root->left, in);
        Unserialize(root->right, in);
    }
}


Node* Unserialize(istream& in)
{
    Node* root;
    Unserialize(root, in);
    return root;
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

    Serialize(a, cout);

    string str = "1 2 4 $ $ $ 3 5 $ $ 6 $ $";
    istringstream stream(str);
    Node* root = Unserialize(stream);

    return 0;
}