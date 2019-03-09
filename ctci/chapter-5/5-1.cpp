int insert(int m, int n, int low ,int high)
{
    int ones = ~0;
    int left = ones << (high + 1);
    int right = (1 << low) - 1;
    int mask = left | right;
    n &= mask;
    m = m << low;
    return n | m;
}

