#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "交换前的值：" << endl;
    cout << "a=" << a << " " << "b=" << b << endl;

    Swap(&a, &b);

    cout << "交换后的值：" << endl;
    cout << "a=" << a <<" " << "b=" << b << endl;


}







