#include <cstring>

void clearMatrix(int** matrix, int row, int col)
{
    if (matrix == nullptr || row <= 0 || col <= 0)
        return;

    bool* cols = new bool[col];
    bool* rows = new bool[row];
    memset(cols, 0, sizeof(bool) * col);
    memset(rows, 0, sizeof(bool) * row);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; i < row; j++)
        {
            if (matrix[i][j] == 0)
            {
                cols[i] = true;
                rows[j] = true;
            }
        }
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (cols[i] == 0 || rows[j] == 0)
                matrix[i][j] == 0;
        }
    }

}