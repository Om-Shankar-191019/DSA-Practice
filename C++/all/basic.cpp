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

bool isPalindromeString(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    // int num = 2345;
    // string str = "going";

    // fibonacciSeries(10);

    bool result = isPalindromeString("datad");
    cout << result << endl;
    return 0;
}