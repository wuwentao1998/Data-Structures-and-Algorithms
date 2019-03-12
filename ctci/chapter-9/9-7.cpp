#include <vector>
using namespace std;

void paint(vector<vector<int>>& screen, int row, int col, int x, int y, int color, int origin)
{
    if (x < 0 || x >= col || y < 0 || y >= col || screen[x][y] != origin)
        return;

    screen[x][y] = color;
    paint(screen, row, col, x - 1, y, color, origin);
    paint(screen, row, col, x + 1, y, color, origin);
    paint(screen, row, col, x, y - 1, color, origin);
    paint(screen, row, col, x, y +1, color, origin);
}