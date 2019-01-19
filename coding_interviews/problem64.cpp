// 求 1+2+3...+n

// 方法一：构造函数

class Solution1
{
public:
    Solution1()
    {
        ++N;
        Sum += N;
    }

    static void reset()
    {
        N = 0;
        Sum = 0;
    }

    static int getSum() { return Sum; }

private:
    static int N;
    static int Sum;
};

int solution1(int n)
{
    Solution1::reset();

    Solution1* a = new Solution1[n];
    delete[] a;
    a = nullptr;

    return Solution1::getSum();
}

// 方法二：虚函数

class A;
A* array[2];

class A
{
public:
    virtual int sum(int n) { return 0; }
};

class B: public A
{
public:
    virtual int sum(int n) { return array[!!n]->sum(n-1) +n; }
};

int Solution2(int n)
{
    A a;
    B b;
    array[0] = &a;
    array[1] = &b;

    return array[1]->sum(n);
}

// 方法三：模板

template<int n>
struct Solution3
{
    enum Value { N = Solution<n - 1>::N + n};
};

template<>
struct Solution3<1>
{
    enum Value {N = 1};
};


// 方法四：递归

int Solution4(int n)
{
    int ans = n;
    ans && (ans += Solution4(n - 1));

    return ans;
}


