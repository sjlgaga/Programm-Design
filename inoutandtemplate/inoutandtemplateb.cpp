#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template <class T1>
void MyForeach(T1 *p1, T1 *p2, void (*function)(T1 &))
{
    for (T1 *i = p1; i < p2; i++)
        function(*i);
}
template <class T1>
void MyForeach(T1 *p1, T1 *p2, void (*function)(T1))
{
    for (T1 *i = p1; i < p2; i++)
        function(*i);
}
void Print(string s)
{
    cout << s;
}
void Inc(int &n)
{
    ++n;
}
string array[100];
int a[100];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int m, n;
    while (cin >> m >> n)
    {
        for (int i = 0; i < m; ++i)
            cin >> array[i];
        for (int j = 0; j < n; ++j)
            cin >> a[j];
        MyForeach(array, array + m, Print);
        cout << endl;
        MyForeach(a, a + n, Inc);
        for (int i = 0; i < n; ++i)
            cout << a[i] << ",";
        cout << endl;
    }
    return 0;
}