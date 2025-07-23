#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false; // optimization flag
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            { // swap if adjacent elements are out of order
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
            break; // exit early if no swaps occurred → array is sorted
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {                      // Traverse from 0 to n-1
        int temp = arr[i]; // Current element to be inserted
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than temp
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j]; // Shift right
            j--;
        }
        arr[j + 1] = temp; // Place temp in its correct position
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
            {
                k = j;
            }
        }
        swap(arr[k], arr[i]);
    }
}

// merge two sorted array in sorted order
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

int *mergeTwoSortedArrayEfficient(int a[], int b[], int m, int n)
{
    int *temp = new int[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
            temp[k++] = a[i++];
        else if (a[i] > b[j])
            temp[k++] = b[j++];
    }

    for (; i < m; i++)
    {
        temp[k++] = a[i];
    }

    for (; j < n; j++)
    {
        temp[k++] = b[j];
    }

    return temp;
}

// follow up:
// ❓ Problem: In-place merge
// You are given two sorted arrays a[] and b[]:

// Array a[] has enough buffer space (extra unused space at the end) to accommodate all elements of array b[].

// Merge b[] into a[] in sorted order, in-place (i.e., no additional array should be created).

void inPlaceMerge(int a[], int m, int b[], int n)
{
    int i = m - 1;     // Last valid element in a[]
    int j = n - 1;     // Last element in b[]
    int k = m + n - 1; // End of buffer space in a[]

    while (i >= 0 && j >= 0)
    {
        if (a[i] >= b[j])
            a[k--] = a[i--]; // Place larger at the end
        else
            a[k--] = b[j--];
    }

    while (j >= 0) // If b[] still has elements
        a[k--] = b[j--];
    // no need for a[] , if elements left in a , it's already there.
}

// follow up: merger two array in sorted order but remove duplicates if any in any of the array.
int *mergeTwoSortedArrayNoDuplicatesEfficient(int a[], int b[], int m, int n)
{
    // Create a new array large enough to hold the merged elements
    int *temp = new int[m + n];

    // i -> index for array a[]
    // j -> index for array b[]
    // k -> index for merged result temp[]
    int i = 0, j = 0, k = 0;

    // Merge elements while both arrays have items left
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            // Add a[i] only if it is not a duplicate of the last inserted element
            if (k == 0 || temp[k - 1] != a[i])
                temp[k++] = a[i];
            i++;
        }
        else if (a[i] > b[j])
        {
            // Add b[j] only if it is not a duplicate of the last inserted element
            if (k == 0 || temp[k - 1] != b[j])
                temp[k++] = b[j];
            j++;
        }
        else
        { // a[i] == b[j]
            // Add either one of them (both are same) if it's not already added
            if (k == 0 || temp[k - 1] != a[i])
                temp[k++] = a[i];
            // Move both pointers to avoid duplicates
            i++;
            j++;
        }
    }

    // Add remaining elements from a[], avoiding duplicates
    while (i < m)
    {
        if (k == 0 || temp[k - 1] != a[i])
            temp[k++] = a[i];
        i++;
    }

    // Add remaining elements from b[], avoiding duplicates
    while (j < n)
    {
        if (k == 0 || temp[k - 1] != b[j])
            temp[k++] = b[j];
        j++;
    }

    // Return the merged array with no duplicates (length is up to k)
    return temp;
}

// Function to merge two sorted subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m;     // Size of right subarray

    // Create temporary arrays for left and right halves
    int left[n1], right[n2];

    // Copy data into left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    // Merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l; // i for left[], j for right[], k for arr[]

    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++]; // Take smaller element
        else
            arr[k++] = right[j++]; // Take element from right
    }

    // Copy remaining elements of left[], if any
    while (i < n1)
        arr[k++] = left[i++];

    // Copy remaining elements of right[], if any
    while (j < n2)
        arr[k++] = right[j++];
}

// we can also do inPlace merge function where we do not need extrea space.
void inPlaceMerging(int arr[], int l, int m, int r) {
    int i = l;
    int j = m + 1;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            i++; // already in correct place
        } else {
            int value = arr[j];
            int index = j;

            // Shift all elements between arr[i] and arr[j-1] to right
            while (index > i) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[i] = value;

            // Update pointers
            i++;
            m++;
            j++;
        }
    }
}


// Recursive merge sort function to sort arr[l..r]
void mergeSort(int arr[], int l, int r)
{
    if (r > l) // ensure atleast 2 element in array
    {
        int mid = l + (r - l) / 2; // Avoids potential overflow -- as same as (l + r) / 2

        // Recursively sort the first and second halves
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        // Merge the two sorted halves
        merge(arr, l, mid, r); // here we can also call inPlaceMerging function to merge two sorted subarrays
    }
}

int main()
{

    int arr[] = {3, 4, 8, -9, 20, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int result = equlibriumPointEfficient(arr, n);
    // cout << result << endl;
    selectionSort(arr, n);
    printArray(arr, n);
    cout << endl;
    return 0;
}