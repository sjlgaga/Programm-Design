#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int getnum(int num)
{
    int k = 0;
    int n = num;
    for (int j = 2; j <= n / 2; j++)
    {
        if (num == 1)
            break;
        if (num % j == 0)
        {
            k++;
            while (num % j == 0)
                num /= j;
        }
    }
    return k;
}
struct mycompare1
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
};
struct mycompare2
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        else
            return a.second > b.second;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, num;
    cin >> t;
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare1> p;
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare2> q;

    while (t--)
    {
        for (int i = 1; i <= 10; i++)
        {
            cin >> num;
            pair<int, int> temp(num, getnum(num));
            p.push(temp);
            q.push(temp);
        }
        cout << p.top().first << " " << q.top().first << endl;
        p.pop();
        q.pop();
    }
}