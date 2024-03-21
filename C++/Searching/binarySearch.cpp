#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// find x and count to its left and right;
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

void peakElements(int arr[], int n)
{
    if (n == 1)
    {
        cout << arr[0] << " ";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] >= arr[i + 1])
                cout << arr[i] << " ";
        }
        else if (i == n - 1)
        {
            if (arr[i] >= arr[i - 1])
                cout << arr[i] << " ";
        }
        else
        {
            if (arr[i] >= arr[i + 1] && arr[i] >= arr[i - 1])
                cout << arr[i] << " ";
        }
    }
}
int main()
{

    int arr[] = {12, 67, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    peakElements(arr, n);
    // int result = countOccurances(arr, n, 1);
    // cout << result << endl;
    return 0;
}