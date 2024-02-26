#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 3, 4, 4, 3, 5, 4, 4, 4, 3};

    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "Before: " << n << " : ";
    printArray(arr, n);
    cout << endl;

    // printArray(arr, n);

    return 0;
}