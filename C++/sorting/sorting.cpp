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

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void selectionSort(int arr[], int n)
{
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = k = i; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(arr[k], arr[i]);
    }
}

int *mergeTwoSortedArrayNaive(int a[], int b[], int m, int n)
{
    int *temp = new int[m + n];
    int k = 0;
    for (int i = 0; i < m; i++)
        temp[k++] = a[i];
    for (int i = 0; i < n; i++)
        temp[k++] = b[i];
    sort(temp, temp + m + n);
    return temp;
}
int main()
{
    int arr[] = {2, 7, 6, 9, 4, 5};
    int brr[] = {2, 7, 6, 9, 4, 5};
    int an = sizeof(arr) / sizeof(arr[0]);
    int bn = sizeof(brr) / sizeof(brr[0]);

    // int n = sizeof(arr) / sizeof(arr[0]);
    // selectionSort(arr, n);

    int *p = mergeTwoSortedArrayNaive(arr, brr, an, bn);

    cout << endl;
    printArray(p, an + bn);

    return 0;
}