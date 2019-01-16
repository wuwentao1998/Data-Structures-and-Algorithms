// 数据流中的中位数
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


class Heap
{
public:

    void insert(int num)
    {
        if ((max.size() + min.size()) % 2 == 0)
        {
            if (max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());

                num = max[0];

                pop_heap(max.begin(), max.end(), less<int>());
            }

            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else
        {
            if (min.size() > 0 && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<int>());
            }

            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    int getMedian()
    {
        int size = min.size() + max.size();
        if (size == 0)
            throw "no numbers are available";

        if (size % 2 == 0)
            return (min[0] + max[0]) /2;
        else
            return min[0];
    }

private:

    vector<int> min;
    vector<int> max;
}