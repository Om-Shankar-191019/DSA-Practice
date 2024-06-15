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

int longestConsecutiveSubseqNaive(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int s = arr[i] + 1;
        int count = 1;
        bool flag;
        do
        {
            flag = false;
            for (int j = 0; j < n; j++)
            {
                if (s == arr[j])
                {
                    flag = true;
                    count++;
                    break;
                }
            }
            s++;
            // cout << " count : " << count << endl;
        } while (flag);
        // cout << "res : " << res << endl;
        res = max(res, count);
    }
    return res;
}
int main()
{
    int arr[] = {2, 3, 9, 21, 4, 20, 23, 22, 25, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int fun = longestConsecutiveSubseqNaive(arr, n);
    cout << fun << endl;
    return 0;
}