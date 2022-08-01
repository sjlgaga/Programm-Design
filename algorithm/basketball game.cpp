#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int points[5], best;
char game[5][5];
class dot
{
public:
    int xx, yy;
    dot(int i, int j) : xx(i), yy(j){};
};
vector<dot> ungame;
void dfs(int n)
{
    if (n == ungame.size())
    {
        int rank = 1;
        for (int i = 2; i <= 4; i++)
        {
            if (points[i] > points[1])
                rank++;
        }
        best = min(rank, best);
        return;
    }
    points[ungame[n].xx]++;
    dfs(n + 1);
    points[ungame[n].xx]--;
    points[ungame[n].yy]++;
    dfs(n + 1);
    points[ungame[n].yy]--;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int casetime;
    cin >> casetime;
    while (casetime--)
    {
        memset(points, 0, sizeof(points));
        memset(game, 0, sizeof(game));
        best = 5;
        ungame.clear();
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                cin >> game[i][j];
                if (game[i][j] == '-')
                    continue;
                else if (game[i][j] == 'W')
                    points[i]++;
                else if (game[i][j] == 'L')
                    points[j]++;
                else if (game[i][j] == '?')
                    ungame.push_back(dot(i, j));
            }
        }
        dfs(0);
        cout << best << endl;
    }
}