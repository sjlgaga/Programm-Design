#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
    // 在此处补充你的代码
public:
    T *p;
    int f, r, c;
    CArray3D(int f1, int r1, int c1) : f(f1), r(r1), c(c1) { p = new T[f * r * c]; }
    ~CArray3D() { delete[] p; }
    class CArray2D
    {
    public:
        T *fp;
        int c;
        CArray2D(T *p1, int c1) : fp(p1), c(c1){};
        T *operator[](int r2)
        {
            return fp + r2 * c;
        }
        operator T *()
        {
            return fp;
        }
    };
    CArray2D operator[](int f2)
    {
        return CArray2D(p + f2 * r * c, c);
    }
};

CArray3D<int> a(3, 4, 5);
CArray3D<double> b(3, 2, 2);
void PrintA()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "layer " << i << ":" << endl;
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 5; ++k)
                cout << a[i][j][k] << ",";
            cout << endl;
        }
    }
}
void PrintB()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "layer " << i << ":" << endl;
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
                cout << b[i][j][k] << ",";
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for (int i = 0; i < 3; ++i)
    {
        a[i];
        for (int j = 0; j < 4; ++j)
        {
            a[j][i];
            for (int k = 0; k < 5; ++k)
                a[i][j][k] = No++;
            a[j][i][i];
        }
    }
    PrintA();
    memset(a[1], -1, 20 * sizeof(int));
    memset(a[1], -1, 20 * sizeof(int));
    PrintA();
    memset(a[1][1], 0, 5 * sizeof(int));
    PrintA();

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                b[i][j][k] = 10.0 / (i + j + k + 1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;

    return 0;
}