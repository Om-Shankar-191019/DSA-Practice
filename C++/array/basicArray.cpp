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

int secondLargest2(int arr[], int n)
{
    int result = -1;
    int large = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[large])
        {
            result = large;
            large = i;
        }
        else if (arr[i] < arr[large])
            if (result == -1 || arr[i] > arr[result])
                result = i;
    }
    return result;
}

// remove duplicates from sorted array (efficient)
int removeSortedDuplicates(int arr[], int n)
{
    int firstPointer = 0;
    int secondPointer = 1;
    while (secondPointer < n)
    {
        if (arr[firstPointer] == arr[secondPointer])
        {
            secondPointer++;
        }
        else
        {
            firstPointer++;
            arr[firstPointer] = arr[secondPointer];
            secondPointer++;
        }
    }
    return firstPointer + 1;
}

// move all zeros to the end (efficient) -- two pointer
void moveAllZeros(int arr[], int n)
{
    int i, j;
    i = j = 0;
    while (j < n)
    {
        if (arr[j] != 0)
        {
            // arr[i] = arr[j];
            // if (i != j)
            // {
            //     arr[j] = 0;
            // }
            // i++;
            // j++;

            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
}

void freqInSortedArray(int arr[], int n)
{
    int currCompare = arr[0];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == currCompare)
            count++;
        else
        {
            cout << arr[i - 1] << " : " << count << endl;
            count = 1;
            currCompare = arr[i];
        }
    }
    cout << arr[n - 1] << " : " << count << endl;
}

int tappingRainWaterNaive(int arr[], int n)
{
    int result = 0;
    int gl = arr[0];
    int gr = arr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > gl)
        {
            gl = arr[i];
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > gr)
            {
                gr = arr[j];
            }
        }

        if (arr[i] > gr)
        {
            continue;
        }
        result += min(gl, gr) - arr[i];
    }

    return result;
}

int maximumConsecutiveOnes(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            int count = 0;
            while (i < n && arr[i] == 1)
            {
                count++;
                i++;
            }
            result = max(result, count);
        }
    }
    return result;
}

int IsSubArrayOfGivenSum(int arr[], int n, int sum)
{
    int k = 0;
    int curr_sum = arr[0];
    int i = 1;
    while (i < n)
    {
        if (curr_sum < sum)
            curr_sum += arr[i++];
        else if (curr_sum > sum)
            curr_sum -= arr[k++];
        else
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5};
    // int arr[] = {1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    // printArray(arr, n);

    int result = IsSubArrayOfGivenSum(arr, n, 33);
    cout << result << endl;

    printArray(arr, n);

    return 0;
}