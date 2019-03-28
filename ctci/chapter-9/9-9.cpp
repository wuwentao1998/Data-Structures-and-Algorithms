#include <vector>
#include <cmath>
#include <iterator>
#include <iostream>
using namespace std;

bool checkValid(vector<int>& cols, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int j = cols[i];

        if (j == col)
            return false;

        if (abs(i - row) == abs(j - col))
            return false;
    }

    return true;
}

void helper(const int grid, int row, vector<int> cols, vector<vector<int>>& results)
{
    if (row == grid)
        results.push_back(cols);
    else
    {
        for (int i = 0; i < grid; i++)
        {
            if (checkValid(cols, row, i))
            {
                cols[row] = i;
                helper(grid, row + 1, cols, results);
            }
        }
    }
}

void placeQueens(int grid)
{
    vector<vector<int>> results;
    helper(grid, 0, vector<int>(grid), results); // 记得要初始化，否则33行报错

    for (size_t i = 0; i < results.size(); i++)
    {
        copy(results[i].begin(), results[i].end(), ostream_iterator<int>(cout, " ")); // 流迭代器
        cout << endl;
    }
}


int main(void)
{
    placeQueens(8);
}