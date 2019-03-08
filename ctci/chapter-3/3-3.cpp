#include <stack>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;
const int MAX = 3;

class SetOfStack
{
public:

    SetOfStack(): remaining(MAX)
    {
        shared_ptr<stack<int>> p(new stack<int>);
        vec.push_back(p);
    }

    void push(int val)
    {
        if (remaining == 0)
        {
            shared_ptr<stack<int>> p(new stack<int>);
            p->push(val);
            vec.push_back(p);
            remaining = MAX - 1;
        }
        else
        {
            auto p = vec.back();
            p->push(val);
            remaining--;
        }
    }

    void pop()
    {
        if (vec.empty())
        {
            cout << "stack is empty";
            return;
        }

        auto p = vec.back();
        p->pop();
        if (p->empty())
            vec.pop_back();
    }

private:
    vector<shared_ptr<stack<int>>> vec;
    int remaining;
};


int main(void)
{
    SetOfStack t;
    t.push(1);
    t.push(2);
    t.push(3);
    t.push(4);
    t.push(5);
    t.push(6);
    t.push(7);
    t.pop();
    t.pop();
    t.pop();
    t.pop();
    t.pop();
    t.pop();
    t.push(9);
}