#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = i - 1;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(arr[k], arr[i - 1]);
    }
}
float medianOfTwoSortedArrays(int arr[], int brr[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    int t1 = 0, t2 = 0; // Correct initialization
    int N = n1 + n2;

    while (i < n1 && j < n2)
    {
        t1 = t2;
        if (arr[i] < brr[j])
        {
            t2 = arr[i++];
        }
        else
        {
            t2 = brr[j++];
        }

        if (k >= N / 2) // Stop when we reach the median index
            break;
        k++;
    }

    // Process remaining elements if one array is exhausted
    while (i < n1 && k < N / 2)
    {
        t1 = t2;
        t2 = arr[i++];
        k++;
    }
    while (j < n2 && k < N / 2)
    {
        t1 = t2;
        t2 = brr[j++];
        k++;
    }

    // Correct median calculation for even case
    if (N % 2 == 0)
        return (t1 + t2) / 2.0; // Ensure float division
    else
        return t2;
}

// count pair with given sum
int countPair(int arr[], int n, int givenSum)
{
    int count = 0;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.find(givenSum - arr[i]) != st.end())
            count++;
        st.insert(arr[i]);
    }
    return count;
}
int main()
{

    // int arr[] = {1, 4, 20, 3, 10, 5};
    // int arr[] = {10, 20, 30, 40, 50};
    // int brr[] = {5, 15, 25, 35, 45};

    // int n = sizeof(arr) / sizeof(arr[0]);
    int arr[] = {1, 3, 8};
    int brr[] = {7, 9, 10, 11};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(brr) / sizeof(brr[0]);

    cout << "Median: " << medianOfTwoSortedArrays(arr, brr, n1, n2) << endl;
    return 0;
}