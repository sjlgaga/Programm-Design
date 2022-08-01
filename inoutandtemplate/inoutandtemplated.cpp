#include <iostream>
using namespace std;
class MyCin
{
    // 在此处补充你的代码
    bool bStop;

public:
    MyCin() : bStop(false){};
    operator bool()
    {
        return !bStop;
    }
    MyCin &operator>>(int &n)
    {
        cin >> n;
        if (n == -1)
            bStop = true;
        return *this;
    }
};
int main()
{
    MyCin m;
    int n1, n2;
    while (m >> n1 >> n2)
        cout << n1 << " " << n2 << endl;
    return 0;
}