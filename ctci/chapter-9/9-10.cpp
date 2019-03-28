#include <vector>
#include <algorithm>
using namespace std;

struct Box
{
    int w;
    int h;
    int d;
    int max;

    Box(int W, int H, int D): w(W), h(H), d(H), max(0) {}

    bool canBeAbove(Box& that)
    {
        if (w < that.w && h < that.h && d < that.d)
            return true;
        else
            return false;
    }
};

// 递归法

int helper(vector<Box>& vec, Box box, int level)
{
    if (level == vec.size() - 1)
        return box.h;

    int height = box.h;
    int maxAbove = 0;
    for (auto& t: vec)
    {
        if (t.canBeAbove(box))
            maxAbove = max(helper(vec, t, level + 1), maxAbove);
    }

    return height + maxAbove;
}

int maxHeight(vector<Box>& vec)
{
    int maxHeight = -1;
    for (auto box: vec)
        maxHeight = max(helper(vec, box, 0), maxHeight);

    return maxHeight;
}

// 动态规划
int helper_dp(vector<Box>& vec, Box box, int level)
{
    if (box.max != 0)
        return box.max;

    if (level == vec.size() - 1)
        return box.h;

    int height = box.h;
    int maxAbove = 0;
    for (auto& t: vec)
    {
        if (t.canBeAbove(box))
            maxAbove = max(helper(vec, t, level + 1), maxAbove);
    }

    height += maxAbove;
    box.max = height;
    return height;
}

int maxHeight_dp(vector<Box>& vec)
{
    // 由于Box为自定义结构，hash函数无法映射，所以不能使用unordered_map 和map

    int maxHeight = -1;
    for (auto box: vec)
        maxHeight = max(helper_dp(vec, box, 0), maxHeight);

    return maxHeight;
}

int main(void)
{
    Box a{1,2,3}, b{2,3,4}, c{3,4,5};
    vector<Box> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    int height = maxHeight_dp(vec);
    return 0;
}
