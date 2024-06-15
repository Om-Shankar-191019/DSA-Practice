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

void freqOfChars(string &s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for (auto x : mp)
    {
        cout << x.first << " : " << x.second << endl;
    }
}
int main()
{

    string str = "geeksforgeeks";
    freqOfChars(str);
    cout << str;
    return 0;
}