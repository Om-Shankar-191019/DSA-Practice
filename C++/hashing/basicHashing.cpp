#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSubArrayWithGivenSumExist(int arr[], int n, int sum)
{
    int prefixSum = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == sum)
            return true;
        if (s.find(prefixSum - sum) != s.end())
        {
            return true;
        }
        s.insert(prefixSum);
    }
    return false;
}

int main()
{
    int arr[] = {2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool fun = isSubArrayWithGivenSumExist(arr, n, 5);
    cout << fun << endl;
    return 0;
}