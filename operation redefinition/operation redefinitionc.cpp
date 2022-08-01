#include <iostream>
using namespace std;
class Point
{
public:
    int x;
    int y;

public:
    Point(){};
    // 在此处补充你的代码
    friend istream &operator>>(istream &i, Point &p)
    {
        i >> p.x >> p.y;
        return i;
    }
    friend ostream &operator<<(ostream &o, Point &p)
    {
        o << p.x << "," << p.y;
        return o;
    }
};
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    Point p;
    while (cin >> p)
    {
        cout << p.x << " " << p.y << endl;
        cout << p << endl;
    }
    return 0;
}