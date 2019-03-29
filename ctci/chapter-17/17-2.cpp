#include <vector>

using namespace std;

enum Grid {Empty, X, O};

Grid win(Grid** board, int n)
{
    if (board == nullptr || n <= 2)
        return Empty;

    int col = 0, row = 0;

    for (row = 0; row < n; row++)
    {
        if (board[row][0] != Empty)
        {
            for (col = 1; col < n; col++)
            {
                if (board[row][col - 1] != board[row][col])
                    break;
            }

            if (col == n)
                return board[row][0];
        }
    }

    for (col = 0; col < n; col++)
    {
        if (board[0][col] != Empty)
        {
            for (row = 1; row < n; row++)
            {
                if (board[row - 1][col] != board[row][col])
                    break;
            }

            if (row == n)
                return board[0][col];
        }
    }

    if (board[0][0] != Empty)
    {
        for (row = 1; row < n; row++)
        {
            if (board[row][col] != board[row - 1][col - 1])
                break;
        }

        if (row == n)
            return board[0][0];
    }

    if (board[row - 1][0] != Empty)
    {
        for (row = 1; row < n; row++)
        {
            if (board[n - row - 1][row] != board[n - row][row - 1])
                break;
        }

        if (row == n)
            return board[row - 1][0];
    }

    return Empty;
}