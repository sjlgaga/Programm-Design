#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int pot1;
    int pot2;
    int former;
    int action; // 1 fill i 2 fill j 3 drop i 4 drop j 5 pour i to j 6 pour j to i
    int cost;
};
node q[1 << 15];
int head = 0, tail = 1;
int a, b, c;
bool poured[105][105];
vector<int> an;
void get(int n)
{
    if (q[n].action == 0)
        return;
    an.push_back(q[n].action);
    get(q[n].former);
    return;
}
void out(int n)
{
    if (n == 1)
        cout << "FILL(1)" << endl;
    else if (n == 2)
        cout << "FILL(2)" << endl;
    else if (n == 3)
        cout << "DROP(1)" << endl;
    else if (n == 4)
        cout << "DROP(2)" << endl;
    else if (n == 5)
        cout << "POUR(1,2)" << endl;
    else if (n == 6)
        cout << "POUR(2,1)" << endl;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(poured, 0, sizeof(poured));
    poured[0][0] = 1;
    cin >> a >> b >> c;
    q[1].pot1 = 0, q[1].pot2 = 0, q[1].former = 0, q[1].action = 0, q[1].cost = 0;
    int ans = 0;
    while (head < tail)
    {
        head++;
        node d = q[head];
        if (d.pot1 == c || d.pot2 == c)
        {
            ans = head;
            break;
        }
        int temp1, temp2;
        temp1 = a, temp2 = d.pot2;
        if (poured[temp1][temp2] == 0)
        {
            tail++;
            q[tail].pot1 = temp1, q[tail].pot2 = temp2, q[tail].former = head, q[tail].action = 1, q[tail].cost = d.cost + 1;
            poured[temp1][temp2] = 1;
        }

        temp1 = d.pot1, temp2 = b;
        if (poured[temp1][temp2] == 0)
        {
            tail++;
            q[tail].pot1 = temp1, q[tail].pot2 = temp2, q[tail].former = head, q[tail].action = 2, q[tail].cost = d.cost + 1;
            poured[temp1][temp2] = 1;
        }

        temp1 = 0, temp2 = d.pot2;
        if (poured[temp1][temp2] == 0)
        {
            tail++;
            q[tail].pot1 = temp1, q[tail].pot2 = temp2, q[tail].former = head, q[tail].action = 3, q[tail].cost = d.cost + 1;
            poured[temp1][temp2] = 1;
        }

        temp1 = d.pot1, temp2 = 0;
        if (poured[temp1][temp2] == 0)
        {
            tail++;
            q[tail].pot1 = temp1, q[tail].pot2 = temp2, q[tail].former = head, q[tail].action = 4, q[tail].cost = d.cost + 1;
            poured[temp1][temp2] = 1;
        }

        if (d.pot1 > b - d.pot2)
        {
            temp1 = d.pot1 - (b - d.pot2);
            temp2 = b;
        }
        else
        {
            temp1 = 0;
            temp2 = d.pot2 + d.pot1;
        }
        if (poured[temp1][temp2] == 0)
        {
            tail++;
            q[tail].pot1 = temp1, q[tail].pot2 = temp2, q[tail].former = head, q[tail].action = 5, q[tail].cost = d.cost + 1;
            poured[temp1][temp2] = 1;
        }
        if (d.pot2 > a - d.pot1)
        {
            temp1 = a;
            temp2 = d.pot2 - (a - d.pot1);
        }
        else
        {
            temp1 = d.pot1 + d.pot2;
            temp2 = 0;
        }
        if (poured[temp1][temp2] == 0)
        {
            tail++;
            q[tail].pot1 = temp1, q[tail].pot2 = temp2, q[tail].former = head, q[tail].action = 6, q[tail].cost = d.cost + 1;
            poured[temp1][temp2] = 1;
        }
    }
    if (ans == 0)
        cout << "impossible";
    else
    {
        cout << q[ans].cost << endl;
        get(ans);
        reverse(an.begin(), an.end());
        for (auto i : an)
            out(i);
    }
}