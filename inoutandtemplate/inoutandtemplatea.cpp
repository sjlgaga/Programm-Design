#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T *p1, T *p2)

{
    T temp;
    T *i = p1;
    while (i < p2)
    {
        temp += *i;
        i++;
    }
    return temp;
}
int main()
{
    string array[4] = {"Tom", "Jack", "Mary", "John"};
    cout << SumArray(array, array + 4) << endl;
    int a[4] = {1, 2, 3, 4}; //提示：1+2+3+4 = 10
    cout << SumArray(a, a + 4) << endl;
    return 0;
}