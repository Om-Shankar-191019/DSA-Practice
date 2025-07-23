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

int deleteAnElement(int arr[], int n, int ele)
{
    int x, i;
    // search for ele index
    for (i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            x = i;
            break;
        }
    }
    // check if ele not found , reutrn n
    if (i == n)
        return n;

    // shifting remaining elements
    for (int j = i + 1; j < n; j++)
    {
        arr[i++] = arr[j];
    }
    return n - 1;
}

// int deleteMultipleSameElement(int arr[], int n, int ele){
//     int i;
//     for(i = 0;i<n;i++){
//         if(arr[i] == ele)
//         {

//             break;
//         }
//     }

//     if(i == n)
//         return n;

//     for(int j = i ;j<n;j++){
//         if(arr[j] != ele){
//             arr[i++] = arr[j];
//         }
//     }

//     return i;
// }

int deleteMultipleSameElement(int arr[], int n, int ele)
{
    int writeIndex = 0; // Position to write non-matching elements

    // Two-pointer approach: read through entire array
    for (int readIndex = 0; readIndex < n; readIndex++)
    {
        if (arr[readIndex] != ele)
        {
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }

    return writeIndex; // New size after deletion
}

int largestEle(int arr[], int n)
{
    int l = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[l])
            l = i;
    }
    return arr[l];
}

int secondLargestEle(int arr[], int n)
{

    int l = 0;
    int s = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[l])
        {
            s = l;
            l = i;
        }
        else if (arr[i] < arr[l])
        {
            if ((s >= 0 && arr[i] > arr[s]) || s < 0)
                s = i;
        }
    }
    if (s < 0)
        return s;
    return arr[s];
}

bool isAlreadySorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

int nLargestEle(int arr[], int n, int nth)
{
    int res;
    if (n < nth)
        return -1;
    for (int i = 0; i < nth; i++)
    {
        res = largestEle(arr, n);
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == res)
                arr[j] = INT_MIN;
        }
    }
    if (res == INT_MIN)
        return -1;
    return res;
}

// preserve the original array with the same logic above
int nLargestEle2(int arr[], int n, int nth)
{
    if (n < nth)
        return -1;

    // Create a copy
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }

    int res;
    for (int i = 0; i < nth; i++)
    {
        res = largestEle(temp, n);
        for (int j = 0; j < n; j++)
        {
            if (temp[j] == res)
                temp[j] = INT_MIN;
        }
    }

    return (res == INT_MIN) ? -1 : res;
}

int nLargestEleEfficient(int arr[], int n, int nth)
{
    if (n < nth)
        return -1;
    sort(arr, arr + n, greater<int>());
    int count = 1;
    if (nth == 1)
        return arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            count++;
        if (count == nth)
            return arr[i];
    }
    return -1;
}

bool isDescendingSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}

bool isSorted(int arr[], int n)
{
    return isAlreadySorted(arr, n) || isDescendingSorted(arr, n);
}

void reverse(int arr[], int n)
{
    if (arr == NULL || n <= 1)
        return; // Safety check
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - 1 - i]);
    }
}

void reverseUsingSTL(int arr[], int n)
{
    reverse(arr, arr + n);
}

void reverseRecursive(int arr[], int start, int end)
{
    if (start >= end)
        return;
    swap(arr[start], arr[end]);
    reverseRecursive(arr, start + 1, end - 1);
}

void reverseAPortion(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int removeDuplicatesFromSortedArray(int arr[], int n)
{
    if (n <= 1)
        return n; // Handle edge cases
    int i = 0, j = 1;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
        j++;
    }
    return i + 1;
}

// Interview Follow-ups:
// "What if array is not sorted?"
// using same approach - two pointer approach.
int removeDuplicatesFromUnsortedArray(int arr[], int n)
{
    sort(arr, arr + n);
    int i = 0, j = 1;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
        j++;
    }
    return i + 1;
}

// using hashing
int removeDuplicatesFromUnsortedArrayHashing(int arr[], int n)
{
    unordered_set<int> s;
    int i = 0; // Write pointer
    for (int j = 0; j < n; j++)
    { // Read pointer
        if (s.find(arr[j]) == s.end())
        {                      // Element not seen before
            s.insert(arr[j]);  // Mark as seen
            arr[i++] = arr[j]; // Keep this element
        }
    }
    return i; // Return new length
}

