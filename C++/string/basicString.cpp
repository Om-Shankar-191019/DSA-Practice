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

void freqOfChars2(string &s)
{
    int count[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
    }

    // freq of char print in same order.
    // for (int i = 0; i < s.length(); i++)
    // {
    //     cout << s[i] << " : " << count[s[i] - 'a'] << endl;
    // }

    // freq of char print in alphabetical order.
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
            cout << (char)(i + 97) << " : " << count[i] << endl;
    }
}
int main()
{

    string str = "geeksforgeeks";
    freqOfChars2(str);
    cout << str;
    return 0;
}