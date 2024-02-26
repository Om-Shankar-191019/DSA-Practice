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

int largest(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

int getLargestEleIndex(int arr[], int n)
{
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[maxi])
        {
            maxi = i;
        }
    }
    return maxi;
}

// works only for +ve num.
int secondLargest(int arr[], int n)
{
    int result = -1;
    int large = getLargestEleIndex(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[large])
            if (result == -1 || arr[i] > arr[result])
                result = i;
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 4, 4, 3, 5, 4, 4, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // printArray(arr, n);

    int result = secondLargest(arr, n);
    cout << result;

    // printArray(arr, n);

    return 0;
}