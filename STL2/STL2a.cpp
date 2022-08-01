#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class MyList
{
public:
    int no;
    list<int> lst;

public:
};
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int ordernum;
    cin >> ordernum;
    string order;
    int no, no2, num;
    vector<MyList> ListArray;
    while (ordernum--)
    {
        cin >> order;
        if (order == "new")
        {
            cin >> no;
            MyList temp;
            temp.no = no;

            ListArray.push_back(temp);
        }
        else if (order == "add")
        {
            cin >> no >> num;
            for (int i = 0; i < ListArray.size(); i++)
            {
                if (ListArray[i].no == no)
                {
                    ListArray[i].lst.push_back(num);
                    break;
                }
            }
        }
        else if (order == "out")
        {
            cin >> no;
            for (auto i : ListArray)
            {

                if (i.no == no)
                {
                    i.lst.sort();
                    for (auto j : i.lst)
                        cout << j << " ";
                    cout << endl;
                    break;
                }
            }
        }

        else if (order == "merge")
        {
            cin >> no >> no2;
            for (int i = 0; i < ListArray.size(); i++)
            {
                if (ListArray[i].no == no)
                {
                    for (int j = 0; j < ListArray.size(); j++)
                    {
                        if (ListArray[j].no == no2)
                        {
                            ListArray[i].lst.merge(ListArray[j].lst);
                            break;
                        }
                    }
                }
            }
        }

        else if (order == "unique")
        {
            cin >> no;
            for (int i = 0; i < ListArray.size(); i++)
            {
                if (ListArray[i].no == no)
                {
                    ListArray[i].lst.sort();
                    ListArray[i].lst.unique();
                    break;
                }
            }
        }
    }
}