#include <iostream>
#include <assert.h>
using namespace std;

void printMatrix(int** matrix, int row, int col, int start)
{
    if (row <= 0 || col <= 0)
        return;

    if (row == 1 && col == 1)
    {
        cout << matrix[0][start] << " ";
        return;
    }

    for (int j = 0; j < col; ++j)
        cout << matrix[0][j + start] << " ";

    for (int i = 1; i < row - 1; ++i)
        cout << matrix[i][col + start - 1] << " ";

    if (row > 1)
    {
        for (int j = col - 1; j >= 0; --j)
            cout << matrix[row - 1][j + start] << " ";
    }

    if (col > 1)
    {
        for (int i = row - 2; i >=1 ; --i)
            cout << matrix[i][start] << " ";
    }

    printMatrix(matrix + 1, row - 2, col - 2, start + 1);
}




/* 测试代码 */

int main(int argc, char const *argv[])
{
    int** matrix = new int*[4];
    for (int i = 0; i < 4; i++)
        matrix[i] = new int[4];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = 4 * i + j + 1;

    printMatrix(matrix, 4, 4, 0);

    return 0;
}