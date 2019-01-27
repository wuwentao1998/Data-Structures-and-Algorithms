#include <vector>
#include <exception>
#include <deque>
using namespace std;

// 问题1：滑动窗口的最大值

vector<int> maxInWindows(const vector<int> vec, int size)
{
    vector<int> result;
    deque<int> window;
    int capacity = vec.size();
    if (capacity < size || size < 1)
        return result;

    for (int i = 0; i< size; i++)
    {
        while(!window.empty() && vec[i] > vec[window.back()])
            window.pop_back();

        window.push_back(i);
    }

    for (int i = size; i < capacity; i++)
    {
        result.push_back(vec[window.front()]);

        while(!window.empty() && vec[i] > vec[window.back()])
            window.pop_back();

        if (!window.empty() && window.front() <= (int)(i - size))
            window.pop_front();

        window.push_back(i);
    }

    result.push_back(vec[window.front()]);

    return result;
}



// 问题2：队列的最大值

template <typename T>
class QueueWithMax
{
pulic:

    QueueWithMax(): curIndex(0) {}

    void push_back(const T& val)
    {
        while (!max.empty() && val >= max.back().val)
            max.pop_back();

        Data newData = {T, curIndex++};
        data.push_back(newData);
        max.push_back(newData);
    }

    void pop_front()
    {
        if (data.emtpy() || max.empty())
            throw exception("queue is empty");

        if (max.front().index == data.front().index)
            max.pop_front();

        data.pop_front();
    }

    const T& max() const
    {
        if (data.emtpy() || max.empty())
            throw exception("queue is empty");

        return max.front().val;
    }

private:
    struct Data
    {
        T val;
        int index;
    };

    deque<Data> data;
    deque<Data> max;
    int curIndex;
}