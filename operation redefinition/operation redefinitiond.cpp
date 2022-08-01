#include <iostream>
#include <cstring>
using namespace std;

class Array2
{
    // 在此处补充你的代码
private:
    int **p;
    int row, col;

public:
    Array2(int x = 0, int y = 0) : row(x), col(y)
    {
        if (x == 0 && y == 0)
            p = NULL;
        else
        {
            p = new int *[row];
            for (int i = 0; i < row; i++)
            {
                p[i] = new int[col];
            }
        }
    }
    Array2(const Array2 &r)
    {

        row = r.row;
        col = r.col;
        p = new int *[row];
        for (int i = 0; i < row; i++)
            p[i] = new int[i];
        memcpy(p, r.p, sizeof(int) * row * col);
    }
    Array2 operator=(const Array2 &r)
    {
        if (p)
            delete[] p;
        row = r.row;
        col = r.col;
        p = new int *[row];
        for (int i = 0; i < row; i++)
            p[i] = new int[i];
        memcpy(p, r.p, sizeof(int) * row * col);
        return *this;
    }
    int *operator[](int i)
    {
        return p[i];
    }
    int operator()(int i, int j)
    {
        return p[i][j];
    }
    ~Array2()
    {
        if (p)
            delete[] p;
    }
};

int main()
{
    freopen("out.txt", "w", stdout);
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}