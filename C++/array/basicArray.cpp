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

int deleteOne(int arr[], int n, int key)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            for (int j = i + 1; j < n; j++)
            {
                arr[j - 1] = arr[j];
            }
            return n - 1;
        }
    }
    return n;
}

int deleteAllOccurances(int arr[], int n, int key)
{
    int p = -1, q;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            p = i;
            break;
        }
    }
    if (p == -1)
    {
        return n;
    }

    q = p + 1;
    for (; q < n; q++)
    {
        if (arr[q] != key)
        {
            arr[p++] = arr[q];
        }
    }
    return p;
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