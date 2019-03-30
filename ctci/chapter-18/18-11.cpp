#include <vector>
using namespace std;

enum Color{White, Black};

struct subMatrix
{
    int row;
    int col;
    int size;

    subMatrix(): row(-1), col(-1), size(-1) {}
    subMatrix(int Row, int Col, int Size): row(Row), col(Col), size(Size) {}

    bool empty()
    {
        return row == -1 || col == -1 || size == -1;
    }
};

struct Point
{
    int blackRight;
    int blackBottom;
};

vector<vector<Point>> buildAuxMatrix(Color** matrix, const int n)
{
    vector<vector<Point>> aux;
    // 必须先初始化，否则越界
    aux.resize(n);
    for (auto& x: aux)
        x.resize(n);

    // 从迭代公式知，循环应该从右向左，从下向上
    for (int row = n - 1; row >= 0; row--)
    {
        for (int col = n - 1; col >= 0; col--)
        {
            if (matrix[row][col] == Black)
            {
                if (col + 1 < n)
                    aux[row][col].blackRight += aux[row][col + 1].blackRight + 1;

                if (row + 1 < n)
                    aux[row][col].blackBottom += aux[row + 1][col].blackBottom + 1;
            }
            else
                aux[row][col] = {0, 0};
        }
    }

    return aux;
}


bool isSquare(Color** matrix, const int n, const int row, const int col, const int i)
{
    vector<vector<Point>> aux = buildAuxMatrix(matrix, n);

    auto topLeft = aux[row][col];
    auto topRight = aux[row][col + i - 1];
    auto bottomLeft = aux[row + i - 1][col];

    if (topLeft.blackRight < i || topRight.blackBottom < i || bottomLeft.blackRight < i)
        return false;
    else
        return true;
}

subMatrix helper(Color** matrix, const int n, const int i)
{
    int count = n - i + 1;
    for (int row = 0; row < count; row++)
    {
        for (int col = 0; col < count; col++)
        {
            if (isSquare(matrix, n, row, col, i))
                return subMatrix(row, col, i);
        }
    }

    return subMatrix();
}


subMatrix findMaxSubMatrix(Color** matrix, const int n)
{
    for (int i = n; i >= 1; i--)
    {
        auto square = helper(matrix, n, i);
        if (!square.empty())
            return square;
    }
}
