#include <iostream>
#include <cstring>
using namespace std;
int board[6][6];
int press[6][6];
bool end()
{
    if (press[1][5] == 1)
        return false;
    else
        return true;
}
bool satisfy(int n)
{
    if (n == 0)
    {
        for (int i = 1; i <= 4; i++)
        {
            if ((press[3][i] + press[4][i - 1] + press[4][i] + press[4][i + 1] + board[4][i]) % 2 != 0)
                return false;
        }
        return true;
    }
    else if (n == 1)
    {

        for (int i = 1; i <= 4; i++)
        {
            if ((press[3][i] + press[4][i - 1] + press[4][i] + press[4][i + 1] + board[4][i]) % 2 != 1)
                return false;
        }
        return true;
    }
    return true;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(board, 0, sizeof(board));
    memset(press, 0, sizeof(press));
    char s[6][6];
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == 'b')
                board[i][j] = 0;
            else if (s[i][j] == 'w')
                board[i][j] = 1; // 0 black 1 white
        }
    } // if can all black

    int c;
    int ans = 20;
    while (end())
    {
        c = 1;
        while (press[1][c] > 1)
        {
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
        for (int i = 2; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                press[i][j] = (press[i - 2][j] + press[i - 1][j] + press[i - 1][j - 1] + press[i - 1][j + 1] + board[i - 1][j]) % 2;
            }
        }
        if (satisfy(0))
        {
            int sum = 0;
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 1; j <= 4; j++)
                {
                    if (press[i][j] == 1)
                        sum++;
                }
            }
            if (sum < ans)
                ans = sum;
        }
        press[1][1]++;
    }
    // if can all white
    memset(press, 0, sizeof(press));
    while (end())
    {
        c = 1;
        while (press[1][c] > 1)
        {
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
        for (int i = 2; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                if ((press[i - 2][j] + press[i - 1][j] + press[i - 1][j - 1] + press[i - 1][j + 1] + board[i - 1][j]) % 2 == 1)
                    press[i][j] = 0;
                else
                    press[i][j] = 1;
            }
        }
        if (satisfy(1))
        {
            int sum = 0;
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 1; j <= 4; j++)
                {
                    if (press[i][j] == 1)
                        sum++;
                }
            }
            if (sum < ans)
                ans = sum;
        }
        press[1][1]++;
    }
    if (ans == 20)
        cout << "Impossible";
    else
        cout << ans;
}