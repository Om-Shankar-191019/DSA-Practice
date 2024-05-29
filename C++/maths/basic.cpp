#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countDigit(long n)
{
    int c = 0;
    while (n != 0)
    {
        n = n / 10;
        c++;
    }
    return c;
}

int reverseNum(int n)
{
    int y = 0;
    while (n != 0)
    {
        int r = n % 10;
        y = y * 10 + r;
        n = n / 10;
    }
    return y;
}

int main()
{

    int result = reverseNum(234);
    cout << result << endl;
    return 0;
}