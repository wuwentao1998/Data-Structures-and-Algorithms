// 礼物的最大值
#include <algorithm>

int maxValue(int** matrix, int row, int col)
{
    if (matrix == nullptr || row <= 0 || col <= 0)
        return 0;

    int** values = new int*[row];
    for (int i = 0; i < row; ++i)
        values[i] = new int[col];

    values[0][0] = matrix[0][0];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int left = 0, up = 0;
            if (i > 0)
                up = values[i - 1][j];

            if (j > 0)
                left = values[i][j - 1];

            values[i][j] = std::max(up, left) + matrix[i][j];
        }
    }

    int result = values[row - 1][col - 1];

    for(int i = 0; i < col; i++)
        delete[] values[i];

    delete values;

    return result;
}
