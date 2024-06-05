#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverseString(string &str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        swap(str[i], str[str.length() - 1 - i]);
    }
}

int main()
{

    string str = "omshankar";
    reverseString(str);
    cout << str;
    return 0;
}