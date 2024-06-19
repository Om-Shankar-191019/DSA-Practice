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

int reverseNumber(int num)
{
    int y = 0;
    while (num)
    {
        int r = num % 10;
        y = y * 10 + r;
        num = num / 10;
    }
    return y;
}

void reverseString(string &s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - 1 - i]);
    }
}

void fibonacciSeries(int n)
{
    int a = 0;
    int b = 1;
    if (n == 1)
        cout << a;
    else if (n >= 2)
    {
        cout << a << " " << b << " ";
        for (int i = 3; i <= n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
            cout << c << " ";
        }
    }
}

bool isPalindrome(int n)
{
    int temp = reverseNumber(n);
    return temp == n;
}

int main()
{
    // int num = 2345;
    // string str = "going";

    // fibonacciSeries(10);

    bool result = isPalindrome(1234321);
    cout << result << endl;
    return 0;
}