// order of remaining element should be same
void moveAllZerosToEnd(int arr[], int n)
{
    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] != 0)
        {
            swap(arr[i++], arr[j]);
        }
        j++;
    }
}

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

// Interview Follow-ups:
// "How would you do right rotation by one?"?
void rightRotateByOne(int arr[], int n)
{
    int temp = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;
}

void leftRotateByK(int arr[], int n, int k)
{
    if (n <= 1)
        return; // Handle edge cases
    k = k % n;  // ✅ Normalize k
    if (k == 0)
        return; // No rotation needed

    for (int i = 0; i < k; i++)
    {
        leftRotateByOne(arr, n);
    }
}

void leftRotateByKUsingReversalAlgo(int arr[], int n, int k)
{
    if (n <= 1)
        return; // Handle edge cases
    k = k % n;  // ✅ Normalize k
    if (k == 0)
        return; // No rotation needed

    reverseAPortion(arr, 0, k - 1);
    reverseAPortion(arr, k, n - 1);
    reverseAPortion(arr, 0, n - 1);
}

//  it working because lf n = 5 then right rotation by one is equivalent to left rotation by ( n - 1 ) .

// Right rotation by k = Left rotation by (n-k)

// This is because rotating right by k positions is equivalent to moving elements k steps clockwise, which is the same as moving them (n-k) steps counterclockwise.
void rightRotateByKUsingLeftRotation(int arr[], int n, int k)
{
    leftRotateByK(arr, n, n - (k % n));
}

void rightRotateByK(int arr[], int n, int k)
{
    if (n <= 1)
        return; // Handle edge cases
    k = k % n;  // ✅ Normalize k
    if (k == 0)
        return; // No rotation needed

    for (int i = 0; i < k; i++)
    {
        rightRotateByOne(arr, n);
    }
}

void leftRotateByKUsingRightRotation(int arr[], int n, int k)
{
    if (n <= 1 || k <= 0)
        return; // Handle edge cases
    k = k % n;  // Normalize k
    if (k == 0)
        return;                    // No rotation needed
    rightRotateByK(arr, n, n - k); // Apply the conversion
}

void rightRotateByKUsingReversalAlgo(int arr[], int n, int k)
{
    if (n <= 1)
        return; // Handle edge cases
    k = k % n;  // ✅ Normalize k
    if (k == 0)
        return; // No rotation needed

    reverseAPortion(arr, 0, n - 1); // ✅ Step 1: Reverse entire array
    reverseAPortion(arr, 0, k - 1); // ✅ Step 2: Reverse first k elements
    reverseAPortion(arr, k, n - 1); // ✅ Step 3: Reverse remaining elements
}

// find leaders in array. A leader is an element where no element is greater than to it's right side.
void leaders(int arr[], int n)
{
    int curr = arr[n - 1];
    cout << curr << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > curr)
        {
            curr = arr[i];
            cout << curr << " ";
        }
    }
}

// find maximum difference ( arr[j] - arr[i] ) when j>i

int maximumDifferenceNaive(int arr[], int n)
{
    if (n < 2)
        return -1;
    int res = arr[1] - arr[0];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] - arr[i] > res)
            {
                res = arr[j] - arr[i];
            }
        }
    }
    return res;
}

int maximumDifferenceEfficient(int arr[], int n)
{
    if (n < 2)
        return -1;
    int currMin = arr[0];
    int res = arr[1] - arr[0];
    for (int j = 1; j < n; j++)
    {
        currMin = min(currMin, arr[j - 1]);
        res = max(res, arr[j] - currMin);
    }
    return res;
}

int minimumSignedDifference(int arr[], int n)
{
    if (n < 2)
        return -1;

    int minDiff = arr[1] - arr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            minDiff = min(minDiff, arr[j] - arr[i]);
        }
    }
    return minDiff;
}

int minimumDifferenceEfficient(int arr[], int n)
{
    if (n < 2)
        return -1;
    int currMax = arr[0];
    int res = arr[1] - arr[0];
    for (int j = 1; j < n; j++)
    {
        currMax = max(currMax, arr[j - 1]);
        res = min(res, arr[j] - currMax);
    }
    return res;
}

// follow up : find minimum absolute difference between two element

int minimumAbsoluteDifference(int arr[], int n)
{
    if (n < 2)
        return -1;

    sort(arr, arr + n); // Sort the array first
    int minDiff = abs(arr[1] - arr[0]);

    for (int i = 1; i < n - 1; i++)
    {
        minDiff = min(minDiff, abs(arr[i + 1] - arr[i]));
    }
    return minDiff;
}

