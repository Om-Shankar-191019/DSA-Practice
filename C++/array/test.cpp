#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printUnorderedMap(unordered_map<int, int> mp)
{
    unordered_map<int, int>::iterator it;
    for (; it != mp.end(); it++)
    {
        cout << it->first << " : " << it->second;
    }
    cout << endl;
}

vector<int> duplicates2(vector<int> arr)
{

    vector<int> result;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    unordered_map<int, int>::iterator it;
    for (; it != mp.end(); it++)
    {
        if (it->second > 1)
        {
            result.push_back(it->first);
        }
        cout << it->first << " : " << it->second;
    }

    sort(result.begin(), result.end());
    if (result.size() > 1)
        return result;
    else
    {
        result.push_back(-1);
        return result;
    }
}

vector<int> duplicates(vector<int> arr)
{

    vector<int> result;
    int count = 1;
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                result.push_back(arr[i - 1]);
            }
            count = 1;
        }
    }

    if (count > 1)
    {
        result.push_back(arr[arr.size() - 1]);
    }

    if (result.size() > 1)
        return result;
    else
    {
        result.push_back(-1);
        return result;
    }
}
int main()
{
    vector<int> v = {2, 3, 1, 2, 3};
    vector<int> r = duplicates(v);
    printVector(r);
    return 0;
}