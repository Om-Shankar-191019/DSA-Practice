#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swapTwoNumbers(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << " a : " << a << endl;
    cout << " b : " << b << endl;
    cout << " after swap ----- " << endl;
    swapTwoNumbers(&a, &b);
    cout << " a : " << a << endl;
    cout << " b : " << b << endl;
    return 0;
}