#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int helper(vector<vector<int>>& matrix, int width, int height, int x, int y)
{
    if (x == 0 || y == 0)
        return 1;

    if (matrix[x][y] != 0)
        return matrix[x][y];

    int left = helper(matrix, width, height, x- 1, y);
    int up = helper(matrix, width, height, x, y - 1);
    matrix[x][y] = left + up;
    return matrix[x][y];
}

int ways(int x, int y)
{
    if (x < 1 || y < 1)
        return 0;

    vector<vector<int>> matrix(x);
    for (int i = 0; i < x; i++)
        matrix[i].resize(y);

    return helper(matrix, x, y, x - 1, y - 1);
}

int main(void)
{
    cout << ways(3,3);
}