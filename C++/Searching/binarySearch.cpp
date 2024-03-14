#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countOccurances(int arr[], int n, int x)
{
    int l = 0, h = n - 1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] > x)
            h = mid - 1;
        else if (arr[mid] < x)
            l = mid + 1;
        else
            break;
    }

    if (l > h)
    {
        return 0;
    }
    int count = 1;
    int i = mid + 1;
    while (i < n)
    {
        if (arr[i] == arr[mid])
        {
            count++;
            i++;
        }
        else
        {
            break;
        }
    }
    i = mid - 1;
    while (i >= 0)
    {
        if (arr[i] == arr[mid])
        {
            count++;
            i--;
        }
        else
        {
            break;
        }
    }

    return count;
}
int main()
{

    int arr[] = {2, 3, 6, 6, 6, 6, 6, 6, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countOccurances(arr, n, 1);
    cout << result << endl;
    return 0;
}