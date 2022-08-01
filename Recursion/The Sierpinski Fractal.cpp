#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
char tri[3000][3000];
void draw(int layer, int xx, int yy)
{
    if (layer == 1)
    {
        tri[xx][yy] = '/';
        tri[xx][yy + 1] = '\\';
        tri[xx + 1][yy - 1] = '/';
        tri[xx + 1][yy] = '_';
        tri[xx + 1][yy + 1] = '_';
        tri[xx + 1][yy + 2] = '\\';
    }
    else
    {
        draw(layer - 1, xx, yy);
        draw(layer - 1, xx + pow(2, layer - 1), yy - pow(2, layer - 1));
        draw(layer - 1, xx + pow(2, layer - 1), yy + pow(2, layer - 1));
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    for (;;)
    {
        cin >> t;
        if (t == 0)
            break;
        else
        {
            memset(tri, ' ', sizeof(tri));
            draw(t, 1, pow(2, t));
        }
        for (int i = 1; i <= pow(2, t); i++)
        {
            for (int j = 1; j <= pow(2, t + 1); j++)
                cout << tri[i][j];
            cout << endl;
        }
        cout << endl;
    }
}