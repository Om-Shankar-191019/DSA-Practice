#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> a, vector<int> b)
{
    int start = -1;
    int end = -1;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            start = i;
            break;
        }
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
        {
            end = i;
            break;
        }
    }

    if (start == -1 || end == -1)
    {
        return 0;
    }
    return end - start + 1;
}
int main()
{
    int t;
    cin >> t; // Reading input from STDIN
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int res = fun(a, b);
        cout << "res : " << res;
        return res;
    }
}