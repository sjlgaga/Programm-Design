#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset
{
    char a[bitNum / 8 + 1];
    MyBitset() { memset(a, 0, sizeof(a)); };
    void Set(int i, int v)
    {
        char &c = a[i / 8];
        int bp = i % 8;
        if (v)
            c |= (1 << bp);
        else
            c &= ~(1 << bp);
    }
    // 在此处补充你的代码
    class inner
    {
    public:
        int text[20];
        bool flag;
        inner()
        {
            memset(text, 0, sizeof(text));
            flag = 0;
        }
        int &operator()(int n, MyBitset &r)
        {
            if (flag == 0)
            {
                for (int k = 0; k <= 2; k++)
                {
                    if (k != 2)
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            text[8 * k + i] = ((r.a[k] >> i) & 1);
                        }
                    }
                    else
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            text[8 * k + i] = ((r.a[k] >> i) & 1);
                        }
                    }
                }
                flag = 1;
            }
            return text[n];
        }
    };
    inner t;
    int &operator[](int n)
    {
        return t(n, *this);
    }
    void Print()
    {
        for (int i = 0; i < bitNum; ++i)
            cout << (*this)[i];
        cout << endl;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    int i, j, k, v;
    while (cin >> n)
    {
        MyBitset<20> bs;
        for (int i = 0; i < n; ++i)
        {
            int t;
            cin >> t;
            bs.Set(t, 1);
        }
        bs.Print();
        cin >> i >> j >> k >> v;
        bs[k] = v;
        bs[i] = bs[j] = bs[k];
        bs.Print();
        cin >> i >> j >> k >> v;
        bs[k] = v;
        (bs[i] = bs[j]) = bs[k];
        bs.Print();
    }
    return 0;
}