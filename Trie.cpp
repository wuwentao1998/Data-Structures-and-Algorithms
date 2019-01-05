#include <assert.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define RANGE 256


#define DEBUG

template <typename Val>
class Trie
{
    struct Node
    {
        Val val;
        Node* next[RANGE] = {nullptr}; //不可以用 Node* next[]代替

    }; //声明结构体和类的时候结尾都要加分号

    Node* root;

public:
    Trie() : root(new Node()) {}
    void put(string key, Val val) { put(root, key, val, 0); }
    Val get(string key); //键不存在时返回默认值
    unique_ptr<vector<string>> keysWithPrefix(string prefix);
    unique_ptr<vector<string>> keys();
    bool find(string str);
    string longestPrefix(string str);
    bool del(string str);

  private:
    void put(Node* x, string key, Val val, size_t d);
    Node* get(Node* x, string key, size_t d);
    void keysWithPrefix(const unique_ptr<vector<string>> &ptr, Node *x, string prefix); //unique_ptr不能复制，所以只能通过引用传参。当然也可以通过std::move()使其变成右值
    void del(Node *&x, string str, int d);
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
unique_ptr<vector<string>> Trie<Val>::keysWithPrefix(string prefix)
{
    unique_ptr<vector<string>> ptr(new vector<string>);

    Node* begin = get(root, prefix, 0);
    if (begin != nullptr)
    {
        if (begin->val != Val())
            ptr->push_back(prefix);

        keysWithPrefix(ptr, begin, prefix);
    }

    return ptr;
}

template <typename Val>
unique_ptr<vector<string>> Trie<Val>::keys()
{
    return keysWithPrefix("");
}

template <typename Val>
bool Trie<Val>::find(string str)
{
    if (str.empty())
        return false;

    Node* t = root;
    for (size_t d = 0; d < str.length(); d++)
    {
        int c = str[d];
        if (t->next[c] == nullptr)
            return false;

        t = t->next[c];
    }

    return (t->val == Val()) ? false : true;
}

template <typename Val>
string Trie<Val>::longestPrefix(string str)
{
    if (str.empty())
        return "";

    Node* t = root;
    string prefix;
    string record;
    for (size_t d = 0; d < str.length(); d++)
    {
        int c = str[d];
        if (t->next[c] == nullptr)
            return prefix;

        record += (char)c;
        if (t->next[c]->val != Val())
            prefix = record;

        t = t->next[c];
    }

    return prefix;
}

template <typename Val>
bool Trie<Val>::del(string str)
{
    Node* end = get(root, str, 0);
    if (str == "" || end == nullptr || end->val == Val())
        return false;

    del(root, str, 0);
    return true;
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
    if (key == "")
        return root;

    int c = key[d];

    if (x->next[c] == nullptr)
        return nullptr;

    if (d == key.length() - 1)
            return x->next[c];
    else
        return get(x->next[c], key, d + 1);

}

template <typename Val>
void Trie<Val>::keysWithPrefix(const unique_ptr<vector<string>> &ptr, Node *x, string prefix)
{
    for (int i = 0; i < RANGE; i++)
    {
        if (x->next[i] == nullptr)
            continue;

        if (x->next[i]->val != Val())
            ptr->push_back(prefix + (char)i);

        keysWithPrefix(ptr, x->next[i], prefix + (char)i);
    }
}

template <typename Val>
void Trie<Val>::del(Node*& x, string str, int d)
{
    int c = str[d];
    if ((size_t)d == str.length() - 1)
        x->next[c]->val = Val();
    else
        del(x->next[c], str, d + 1);

    auto &y = x->next[c];
    for (int i = 0; i < RANGE; i++)
    {
        if (y->next[i] != Val())
            return;
    }
    y = nullptr;
}

/* 测试代码 */

#ifdef DEBUG

int main(int argc, char const *argv[])
{
    Trie<int> t;
    t.put("se", 1);
    t.put("sea", 2);
    t.put("shells", 3);
    t.put("she", 4);
    assert(t.get("se") == 1);
    assert(t.get("sea") == 2);
    assert(t.get("shells") == 3);
    assert(t.get("she") == 4);
    assert(t.get("sec") == int());
    assert(t.get("shell") == int());
    unique_ptr<vector<string>> v = t.keysWithPrefix("s");
    vector<string> vec = *v;
    assert(v->size() == 4);
    t.put("all", 5);
    auto all = t.keys();
    assert(all->size() == 5);
    assert(t.find("she") == true);
    assert(t.find("") == false);
    assert(t.find("shellss") == false);
    assert(t.longestPrefix("she") == "she");
    assert(t.longestPrefix("shell") == "she");
    assert(t.longestPrefix("shellsort") == "shells");
    assert(t.longestPrefix("sert") == "se");
    assert(t.longestPrefix("safe") == "");
    assert(t.longestPrefix("") == "");
    assert(t.longestPrefix("b") == "");

    assert(t.del("se") == true);
    assert(t.find("se") == false);
    assert(t.del("shes") == false);
    assert(t.del("sh") == false);
    assert(t.del("") == false);
    assert(t.find("she") == true);
    return 0;
}

#endif // DEBUG
