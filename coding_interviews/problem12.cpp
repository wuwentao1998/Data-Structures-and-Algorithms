// 矩阵中的路径

// 一般在二维矩阵上找路径的题目都可以用回溯法解决
#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;

bool pathHelper(const char* matrix, int row, int col, int i, int j, const char* str, bool* isVisited, int step);

bool hasPath(const char* matrix, int row, int col, const char* str)
{
    if (matrix == nullptr || row <= 0 || col <= 0 || str == nullptr || strlen(str) == 0)
        return false;

    size_t len = strlen(str);
    bool* isVisited = new bool[row * col];
    memset(isVisited, 0, row * col); // 显示填充为false;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (pathHelper(matrix, row, col, i, j, str, isVisited, len))
            {
                delete[] isVisited;
                return true;
            }
            // else
            //     memset(isVisited, 0, row * col);
        }
    }

    delete[] isVisited;
    return false;
}


bool pathHelper(const char* matrix, int row, int col, int i, int j, const char* str, bool* isVisited, int step)
{
    if (step == 0)
        return true;

    if (i < 0 || i >= row || j < 0 || j >= col || isVisited[i * col + j] || matrix[i * col + j] != *str)
        return false;

    isVisited[i * col + j] = true;

    // 因为如果不是路径时需要把访问记号改回false，所以不能直接返回，
    bool result = pathHelper(matrix, row, col, i + 1, j, str + 1, isVisited, step - 1)
    | pathHelper(matrix, row, col, i - 1, j, str + 1, isVisited, step - 1)
    | pathHelper(matrix, row, col, i, j + 1, str + 1, isVisited, step - 1)
    | pathHelper(matrix, row, col, i, j - 1, str + 1, isVisited, step - 1);

    if (!result)
        isVisited[i * col + j] = false;

    return result;
}

/*  测试代码 */

int main(int argc, char const *argv[])
{
    char matrix[] = {'a','b','t','g','c','f','c','s','j','d','e','h'};
    char wrong[] = {'a','a','a','a','a','a','a','a','a'};
    assert(hasPath(matrix, 3, 4, "bfce") == true);
    assert(hasPath(matrix, 3, 4, "abfb") == false);
    assert(hasPath(matrix, 3, 4, "") == false);
    assert(hasPath(wrong, 3, 3, "aaaaaaaaa") == true);
    assert(hasPath(wrong, 3, 3, "aaaaaaaaaa") == false);

    return 0;
}



