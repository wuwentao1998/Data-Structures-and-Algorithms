// 包含min函数的栈
#include <stack>
using namespace std;

template <typename T>
class SK
{
public:
    void push(T val)
    {
        if (min.empty() || val < min.top())
            min.push(val);

        data.push(std::move(val));
    }

    void pop()
    {
        T val = data.top();
        data.pop();

        if (val == min.top())
            min.pop()
    }

    T min()
    {
        return min.top();
    }

private:

    stack<T> data;
    stack<T> min;

}