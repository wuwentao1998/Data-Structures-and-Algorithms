#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

#define RANGE 256

template <typename Val>
class Trie
{

    struct Node
    {
        Val val;
        Node* next[RANGE] = {nullptr}; //不可以用 Node* next[]代替

    }; //声明结构体和类的时候结尾都要加分号

    Node* root;
    size_t num;

public:
    Trie() : root(new Node()), num(0) {}
    void put(string key, Val val) { put(root, key, val, 0); }
    Val get(string key); //键不存在时返回默认值
    size_t size() { return num; }
    unique_ptr<vector<string>> valsWithPrefix(string prefix);

private:
    void put(Node* x, string key, Val val, size_t d);
    Node* get(Node* x, string key, size_t d);
    void valsWithPrefix(unique_ptr<vector<string>> ptr, Node *x, string prefix, size_t d);
};


/*公有成员函数的实现*/

template <typename Val>
Val Trie<Val>::get(string key)
{
    Node* node = get(root, key, 0);
    if (node == nullptr)
        return Val();
    else
        return node->val;
}


template <typename Val>
unique_ptr<vector<string>> Trie<Val>::valsWithPrefix(string prefix)
{
    unique_ptr<vector<string>> ptr(new vector<string>);
    valsWithPrefix(ptr, root, prefix, 0);
    return ptr;
}



/*私有成员函数的实现*/

template <typename Val>
void Trie<Val>::put(Node *x, string key, Val val, size_t d)
{
    int c = key[d];
    if (x->next[c] == nullptr)
        x->next[c] = new Node();

    if (d == key.length() - 1)
        x->next[c]->val = val;
    else
        put(x->next[c], key, val, d + 1);
}

template <typename Val>
typename Trie<Val>::Node* Trie<Val>::get(Node* x, string key, size_t d)
{
    int c = key[d];

    if (x->next[c] == nullptr)
        return nullptr;

    if (d == key.length() - 1)
        return x->next[c];
    else
        return get(x->next[c], key, d + 1);

}

template <typename Val>
void Trie<Val>::valsWithPrefix(unique_ptr<vector<string>> ptr, Node *x, string prefix, size_t d)
{

}