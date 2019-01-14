#include <assert.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int Val):
        val(Val), left(nullptr), right(nullptr) {}
};


bool isTraversal(int* result, int len)
{
    if (result == nullptr || len <= 0)
        return false;

    int root = result[len - 1];
    int begin = 0;
    for (int i = 0; i < len - 1; ++i)
    {
        if (result[i] > root)
        {
            begin = i;
            break;
        }
    }

    for (int j = begin; j < len - 1; ++j)
    {
        if (result[j] < root)
            return false;
    }

    int leftLen = begin;
    int rightLen = len - leftLen - 1;

    bool left = true, right = true;
    if (leftLen > 0)
        left = isTraversal(result, leftLen);

    if (rightLen > 0)
        right = isTraversal(result + begin, rightLen);

    return (left && right);
}


/* 测试代码 */


int main(int argc, char const *argv[])
{
    int a[] = {5,7,6,9,11,10,8};
    int b[] = {7,4,6,5};
    int c[] = {5,7,6};
    assert(isTraversal(a, 7));
    assert(isTraversal(b, 4) == false);
    assert(isTraversal(c, 3));
    return 0;
}


