// 机器人的运动范围

#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

int range(int row, int col, int k, int i, int j, bool* isVisited);

int digitSum(int num)
{
    int sum = 0;

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int range(int row, int col, int k)
{
    if (row <= 0 || col <= 0 || k < 0)
        return -1;

    bool* isVisited = new bool[row * col];
    memset(isVisited, 0, row * col);

    int count = range(row, col, k, 0, 0, isVisited);

    delete[] isVisited;
    return count;
}

int range(int row, int col, int k, int i, int j, bool* isVisited)
{
    if (i < 0 || i >= row || j < 0 || j >= col
    || isVisited[i * col + j] || k < digitSum(i) + digitSum(j))
        return 0;

    isVisited[i * col + j] = true;
    return 1 + range(row, col, k, i + 1, j, isVisited)
    +  range(row, col, k, i - 1, j, isVisited)
    +  range(row, col, k, i, j + 1, isVisited)
    +  range(row, col, k, i, j - 1, isVisited);
}

int main(int argc, char const *argv[])
{
    assert(range(1, 5, 3) == 4);
    assert(range(1, 6, 5) == 6);
    assert(range(4, 5, 0) == 1);
    assert(range(4, 4, 4) == 13);

    return 0;
}
