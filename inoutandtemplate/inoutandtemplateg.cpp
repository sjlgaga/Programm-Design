#include <iostream>
using namespace std;

bool Greater2(int n1, int n2)
{
    return n1 > n2;
}
bool Greater1(int n1, int n2)
{
    return n1 < n2;
}
bool Greater3(double d1, double d2)
{
    return d1 < d2;
}

template <class T1>
void mysort(T1 *start, T1 *end, bool (*function)(T1, T1))
{
    int k = 0;
    for (T1 *i = start; i < end; i++)
    {
        k++;
        for (T1 *j = start; j < end - k; j++)
        {
            if (function(*j, *(j + 1)) == false)
            {
                T1 temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
}
// 在此处补充你的代码
#define NUM 5
int main()
{
    int an[NUM] = {8, 123, 11, 10, 4};
    mysort(an, an + NUM, Greater1); //从小到大排序
    for (int i = 0; i < NUM; i++)
        cout << an[i] << ",";
    mysort(an, an + NUM, Greater2); //从大到小排序
    cout << endl;
    for (int i = 0; i < NUM; i++)
        cout << an[i] << ",";
    cout << endl;
    double d[6] = {1.4, 1.8, 3.2, 1.2, 3.1, 2.1};
    mysort(d + 1, d + 5, Greater3); //将数组从下标1到下标4从小到大排序
    for (int i = 0; i < 6; i++)
        cout << d[i] << ",";
    return 0;
}