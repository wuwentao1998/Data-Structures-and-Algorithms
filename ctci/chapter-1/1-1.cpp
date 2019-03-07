// 使用位操作代替hash数组节约空间

#include <string>
using namespace std;

bool isUnique(string str)
{
    if (str.size() > 26)
        return false;

    int flag = 0;
    for (auto c : str)
    {
        int offset = c - 'a';
        if ((flag & (1 << offset)) > 0)
            return false;
        else
            flag |= (1 << offset);
    }

    return true;
}

