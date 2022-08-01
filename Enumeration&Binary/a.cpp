#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int watch[10];
int step[10];
int press[12];
void move(int n, int tie)
{
    if (tie == 0)
        return;

    if (n == 0)
        return;
    else if (n == 1)
        step[1] += tie, step[2] += tie, step[4] += tie, step[5] += tie;
    else if (n == 2)
        step[1] += tie, step[2] += tie, step[3] += tie;
    else if (n == 3)
        step[2] += tie, step[3] += tie, step[5] += tie, step[6] += tie;
    else if (n == 4)
        step[1] += tie, step[4] += tie, step[7] += tie;
    else if (n == 5)
        step[2] += tie, step[4] += tie, step[5] += tie, step[6] += tie, step[8] += tie;
    else if (n == 6)
        step[3] += tie, step[6] += tie, step[9] += tie;
    else if (n == 7)
        step[4] += tie, step[5] += tie, step[7] += tie, step[8] += tie;
    else if (n == 8)
        step[7] += tie, step[8] += tie, step[9] += tie;
    else if (n == 9)
        step[5] += tie, step[6] += tie, step[8] += tie, step[9] += tie;

    return;
}
bool end()
{
    for (int i = 1; i <= 9; i++)
    {
        if (press[i] != 3)
            return false;
    }
    return true;
}
bool satisfy()
{
    for (int i = 1; i <= 9; i++)
    {
        if ((watch[i] + step[i]) % 4 != 0)
            return false;
    }
    return true;
}
int main()
{

    memset(watch, 0, sizeof(watch));
    vector<int> ans;
    vector<int> cmp;
    for (int i = 1; i <= 9; i++)
        cin >> watch[i];
    int c;
    memset(press, 0, sizeof(press));
    while (!end())
    {
        press[1]++;
        c = 1;
        while (press[c] > 4)
        {
            press[c] = 0;
            c++;
            press[c]++;
        }
        memset(step, 0, sizeof(step));
        for (int i = 1; i <= 9; i++)
        {
            move(i, press[i]);
        }
        if (satisfy())
        {
            if (ans.empty())
            {
                for (int i = 1; i <= 9; i++)
                {
                    for (int j = 1; j <= press[i]; j++)
                        ans.push_back(i);
                }
            }
            else
            {
                int sum = 0;
                cmp.clear();
                for (int i = 1; i <= 9; i++)
                {
                    for (int j = 1; j <= press[i]; j++)
                    {
                        cmp.push_back(i);
                        sum++;
                    }
                }
                if (sum < ans.size())
                {
                    ans.clear();
                    for (int i = 1; i <= 9; i++)
                    {
                        ans.clear();
                        for (auto i : cmp)
                            ans.push_back(i);
                    }
                }
                else if (sum == ans.size())
                {
                    bool flag = false;
                    for (int i = 0; i < ans.size(); i++)
                    {
                        if (cmp[i] < ans[i])
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (flag == true)
                    {
                        ans.clear();
                        for (auto i : cmp)
                            ans.push_back(i);
                    }
                }
            }
        }
    }
    for (auto i : ans)
        cout << i << " ";
}