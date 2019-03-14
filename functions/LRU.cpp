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
            page_list.splice(page_list.begin(), page_list, map[key]);
            map[key] = page_list.begin();
        }
        else if (_capacity == page_list.size())
        {
            map.erase(page_list.back().key);
            page_list.pop_back();
            page_list.emplace_front(key, val);
            map.insert({key, page_list.begin()});
        }
        else
        {
            page_list.emplace_front(key, val);
            map.insert({key, page_list.begin()});
        }
    }


private:
    list<Node> page_list;
    unordered_map<int, list<Node>::iterator> map;
    int _capacity;
};