// freq in sorted array
void freqSortedArray(int arr[], int n)
{
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            count++;
        else
        {
            cout << arr[i - 1] << " : " << count << endl;
            count = 1;
        }
    }
    cout << arr[n - 1] << " : " << count << endl;
}

// follow up question : freq in unsorted array
void freqUnsortedArray(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int k = i - 1; k >= 0; k--)
        {
            if (arr[k] == arr[i])
            {
                flag = true;
                break;
            }
        }

        if (flag)
            continue;

        int count = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        cout << arr[i] << " : " << count << endl;
    }
}

void freqUnsortedArray2(int arr[], int n)
{
    sort(arr, arr + n);
    freqSortedArray(arr, n);
}

void freqUnsortedArrayEfficient(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " : " << it->second << endl;
}

// follow up : print in the same order

void freqUnsortedArrayEfficientPrintSameOrder(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    unordered_set<int> printed;
    for (int i = 0; i < n; i++)
    {
        if (printed.find(arr[i]) == printed.end())
        {
            cout << arr[i] << " : " << mp[arr[i]] << endl;
            printed.insert(arr[i]);
        }
    }
}

int stockBuyAndSell(int arr[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += (arr[i] - arr[i - 1]);
        }
    }
    return profit;
}

// follow up : if only one transction is allowed.

int stockBuyAndSellOneNaive(int arr[], int n)
{
    int profit = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int sp = arr[i];
        // for each ele to it's right , find max value as selling price
        for (int j = i + 1; j < n; j++)
        {
            sp = max(sp, arr[j]);
        }
        profit = max(profit, sp - arr[i]);
    }
    return profit;
}

// if single transction allowed :
// Track min-price-so-far as you traverse, and at each price compute profit if sold today.
int stockBuyAndSellOneEfficient(int arr[], int n)
{
    if (n < 2)
        return 0;
    int currMin = arr[0];
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        int currProfit = max(0, arr[i] - currMin);
        profit = max(profit, currProfit);
        currMin = min(currMin, arr[i]);
    }
    return profit;
}

int maxProfitAtMostTwoTransactions(int arr[], int n)
{
    // try undestanding later on
    return 0;
}

int trappingRainWaterNaive(int arr[], int n)
{
    if (n < 3)
        return 0;
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int leftMax = arr[i];
        for (int k = i - 1; k >= 0; k--)
            leftMax = max(leftMax, arr[k]);

        int rightMax = arr[i];
        for (int k = i + 1; k < n; k++)
            rightMax = max(rightMax, arr[k]);

        int water = min(leftMax, rightMax) - arr[i];
        if (water > 0)
            res += water;
    }
    return res;
}

int tappingRainWaterEfficient(int arr[], int n)
{
    if (n < 3)
        return 0;
    int res = 0;
    int leftMax = arr[0];
    int rightMax[n];

    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], arr[i]);

    for (int i = 1; i < n - 1; i++)
    {
        leftMax = max(leftMax, arr[i - 1]);
        // here please use rightMax[i] only and not rightMax[i+1] . though correct but not recommended.
        int water = min(leftMax, rightMax[i]) - arr[i];
        if (water > 0)
            res += water;
    }
    return res;
}

// follow up :
int containerWithMostWaterNaive(int arr[], int n)
{
    // solve first
    return 0;
}

// return maximum consecutive ones where array has only 0 & 1.
int maxConsecutiveOnes(int arr[], int n)
{
    int res = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            count++;
        else
        {
            res = max(res, count);
            count = 0;
        }
    }
    res = max(res, count);
    return res;
}

int maxConsecutiveOnes2(int arr[], int n)
{
    int res = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count = 0;
        else
        {
            count++;
            res = max(res, count);
        }
    }
    return res;
}

int maxSubArraySumNaive(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            res = max(res, sum);
        }
    }
    return res;
}

int maxSubArraySumEfficient(int arr[], int n)
{
    int res = arr[0];  // keeps track of the overall maximum.
    int prev = arr[0]; // keeps the maximum subarray sum ending at current index.
    for (int i = 1; i < n; i++)
    {
        prev = max(prev + arr[i], arr[i]);
        res = max(res, prev);
    }
    return res;
}

bool isEven(int num)
{
    if (num % 2 == 0)
        return true;
    return false;
}

