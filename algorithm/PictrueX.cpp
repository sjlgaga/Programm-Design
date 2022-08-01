#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int pic[2200][2200];
void draw(int xx, int yy, int layer)
{
    if (layer == 0)
    {
        pic[xx][yy] = 1;
        return;
    }
    draw(xx, yy, layer - 1);
    draw(xx + 2 * pow(3, layer - 1), yy, layer - 1);
    draw(xx + pow(3, layer - 1), yy + pow(3, layer - 1), layer - 1);
    draw(xx, yy + 2 * pow(3, layer - 1), layer - 1);
    draw(xx + 2 * pow(3, layer - 1), yy + 2 * pow(3, layer - 1), layer - 1);
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    for (;;)
    {
        cin >> t;
        if (t == -1)
            break;
        memset(pic, 0, sizeof(pic));
        draw(1, 1, t - 1);
        for (int i = 1; i <= pow(3, t - 1); i++)
        {
            for (int j = 1; j <= pow(3, t - 1); j++)
            {
                if (pic[i][j] == 0)
                    cout << ' ';
                else
                    cout << 'X';
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
}