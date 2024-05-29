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

int main()
{

    int result = countDigit(3);
    cout << result << endl;
    return 0;
}