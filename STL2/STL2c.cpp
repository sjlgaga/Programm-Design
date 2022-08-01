#include <iostream>
#include <set>
#include <iterator>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    multiset<int> m;
    set<int> added;
    string order;
    int num;
    int ordernum;
    set<int>::const_iterator i;
    cin >> ordernum;
    while (ordernum--)
    {
        cin >> order;
        switch (order[1])
        {
        case 'd':
            cin >> num;
            m.insert(num);
            added.insert(num);
            cout << m.count(num) << endl;
            break;
        case 'e':
            cin >> num;
            cout << m.count(num) << endl;
            m.erase(num);
            break;
        case 's':
            cin >> num;
            i = added.find(num);
            if (i != added.end())
                cout << 1 << " ";
            else
                cout << 0 << " ";
            cout << m.count(num) << endl;
        }
    }
}