bool isOdd(int num)
{
    if (num % 2 != 0)
        return true;
    return false;
}

int maxLengthAlternatingOddEvenSubarrayNaive(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((isEven(arr[j]) && isOdd(arr[j - 1])) || (isEven(arr[j - 1]) && isOdd(arr[j])))
                count++;
            else
                break;
        }
        res = max(res, count);
    }
    return res;
}

int maxLengthAlternatingOddEvenSubarrayEfficient(int arr[], int n)
{
    int res = 1;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if ((isEven(arr[i]) && isOdd(arr[i - 1])) || (isEven(arr[i - 1]) && isOdd(arr[i])))
        {
            count++;
            res = max(res, count);
        }
        else
            count = 1;
    }
    return res;
}

// 🔁 Follow-up Questions:
// Can you return the subarray itself, not just the length?

// What if we allow only subarrays starting with an odd number?

// Can you handle arrays where only even-odd or only odd-even sequences are allowed?

// How would you solve this if array elements were not integers (e.g., floats)?

int maxSubArraySumCircularNaive(int arr[], int n)
{
    int res = arr[0]; // Initialize result with first element
    for (int i = 0; i < n; i++)
    { // Start index of subarray
        int sum = 0;
        int j = i;
        int t = n; // Max subarray length is n (circular)
        // here instead of for loop while loop is used using t var , it is just to iterate n times . And j start from i and goes n times to index var go circularly.
        while (t--)
        {
            int index = j % n; // Wrap around using modulo
            j++;
            sum += arr[index];   // Add element to sum
            res = max(res, sum); // Update result
        }
    }
    return res;
}

int minSubArraySumEfficient(int arr[], int n)
{
    int res = arr[0];
    int prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        prev = min(prev + arr[i], arr[i]);
        res = min(prev, res);
    }
    return res;
}

// logic : get Max(mx normal subArr sum , mx circular subArr sum) and to get mx circualr subArr : ( total - minSubArr sum) Also must handle edge case if(maxSubArrNormal < 0 )

int maxSubArraySumCircularEfficient(int arr[], int n)
{
    int maxSubArrNormal = maxSubArraySumEfficient(arr, n);
    if (maxSubArrNormal < 0)
        return maxSubArrNormal;

    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    int minSubArrSum = minSubArraySumEfficient(arr, n);
    int maxSubArrCircular = totalSum - minSubArrSum;
    return max(maxSubArrNormal, maxSubArrCircular);
}

// 🚀 Follow-up Interview Questions
// Q: Why do we subtract the min subarray from the total?

// A: Because subtracting the minimum contiguous part effectively gives the maximum sum of the complementary circular subarray.

// Q: What happens if all elements are negative?

// A: Then total - min = 0 (invalid), so we just return the maximum element using normal Kadane’s.

// Q: Can this approach be extended to 2D arrays?

// A: Yes, but it’s significantly more complex and involves reducing the 2D problem to multiple 1D Kadane's problems.

// find index of majority element (any index). which appears more than n/2 times.
int majorityElementNaive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0; // Reset count for each i
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > n / 2)
            return i; // Return any index of the majority element
    }
    return -1; // No majority element found
}

int majorityElementEfficient(int arr[], int n)
{
    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[res])
            count++;
        else
        {
            count--;
            if (count == 0)
            {
                res = i;
                count = 1;
            }
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[res])
            count++;
    }
    if (count > n / 2)
        return res;
    return -1;
}

// print the indices for finding minimum consecutive flips in a binary array.
void minimumConsecutiveFlips(int arr[], int n)
{
    int target = arr[0] == 1 ? 0 : 1; // Set target to the opposite of the first element
    int start = -1;                   // Initialize start and end indices
    int end = -1;                     // Initialize end index
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == target)
        {
            if (start == -1)
                start = end = i;
            else
                end = i;
        }
        else
        {
            if (start != -1) // If we have a segment to print
                cout << "From " << start << "to " << end << endl;
            start = end = -1;
        }
    }
    if (start != -1) // Handle the last segment
        cout << "From " << start << " to " << end << endl;
}

void minimumConsecutiveFlips2(int arr[], int n)
{
    int target = arr[0] == 1 ? 0 : 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == target)
        {
            int start = i;
            while (i < n && arr[i] == target)
                i++;
            int end = i - 1;
            cout << "From " << start << " to " << end << endl;
        }
    }
}

