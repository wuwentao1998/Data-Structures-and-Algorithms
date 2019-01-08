// 空格替换
// 使用场景： 网络编程中，URL参数中含有特殊字符，例如空格，需要替换为服务器可识别的参数
#include <assert.h>

void replace(char* str, int len)
{
    if (str == nullptr || len <= 0)
        return;

    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == ' ')
            count++;
    }

    int move = count * 2;

    for (int i = len; i >= 0; --i)
    {
        if (count == 0)
            break;

        if (str[i] != ' ')
            str[i + move] = str[i];
        else
        {
            --count;
            str[i + move] = '0';
            str[i + move - 1] = '2';
            str[i + move - 2] = '\%';
            move -= 2; // move的值不是一直不变的
        }
    }
}



/* 测试代码 */

int main(int argc, char const *argv[])
{
    char a[10] = "hai ya";
    char b[5] = " ";
    char c[30] = " wo shi shei ";
    char d[10] = "hhh ";
    char e[10] = " bbb";
    replace(a, 6);
    replace(b, 1);
    replace(c, 13);
    replace(d, 4);
    replace(e, 4);
    return 0;
}

