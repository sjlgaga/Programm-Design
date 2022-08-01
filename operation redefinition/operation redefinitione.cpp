#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt
{
    // 在此处补充你的代码
private:
    char buf[210];

public:
    void reverse(char *p)
    {
        int i = 0, j = strlen(p) - 1;
        while (i < j)
        {
            swap(p[i], p[j]);
            i++;
            j--;
        }
    }
    CHugeInt(char *s)
    {
        memset(buf, 0, sizeof(buf));
        strcpy(buf, s);
        reverse(buf);
    }
    CHugeInt(int n)
    {
        memset(buf, 0, sizeof(buf));
        itoa(n, buf, 10);
        reverse(buf);
    }
    CHugeInt operator+(int n)
    {
        return *this + CHugeInt(n);
    }
    CHugeInt operator+(const CHugeInt &n)
    {
        CHugeInt temp(0);
        int upper = 0;
        for (int i = 0; i < 210; i++)
        {
            if (buf[i] == 0 && n.buf[i] == 0 && upper == 0)
                break;
            int k1, k2;
            if (buf[i] == 0)
                k1 = 0;
            else
                k1 = buf[i] - '0';
            if (n.buf[i] == 0)
                k2 = 0;
            else
                k2 = n.buf[i] - '0';

            k1 = k1 + k2 + upper;
            if (k1 >= 10)
            {
                k1 -= 10;
                upper = 1;
            }
            else
                upper = 0;
            temp.buf[i] = k1 + '0';
        }
        return temp;
    }
    friend CHugeInt operator+(int n, CHugeInt &a)
    {
        return a + n;
    }
    CHugeInt &operator++()
    {
        *this = *this + 1;
        return *this;
    }
    CHugeInt operator++(int)
    {
        CHugeInt tmp(*this);
        *this = *this + 1;
        return tmp;
    }
    friend ostream &operator<<(ostream &o, const CHugeInt &h)
    {
        int len = strlen(h.buf);
        for (int i = len - 1; i >= 0; --i)
            cout << h.buf[i];
        return o;
    }
    CHugeInt &operator+=(int n)
    {
        *this = *this + n;
        return *this;
    }
};
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char s[210];
    int n;

    while (cin >> s >> n)
    {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout << ++b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}