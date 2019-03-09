int changeBits(int a, int b)
{
    int c = a ^ b;
    int num = 0;
    while (c != 0)
    {
        c = c & (c - 1);
        num++;
    }
    return num;
}

