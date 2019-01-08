// 二维数组的查找
//主要思路：从右上角开始查询，如果偏大则剔除列，如果偏小则剔除行
#include <assert.h>

bool find(int** matrix, int row, int col, int num)
{
    if (row <= 0 || col <= 0 || matrix == nullptr)
        return false;

    for (int i = 0; i < row; ++i)
    {
        if (matrix[i] == nullptr)
            return false;
    }

    if (row == 1 && col == 1)
        return num == matrix[0][0];

    int i = 0, j = col;
    while (i <= row && j >= 0)
    {
        int t = matrix[i][j];
        if (t == num)
            return true;
        else if (t < num)
            ++i;
        else
            --j;
    }
    return false;
}



