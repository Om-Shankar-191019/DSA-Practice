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

void moveAllZeroNaive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] != 0)
                {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
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

void moveAllZeros2(int arr[], int n)
{
    for (int x = 0; x < n; x++)
    {
        if (arr[x] == 0)
        {
            int k = x;
            for (int i = x + 1; i < n; i++)
            {
                if (arr[i] != 0)
                {
                    swap(arr[k], arr[i]);
                    k++;
                }
            }
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

// Q. minimum consecutive flips required to make all element same in array.
// array contains only zero and one. Also print from where to where flip required.
void minimumConsecutiveFlips(int arr[], int n)
{
    int zeroGroupCount = 0;
    int oneGroupCount = 0;
    if (arr[0] == 0)
        zeroGroupCount++;
    else
        oneGroupCount++;

    for (int i = 1; i < n; i++)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            i++;
        }
        if (arr[i] == 0)
            zeroGroupCount++;
        else
            oneGroupCount++;
    }

    int target;
    if (zeroGroupCount < oneGroupCount)
    {
        target = 0;
    }
    else
    {
        target = 1;
    }

    for (int i = 0; i < n; i++)
    {
        int start;
        int end;
        if (arr[i] == target)
        {
            start = i;
            while (i < n && arr[i] == target)
                i++;
            end = i - 1;

            cout << "From " << start << " to " << end << endl;
        }
    }
}

bool IsequilibriumPoint(int arr[], int n)
{
    if (n == 1)
        return true;
    int prefixSumLR[n];
    int prefixSumRL[n];

    prefixSumLR[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefixSumLR[i] = prefixSumLR[i - 1] + arr[i];

    prefixSumRL[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        prefixSumRL[i] = prefixSumRL[i + 1] + arr[i];

    for (int i = 0; i < n; i++)
    {
        if (i == 0 && prefixSumRL[i + 1] == 0)
            return true;
        if (i == n - 1 && prefixSumLR[i - 1] == 0)
            return true;
        else
        {
            if (prefixSumLR[i - 1] == prefixSumRL[i + 1])
                return true;
        }
    }
    return false;
}

bool IsEquilibriumPoint2(int arr[], int n)
{
    int totalSum = arr[0];
    for (int i = 1; i < n; i++)
    {
        totalSum += arr[i];
    }

    int leftSum = 0;
    for (int i = 0; i < n; i++)
    {
        int rightSum = totalSum - arr[i] - leftSum;
        if (leftSum == rightSum)
            return true;
        leftSum += arr[i];
    }

    return false;
}

int main()
{
    // int arr[] = {3, 4, 8, -9, 20, 6};
    // int arr[] = {false, true};
    int arr[] = {0, 0, 10, 5, 0, 8, 0, 9, 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    moveAllZeros2(arr, n);

    // int result = IsEquilibriumPoint2(arr, n);
    // cout << result << endl;

    printArray(arr, n);

    return 0;
}