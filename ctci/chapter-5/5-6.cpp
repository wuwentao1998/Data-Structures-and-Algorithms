int swap(int x)
{
    static int odd = 0xaaaaaaaa;
    static int even =0x55555555;
    return ((x & odd) >> 1) | ((x & even) << 1);
}

