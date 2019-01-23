// 利用流迭代器读取一串整数，将奇书写入一个文件，将偶数写入另一个文件
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

bool isOdd(int n)
{
    return n % 2 != 0;
}

bool isEven(int n)
{
    return n % 2 == 0;
}

int main(int argc, char const *argv[])
{
    ofstream out1("odd.txt");
    ofstream out2("even.txt");
    vector<int> vec;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vec));
    copy_if(vec.begin(), vec.end(), ostream_iterator<int>(out1, " "), isOdd);
    copy_if(vec.begin(), vec.end(), ostream_iterator<int>(out2, "\n"), isEven);

    return 0;
}
