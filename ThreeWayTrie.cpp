#include <assert.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

//#define DEBUG

template <typename Val>
class ThreeWayTrie
{
    struct Node
    {
        char c;
        Val val;
        Node *left;
        Node *mid;
        Node *right;
    };

    Node *root;

public:
    ThreeWayTrie() : root(nullptr) {}
    void put(string key, Val value);
    Val get(string key);
    unique_ptr<vector<string>> keysWithPrefix(string prefix);
    unique_ptr<vector<string>> keys() { return keysWithPrefix(""); }
    string longestPrefix(string str);
    bool del(string str);

  private:
    void put(Node *&x, string key, Val value, size_t d);
    Node *get(Node *x, string key, size_t d);
    void keysWithPrefix(const unique_ptr<vector<string>> &ptr, string prefix, Node* x);
    void del(Node *&x, string str, size_t d);
};

/*公有成员函数的实现*/
template <typename Val>
inline void ThreeWayTrie<Val>::put(string key, Val value)
{
    if (key == "")
        return;

    put(root, key, value, 0);
}

template <typename Val>
inline Val ThreeWayTrie<Val>::get(string key)
{
    if (key == "")
        return Val();

    Node* n = get(root, key, 0);
    return (n == nullptr) ? Val() : n->val;
}

template <typename Val>
unique_ptr<vector<string>> ThreeWayTrie<Val>::keysWithPrefix(string prefix)
{
    unique_ptr<vector<string>> ptr(new vector<string>);

    if (prefix == "")
        keysWithPrefix(ptr, prefix, root);
    else
    {
        Node *t = get(root, prefix, 0);
        if (t != nullptr)
            keysWithPrefix(ptr, prefix, t->mid);
    }

    return ptr;
}

template <typename Val>
string ThreeWayTrie<Val>::longestPrefix(string str)
{
    Node *t = root;
    string result, temp;
    int d = 0;
    while(t != nullptr)
    {
        char c = str[d];
        if (t->c == c)
        {
            temp += c;
            if (t->val != Val())
                result = temp;
        }


        if (c < t->c)
            t = t->left;
        else if (c > t->c)
            t = t->right;
        else
        {
            d++;
            t = t->mid;
        }
    }

    return result;
}

template <typename Val>
bool ThreeWayTrie<Val>::del(string str)
{
    Node *end = get(root, str, 0);
    if (str == "" || end == nullptr || end->val == Val())
        return false;

    del(root, str, 0);
    return true;
}

/*私有成员函数的实现*/
template <typename Val>
void ThreeWayTrie<Val>::put(Node *&x, string key, Val value, size_t d)
{
    char c = key[d];

    if (x == nullptr)
    {
        x = new Node();
        x->c = c;
    }

    if (d == key.length() - 1)
    {
        x->val = value;
        return;
    }

    if (c < x->c)
        put(x->left, key, value, d);
    else if (c > x->c)
        put(x->right, key, value, d);
    else
        put(x->mid, key, value, d + 1);
}

template <typename Val>
typename ThreeWayTrie<Val>::Node* ThreeWayTrie<Val>::get(Node *x, string key, size_t d)
{
    if (x == nullptr)
        return nullptr;

    char c = key[d];
    if (d == key.length() - 1)
    {
        if (x->c == c)
            return x;
        else
            return nullptr;
    }

    if (c < x->c)
        return get(x->left, key, d);
    else if (c > x->c)
        return get(x->right, key, d);
    else
        return get(x->mid, key, d + 1);
}

template <typename Val>
void ThreeWayTrie<Val>::keysWithPrefix(const unique_ptr<vector<string>> &ptr, string prefix, Node *x)
{
    string s = prefix + x->c;

    if (x->val != Val())
        ptr->push_back(s);

    if (x->left != nullptr)
     keysWithPrefix(ptr, prefix, x->left);

    if (x->mid != nullptr)
    keysWithPrefix(ptr, s, x->mid);

    if (x->right != nullptr)
    keysWithPrefix(ptr, prefix, x->right);
}

template <typename Val>
void ThreeWayTrie<Val>::del(Node *&x, string str, size_t d)
{
    if (x == nullptr)
        return;

    if (d == str.length() - 1)
        x->val = Val();

    char c = str[d];
    if (c < x->c)
        del(x->left, str, d);
    else if (c > x->c)
        del(x->right, str, d);
    else
        del(x->mid, str, d + 1);

    if (x->val == Val() && x->mid == nullptr && x->left == nullptr && x->right == nullptr)
        x = nullptr;
}

/* 测试代码 */

#ifdef DEBUG

    int main(int argc, char const *argv[])
{
    ThreeWayTrie<int> t;
    t.put("she", 1);
    t.put("are", 2);
    t.put("by", 3);
    t.put("shells", 4);
    t.put("sea", 5);
    assert(t.get("are") == 2);
    assert(t.get("shells") == 4);
    assert(t.get("") == int());
    assert(t.get("sh") == int());
    assert(t.get("sear") == int());
    assert(t.get("cd") == int());
    auto v1 = *t.keysWithPrefix("");
    assert(v1.size() == 5);
    auto v2 = *t.keysWithPrefix("s");
    assert(v2.size() == 3);
    auto v3 = *t.keys();
    assert(v3.size() == 5);
    assert(t.longestPrefix("shear") == "she");
    string temp = t.longestPrefix("arary");
    assert(t.longestPrefix("arary") == "");
    assert(t.longestPrefix("are") == "are");
    assert(t.del("") == false);
    assert(t.del("sh") == false);
    assert(t.del("shear") == false);
    assert(t.del("shells") == true);

    return 0;
}

#endif // DEBUG