// return the count of minimum consecutive flips
int minimumConsecutiveFlipsCount(int arr[], int n)
{
    int target = arr[0] == 1 ? 0 : 1;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == target)
        {
            count++;
            while (i < n && arr[i] == target)
                i++;
        }
    }
    return count;
}

// given an array of integers and a number k, find the max sum of k consecutive elements.

int slidingWindowNaive(int arr[], int n, int k)
{
    if (k > n)
        return -1;
    int res = INT_MIN;

    for (int i = 0; i < n - k + 1; i++) // Iterate through all possible starting indices
    {
        int sum = 0;
        for (int j = i; j < k + i; j++) // Calculate sum of k elements starting from i
            sum += arr[j];
        res = max(res, sum);
    }
    return res;
}

int slidingWindow(int arr[], int n, int k)
{
    if (k > n)
        return -1;

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];

    int res = sum;

    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k]; // Slide the window
        res = max(res, sum);
    }

    return res;
}

//** given an array of non-negative integers find if there is an subarray of given sum
bool isGivenSumExistNaive(int arr[], int n, int givenSum)
{

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == givenSum)
                return true;
        }
    }
    return false;
}

bool isGivenSumExistEfficient(int arr[], int n, int givenSum)
{
    int start = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == givenSum)
            return true;
        else if (sum > givenSum)
        {

            while (start <= i && sum > givenSum)
            {
                sum -= arr[start];
                start++;
            }
            if (sum == givenSum)
                return true;
        }
    }
    return false;
}

bool isGivenSumExistEfficientMoreCleaner(int arr[], int n, int givenSum)
{
    int start = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        while (sum > givenSum && start <= i)
        {
            sum -= arr[start];
            start++;
        }

        if (sum == givenSum)
            return true;
    }

    return false;
}

bool isGivenSumExistEfficientMoreCleaner2(int arr[], int n, int givenSum)
{
    int start = 0;
    int sum = arr[0];
    int i = 1;

    while (i <= n)
    {
        if (sum == givenSum)
            return true;
        else if (sum < givenSum && i < n)
            sum += arr[i++];
        else
            sum -= arr[start++];
    }

    return false;
}

// follow up : Version That Also Prints the Subarray
bool isGivenSumExistEfficientWithPrint(int arr[], int n, int givenSum)
{
    int start = 0, sum = arr[0], i = 1;

    while (i <= n)
    {
        if (sum == givenSum)
        {
            cout << "Subarray from index " << start << " to " << i - 1 << endl;
            return true;
        }
        else if (sum < givenSum && i < n)
            sum += arr[i++];
        else
            sum -= arr[start++];
    }

    return false;
}

// follow up : if the given array includes negative integers

// find equilibrium point : if sum of elements to it's left and right are same then that index is equlibrium point. return true or false .
bool equlibriumPointNaive(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            left += arr[j];
        }
        for (int j = i + 1; j < n; j++)
        {
            right += arr[j];
        }
        if (left == right)
            return true;
    }
    return false;
}

bool equlibriumPointEfficient(int arr[], int n)
{
    int left = 0, right = 0;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        right = total - (left + arr[i]);
        if (left == right)
            return true;
        left += arr[i];
    }
    return false;
}

// Follow-Up Interview Questions and All Types of Solutions
// Q1. Can you return the index of the equilibrium point?
// Naive Version: Just return i; instead of true
// Efficient Version: Same; just update return value.

// Q2. What if there are multiple equilibrium points?
// Return all indices:
// Store in a vector and return; or return count.

// Q3. How would you optimize space if allowed to use O(n) extra memory?
// Prefix Sum Approach:
// Precompute prefix sums for O(1) leftSum, rightSum calculation; though in this specific problem, current O(1) space is already optimal.

// Q4. What if the array is circular?
// You can concatenate the sums accordingly and handle mod n indexing, or simulate sum-wrapping.

// Q5. What if you are to minimize the absolute difference of left and right sum?
// Scan and track the minimum such difference.

// Q6. How do you extend this to the case where elements can be very large or negative?
// No issue; algorithm works since it's purely summing.

int main()
{

    int arr[] = {3, 4, 8, -9, 20, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = equlibriumPointEfficient(arr, n);
    cout << result << endl;
    // freqUnsortedArrayEfficientPrintSameOrder(arr,n);
    // printArray(arr, n);
    cout << endl;
    return 0;
}