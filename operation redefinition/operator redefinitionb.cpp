#include <iostream>
using namespace std;
class MyInt
{
public:
    int nVal;

public:
    MyInt(int n) { nVal = n; }
    // 在此处补充你的代码
    MyInt &operator-(int a)
    {
        nVal -= a;
        return *this;
    }
    //没有&是浅复制，有&就是深复制？
    operator int()
    {
        return nVal;
    }
};
int Inc(int n)
{
    return n + 1;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while (cin >> n)
    {
        MyInt objInt(n);
        objInt - 2 - 1 - 3;

        cout << Inc(objInt);
        cout << ",";
        objInt - 2 - 1;

        cout << Inc(objInt) << endl;
    }
    return 0;
}