#include <list>
#include <unordered_map>
using namespace std;

struct Node
{
    int key;
    int val;
};

class LRU
{
    LRU(int capacity):_capacity(capacity){}

    int get(int key)
    {
        if (map.find(key) == map.end())
            return -1;

        page_list.splice(page_list.begin(), page_list, map[key]);
        map[key] = page_list.begin();
        return page_list.begin()->val;
    }

    void put(int key, int val)
    {
        if (map.find(key) != map.end())
        {
            map[key]->val = val;
            list.splice(list.begin(), list, map[key]);
            map[key] = list.begin();
        }
        else if (_capacity == list.size())
        {
            map.erase(list.back().key);
            list.pop_back();
            list.emplace_front(key, val);
            map.insert({key, list.begin()});
        }
        else
        {
            list.emplace_front(key, val);
            map.insert({key, list.begin()});
        }
    }


private:
    list<Node> page_list;
    unordered_map<int, list<Node>::iterator> map;
    int _capacity;
};