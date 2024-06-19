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
int main()
{
    // int num = 2345;
    string str = "going";

    reverseString(str);
    cout << str << endl;
    // int result = reverseNumber(num);
    // cout << result << endl;
    return 0;
}