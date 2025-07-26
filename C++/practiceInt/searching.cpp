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

// we can use binary search algo when arr is sorted or when we know that we can skip one halp of the array.

// Function to perform Binary Search on a sorted array
// Returns the index of 'target' if found, else returns -1
int binarySearch(int arr[], int n, int target)
{
    int l = 0, h = n - 1; // Initialize low and high pointers

    while (l <= h)
    {
        // Prevents overflow compared to (l + h) / 2
        int mid = l + (h - l) / 2;

        if (arr[mid] == target)
        {
            // Target found at index mid
            return mid;
        }
        else if (target > arr[mid])
        {
            // Search in right half
            l = mid + 1;
        }
        else
        {
            // Search in left half
            h = mid - 1;
        }
    }

    // Target not found
    return -1;
}
int binarySearchRecursive(int arr[], int l, int h, int target)
{
    if (l > h)
        return -1; // Base case: target not found

    int mid = l + (h - l) / 2; // Safe way to calculate mid to avoid overflow

    if (arr[mid] == target)
        return mid; // Target found
    else if (target > arr[mid])
        return binarySearchRecursive(arr, mid + 1, h, target); // Search right half
    else
        return binarySearchRecursive(arr, l, mid - 1, target); // Search left half
}

// Function to find the index of the first occurrence of 'target' in a sorted array
int firstOccurance(int arr[], int n, int target)
{
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2; // Avoid overflow

        if (target > arr[mid])
        {
            l = mid + 1; // Move to the right half
        }
        else if (target < arr[mid])
        {
            h = mid - 1; // Move to the left half
        }
        else
        {
            // Element found, check if it's the first occurrence
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid; // First occurrence found
            else
                h = mid - 1; // Keep searching in the left half
        }
    }

    return -1; // Target not found
}

int lastOccurance(int arr[], int n, int target)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (target > arr[mid])
            l = mid + 1;
        else if (target < arr[mid])
            h = mid - 1;
        else
        {
            if (mid == n - 1 || arr[mid] != arr[mid + 1])
                return mid;
            else
                l = mid + 1;
        }
    }
    return -1;
}

// count occurances in sorted array
int countOccurance(int arr[], int n, int target)
{
    int firstOcc = firstOccurance(arr, n, target);
    if (firstOcc == -1)
        return 0;
    int lastOcc = lastOccurance(arr, n, target);
    return (lastOcc - firstOcc + 1);
}

// count one in sorted binary array
int countOneInBinary(int arr[], int n)
{
    int target = 1;
    int firstOcc = firstOccurance(arr, n, target);
    if (firstOcc == -1)
        return 0;
    return (n - firstOcc);
}

// Get square root of a number n. If n is not a perfect square, return the floor of sqrt(n)
// Naive approach to find square root of a number.
// If the number is not a perfect square, return the floor of the square root.
int sqRootNaive(int n)
{
    if (n == 0 || n == 1)
        return n; // √0 = 0, √1 = 1 — edge cases

    int res = 1;
    // Try all numbers starting from 2 and check their square
    for (int i = 2; i * i <= n; i++)
    {
        if (i * i == n)
            return i; // Exact square root found
        else if (i * i < n)
            res = i; // Store the last valid i whose square is less than n
        else
            break; // Exit if square exceeds n
    }

    // If perfect square is not found, return the floor of the square root
    return res;
}

// Efficiently find the square root of a number n.
// If n is not a perfect square, return the floor of its square root.
int sqRootEfficient(int n)
{
    int l = 0, h = n;
    int res = 0;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        // If mid*mid is exactly n, mid is the square root
        if (mid * mid == n)
            return mid;

        // If mid*mid is less than n, store mid as possible result and search in right half
        else if (mid * mid < n)
        {
            res = mid;
            l = mid + 1;
        }

        // If mid*mid is more than n, search in left half
        else
            h = mid - 1;
    }

    // When no exact square root is found, return the floor value stored in res
    return res;
}

int binarySearch2(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int searchInInfiniteArray(int arr[], int target)
{
    if (arr[0] == target)
        return 0;
    int i = 1;
    while (arr[i] < target)
        i = i * 2;
    if (arr[i] == target)
        return i;
    return binarySearch2(arr, i / 2 + 1, i - 1, target);
}

// Function to search for a target in a sorted and rotated array
int searchInSortedRotatedArray(int arr[], int n, int target)
{
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        // If the element is found at mid
        if (arr[mid] == target)
            return mid;

        // Check if the left half is sorted
        if (arr[l] <= arr[mid])
        {
            // Check if target lies within the left half
            if (target >= arr[l] && target < arr[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        // Otherwise, the right half must be sorted
        else
        {
            // Check if target lies within the right half
            if (target > arr[mid] && target <= arr[h])
                l = mid + 1;
            else
                h = mid - 1;
        }
    }

    // If not found
    return -1;
}

// the above code fails for duplicate values. arr = [2, 2, 2, 3, 4, 2], target = 3 → returns -1 (incorrect)

// follow up : what if arr contains duplicate elements
int searchInSortedRotatedDuplicatedArray(int arr[], int n, int target)
{
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == target)
            return mid;

        // Handle duplicates: shrink bounds
        if (arr[l] == arr[mid] && arr[h] == arr[mid])
        {
            l++;
            h--;
        }
        // Left half is sorted
        else if (arr[l] <= arr[mid])
        {
            if (target >= arr[l] && target < arr[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        // Right half is sorted
        else
        {
            if (target > arr[mid] && target <= arr[h])
                l = mid + 1;
            else
                h = mid - 1;
        }
    }

    return -1;
}

// Q3. How to find the rotation point (minimum element)?
// cpp
// int findRotationPoint(int arr[], int n) {
//     int l = 0, h = n - 1;

//     while(l < h) {
//         int mid = l + (h - l) / 2;

//         if(arr[mid] > arr[h]) {
//             l = mid + 1;  // Minimum is in right half
//         } else {
//             h = mid;      // Minimum is in left half or at mid
//         }
//     }
//     return l;
// }
// Q4. How to find if array is rotated?
// cpp
// bool isRotated(int arr[], int n) {
//     if(n <= 1) return false;
//     return arr[0] > arr[n-1];
// }
// Q5. Search for range of target (first and last occurrence)?
// cpp
// pair<int,int> searchRange(int arr[], int n, int target) {
//     int first = searchFirstOccurrence(arr, n, target);
//     if(first == -1) return {-1, -1};
//     int last = searchLastOccurrence(arr, n, target);
//     return {first, last};
// }

// int searchFirstOccurrence(int arr[], int n, int target) {
//     int l = 0, h = n - 1, result = -1;

//     while(l <= h) {
//         int mid = l + (h - l) / 2;

//         if(arr[mid] == target) {
//             result = mid;
//             h = mid - 1;  // Continue searching left
//         }
//         else if((arr[l] <= arr[mid] && target >= arr[l] && target < arr[mid]) ||
//                 (arr[mid] <= arr[h] && !(target > arr[mid] && target <= arr[h]))) {
//             h = mid - 1;
//         }
//         else {
//             l = mid + 1;
//         }
//     }
//     return result;
// }
// Q6. What if we need to search in 2D rotated matrix?
// cpp
// bool searchMatrix2D(vector<vector<int>>& matrix, int target) {
//     if(matrix.empty() || matrix[0].empty()) return false;

//     int m = matrix.size(), n = matrix[0].size();
//     int row = 0, col = n - 1;

//     while(row < m && col >= 0) {
//         if(matrix[row][col] == target) return true;
//         else if(matrix[row][col] > target) col--;
//         else row++;
//     }
//     return false;
// }
// Q7. How to handle multiple rotations?
// For multiple rotations, the array essentially becomes unsorted, so binary search won't work efficiently. You'd need:

// Linear search: O(n)

// Or use additional data structures like hash maps

// Advanced Follow-ups
// Q8. Can you do this recursively?
// cpp
// int searchRotatedRecursive(int arr[], int l, int h, int target) {
//     if(l > h) return -1;

//     int mid = l + (h - l) / 2;
//     if(arr[mid] == target) return mid;

//     if(arr[l] <= arr[mid]) {
//         if(target >= arr[l] && target < arr[mid])
//             return searchRotatedRecursive(arr, l, mid-1, target);
//         return searchRotatedRecursive(arr, mid+1, h, target);
//     }

//     if(target > arr[mid] && target <= arr[h])
//         return searchRotatedRecursive(arr, mid+1, h, target);
//     return searchRotatedRecursive(arr, l, mid-1, target);
// }
// Q9. What's the pattern recognition approach?
// The key insight is that in a rotated sorted array:

// At least one half is always sorted

// Determine which half is sorted, then check if target lies in that range

// If yes, search that half; otherwise search the other half

// Function to find a peak element in an array
// A peak element is one that is not smaller than its neighbors
// logic used here  :  we can use binary search algo when arr is sorted or when we know that we can skip one halp of the array.
int peakElementNaive(int arr[], int n)
{
    if (n == 1)
        return 0;

    // Check first element
    if (arr[0] >= arr[1])
        return 0;

    // Check middle elements
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }

    // Check last element
    if (arr[n - 1] >= arr[n - 2])
        return n - 1;

    return -1; // Should never reach here
}

int peakElement(int arr[], int n)
{
    // If there's only one element, it's the peak
    if (n == 1)
        return 0;

    // Check if the first element is a peak
    if (arr[0] >= arr[1])
        return 0;

    // Check if the last element is a peak
    if (arr[n - 1] >= arr[n - 2])
        return n - 1;

    // Binary search in the middle of the array
    int l = 1, h = n - 2; // Avoid checking boundary elements again

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        // If mid is a peak
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
            return mid;

        // If the left neighbor is greater, the peak must be on the left
        else if (arr[mid - 1] > arr[mid])
            h = mid - 1;

        // Otherwise, the peak must be on the right
        else
            l = mid + 1;
    }

    // Should never reach here if input constraints are valid
    return -1;
}

int peakElement2(int arr[], int n)
{

    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
            return mid;
        else if (mid > 0 && arr[mid - 1] >= arr[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// Follow-Up Questions & Solutions
// Q1. What's the naive approach?
// Linear Search:

// cpp
// int peakElementNaive(int arr[], int n) {
//     if(n == 1) return 0;

//     // Check first element
//     if(arr[0] >= arr[1]) return 0;

//     // Check middle elements
//     for(int i = 1; i < n-1; i++) {
//         if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1])
//             return i;
//     }

//     // Check last element
//     if(arr[n-1] >= arr[n-2]) return n-1;

//     return -1; // Should never reach here
// }
// Time: O(n), Space: O(1)

// When to use: Very small arrays

// Q2. How to find ALL peak elements?
// cpp
// vector<int> findAllPeaks(int arr[], int n) {
//     vector<int> peaks;

//     if(n == 1) {
//         peaks.push_back(0);
//         return peaks;
//     }

//     // Check first element
//     if(arr[0] >= arr[1]) peaks.push_back(0);

//     // Check middle elements
//     for(int i = 1; i < n-1; i++) {
//         if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1])
//             peaks.push_back(i);
//     }

//     // Check last element
//     if(arr[n-1] >= arr[n-2]) peaks.push_back(n-1);

//     return peaks;
// }
// Time: O(n), Space: O(k) where k is number of peaks

// Q3. What if we want the MAXIMUM peak element?
// cpp
// int findMaxPeak(int arr[], int n) {
//     vector<int> allPeaks = findAllPeaks(arr, n);
//     int maxPeakIndex = allPeaks[0];

//     for(int peak : allPeaks) {
//         if(arr[peak] > arr[maxPeakIndex]) {
//             maxPeakIndex = peak;
//         }
//     }
//     return maxPeakIndex;
// }
// Q4. How to find peak in 2D array (2D Peak)?
// cpp
// int findPeak2D(int arr[][COL], int rows, int cols) {
//     int mid = cols / 2;

//     // Find max element in middle column
//     int maxRow = 0;
//     for(int i = 1; i < rows; i++) {
//         if(arr[i][mid] > arr[maxRow][mid])
//             maxRow = i;
//     }

//     // Check if it's a peak
//     bool leftSmaller = (mid == 0) || (arr[maxRow][mid] >= arr[maxRow][mid-1]);
//     bool rightSmaller = (mid == cols-1) || (arr[maxRow][mid] >= arr[maxRow][mid+1]);

//     if(leftSmaller && rightSmaller)
//         return maxRow * cols + mid; // Convert to 1D index

//     // Recursively search the side with larger neighbor
//     if(!leftSmaller)
//         return findPeak2D(arr, rows, mid); // Search left half
//     else
//         return findPeak2D(arr + mid + 1, rows, cols - mid - 1); // Search right half
// }
// Q5. Find peak with duplicates efficiently?
// Your current solution already handles duplicates correctly! The >= comparisons ensure that equal elements can form valid peaks.

// Q6. What if array is circular?
// cpp
// int peakElementCircular(int arr[], int n) {
//     if(n == 1) return 0;

//     for(int i = 0; i < n; i++) {
//         int prev = (i - 1 + n) % n;
//         int next = (i + 1) % n;

//         if(arr[i] >= arr[prev] && arr[i] >= arr[next])
//             return i;
//     }
//     return -1;
// }
// Q7. Recursive binary search version?
// cpp
// int peakElementRecursive(int arr[], int l, int h, int n) {
//     if(l == h) return l;

//     int mid = l + (h - l) / 2;

//     // Check if mid is peak
//     if((mid == 0 || arr[mid] >= arr[mid-1]) &&
//       (mid == n-1 || arr[mid] >= arr[mid+1]))
//         return mid;

//     // Move toward larger neighbor
//     if(mid > 0 && arr[mid-1] > arr[mid])
//         return peakElementRecursive(arr, l, mid-1, n);
//     else
//         return peakElementRecursive(arr, mid+1, h, n);
// }
// Q8. Why does the binary search approach always work?
// Mathematical Proof:

// Base case: Single element is always a peak

// Inductive step: In any subarray, if we're at position i:

// If arr[i-1] > arr[i], then left side must contain a peak

// If arr[i+1] > arr[i], then right side must contain a peak

// If both neighbors are ≤ arr[i], then i itself is a peak

// Key insight: We always move toward a "higher" region, guaranteeing a peak exists.

// Comparison Table
// Approach	Time	Space	Finds	Best For
// Your Binary Search	O(log n)	O(1)	One peak	Large arrays, optimal
// Naive Linear	O(n)	O(1)	One peak	Small arrays
// Find All Peaks	O(n)	O(k)	All peaks	When all peaks needed
// 2D Peak	O(cols × log rows)	O(log rows)	2D peak	Matrix problems
// Recursive Binary	O(log n)	O(log n)	One peak	When recursion preferred
// Advanced Follow-ups
// Q9. Peak element in rotated sorted array?
// cpp
// int peakInRotatedArray(int arr[], int n) {
//     // First find rotation point
//     int rotationPoint = findRotationPoint(arr, n);

//     // The element just before rotation point is a peak
//     // (largest element in original sorted array)
//     return (rotationPoint == 0) ? n-1 : rotationPoint-1;
// }
// Q10. Peak element with range queries?
// Use Segment Tree or Sparse Table for multiple peak queries on static arrays.

// Edge Cases Handled
// ✅ Single element: Returns index 0
// ✅ Two elements: Finds the larger one
// ✅ Peak at boundaries: Proper boundary checks
// ✅ All equal: Any element is valid peak
// ✅ Multiple peaks: Finds one efficiently
// ✅ Decreasing/Increasing arrays: Finds end peaks

// Code Style Analysis
// Your implementation is clean and follows best practices:

// ✅ Proper overflow prevention: l + (h-l)/2

// ✅ Correct boundary conditions

// ✅ Efficient binary search logic

// ✅ Clear conditional structure

// Minor Enhancement Suggestion
// cpp
// int peakElementRobust(int arr[], int n) {
//     if(n == 0) return -1;  // Handle empty array
//     if(n == 1) return 0;   // Single element optimization

//     int l = 0, h = n - 1;

//     while(l <= h) {
//         int mid = l + (h - l) / 2;

//         bool leftOk = (mid == 0) || (arr[mid] >= arr[mid-1]);
//         bool rightOk = (mid == n-1) || (arr[mid] >= arr[mid+1]);

//         if(leftOk && rightOk) return mid;

//         if(mid > 0 && arr[mid-1] > arr[mid])
//             h = mid - 1;
//         else
//             l = mid + 1;
//     }

//     return -1; // Should never reach here
// }
// Verdict
// Your implementation is excellent and optimal!

// ✅ Perfect algorithm: Correctly implements binary search for peak finding
// ✅ Optimal complexity: O(log n) time, O(1) space
// ✅ Robust boundary handling: Proper edge case management
// ✅ Clean code: Well-structured and readable
// ✅ Interview-ready: Exactly what interviewers expect

// This is the standard solution for the classic "Find Peak Element" problem. Be prepared to explain why the binary search approach always works and discuss variants like finding all peaks or 2D peaks! 🎯

// two pointer approach :
// find if there is a pair whose sum equals to x.
bool isPairNaive(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == x)
                return true;
    }
    return false;
}

// using two pointer : works only if arr is sorted.
bool isPairEfficientTwoPointer(int arr[], int n, int x)
{
    sort(arr, arr + n);
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == x)
            return true;
        else if (arr[left] + arr[right] > x)
            right--;
        else
            left++;
    }
    return false;
}

bool isPairEfficientHashing(int arr[], int n, int x)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(x - arr[i]) != s.end())
            return true;
        else
            s.insert(arr[i]);
    }
    return false;
}

// Follow-Up Interview Questions

// Q1) Return the actual pair of indices (or values), not just true/false.
// Naive: when you find arr[i]+arr[j]==x, return {i,j}.
// Two-pointer: sort value–index pairs first, then scan; map back to original indices.
// Hashing: use unordered_map<int,int> to store value→index; when you see x-arr[i] in map, return {map[x-arr[i]], i}.

// Q2) Find all unique pairs that sum to x.
// Naive: nested loops, collect pairs in a set to avoid duplicates.
// Two-pointer (sorted): advance left/right pointers, when you find a match push it, then skip over duplicates on both sides. O(n).
// Hashing: iterate, for each arr[i], if (x-arr[i]) in set and you haven’t emitted that pair before (use a set of seen values), collect it.

// Q3) Count number of pairs with sum = x.
// Naive: nested loops and an integer counter. O(n²).
// Two-pointer: after sorting, move pointers inward—when arr[l]+arr[r]==x, if arr[l]==arr[r], count += C(r-l+1,2) and break; else count += (# duplicates at l)×(# duplicates at r), move both. O(n).
// Hashing: build frequency map; for each unique value v, if (x−v) exists, add freq[v]×freq[x−v]; adjust for v==x−v by adding C(freq[v],2). O(n).
int countPairEfficientHashing(int arr[], int n, int x)
{
    unordered_set<int> s;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.find(x - arr[i]) != s.end())
            count++;
        else
            s.insert(arr[i]);
    }
    return count;
}

// Q4) Find the pair whose sum is closest to x.
// Naive: nested loops tracking min |sum−x|. O(n²).
// Two-pointer: sort and scan from ends, keep track of the best. O(n log n).
// Optimal: same two-pointer—this is already optimal.

// Q5) Generalize to k-sum (find k elements summing to x).
// Naive: k nested loops, O(nᵏ).
// Efficient: sort + recursive reduction to two-sum at the leaf: O(n^{k−1}).
// Optimal (for k=3): O(n²), the best known for 3-sum. For k=4: O(n³), etc.

// Q6) Multiple queries: you receive lots of x’s to test on the same array.
// Naive: for each query run Naive O(n²).
// Two-pointer: sort once O(n log n), then each query is O(n).
// Hashing: build a hash set once O(n), each query is O(n) to scan (unless you store all possible sums in a bitset or hash—O(n²) precompute, then O(1) per query).

// Q7) Streaming input: elements arrive one by one, can you detect when a pair summing to x exists?
// Naive: store all seen, each new element scans old list O(n).
// Hashing (online): for each incoming a, check if (x−a) in set, else insert a. O(1) per element, O(n) space.

// Summary of Trade-offs

// Naive is easy but only OK for n ≲ 10⁴.

// Two-pointer is O(n log n) & O(1) space—great if you can sort or array is already sorted.

// Hashing is O(n) & O(n) space—best for one-time checks on unsorted data.

// find if there is a triplet with given sum.
bool isTripletNaive(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
                if (arr[i] + arr[j] + arr[k] == x)
                    return true;
        }
    }
    return false;
}

bool isPairForTriplet(int arr[], int left, int right, int sum)
{
    while (left < right)
    {
        if (arr[left] + arr[right] == sum)
            return true;
        else if (arr[left] + arr[right] > sum)
            right--;
        else
            left++;
    }
    return false;
}

bool isTripletEfficient(int arr[], int n, int x)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (isPairForTriplet(arr, i + 1, n - 1, x - arr[i]))
            return true;
    }
    return false;
}

bool isTripletEfficientHashing(int arr[], int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> s; // new, empty set for each i
        int sum = x - arr[i]; // remaining sum to find in pair
        for (int j = i + 1; j < n; j++)
        {
            if (s.find(sum - arr[j]) != s.end())
                return true;
            else
                s.insert(arr[j]);
        }
    }
    return false;
}

// follow up : from notes :
// count pairs and triplets with given sum
// find if there is a triplet such that ( a^2+b^2 = c^2)

// 3. Follow-Up Interview Questions & Solutions
// Q1. How would you return the actual triplet values/indices?
// Naive Version:

// cpp
// vector<int> findTripletNaive(int arr[], int n, int x) {
//     for(int i = 0; i < n; i++) {
//         for(int j = i+1; j < n; j++) {
//             for(int k = j+1; k < n; k++) {
//                 if(arr[i] + arr[j] + arr[k] == x)
//                     return {arr[i], arr[j], arr[k]};
//             }
//         }
//     }
//     return {}; // Empty if not found
// }
// Efficient Two-Pointer Version:

// cpp
// vector<int> findTripletEfficient(int arr[], int n, int x) {
//     sort(arr, arr + n);
//     for(int i = 0; i < n-2; i++) {
//         int left = i + 1, right = n - 1;
//         while(left < right) {
//             int sum = arr[i] + arr[left] + arr[right];
//             if(sum == x)
//                 return {arr[i], arr[left], arr[right]};
//             else if(sum < x)
//                 left++;
//             else
//                 right--;
//         }
//     }
//     return {};
// }
// Q2. Find ALL unique triplets with given sum?
// cpp
// vector<vector<int>> findAllTriplets(int arr[], int n, int x) {
//     vector<vector<int>> result;
//     sort(arr, arr + n);

//     for(int i = 0; i < n-2; i++) {
//         // Skip duplicates for first element
//         if(i > 0 && arr[i] == arr[i-1]) continue;

//         int left = i + 1, right = n - 1;
//         while(left < right) {
//             int sum = arr[i] + arr[left] + arr[right];
//             if(sum == x) {
//                 result.push_back({arr[i], arr[left], arr[right]});

//                 // Skip duplicates
//                 while(left < right && arr[left] == arr[left+1]) left++;
//                 while(left < right && arr[right] == arr[right-1]) right--;

//                 left++;
//                 right--;
//             }
//             else if(sum < x) left++;
//             else right--;
//         }
//     }
//     return result;
// }
// Q3. Count number of triplets with given sum?
// cpp
// int countTripletsWithSum(int arr[], int n, int x) {
//     sort(arr, arr + n);
//     int count = 0;

//     for(int i = 0; i < n-2; i++) {
//         int left = i + 1, right = n - 1;
//         while(left < right) {
//             int sum = arr[i] + arr[left] + arr[right];
//             if(sum == x) {
//                 // If elements are same, count combinations
//                 if(arr[left] == arr[right]) {
//                     int len = right - left + 1;
//                     count += (len * (len - 1)) / 2;
//                     break;
//                 } else {
//                     // Count duplicates on both sides
//                     int leftCount = 1, rightCount = 1;
//                     while(left + 1 < right && arr[left] == arr[left + 1]) {
//                         leftCount++;
//                         left++;
//                     }
//                     while(right - 1 > left && arr[right] == arr[right - 1]) {
//                         rightCount++;
//                         right--;
//                     }
//                     count += leftCount * rightCount;
//                     left++;
//                     right--;
//                 }
//             }
//             else if(sum < x) left++;
//             else right--;
//         }
//     }
//     return count;
// }
// Q4. Find triplet with sum closest to target?
// cpp
// int findClosestTripletSum(int arr[], int n, int target) {
//     sort(arr, arr + n);
//     int closestSum = INT_MAX;
//     int minDiff = INT_MAX;

//     for(int i = 0; i < n-2; i++) {
//         int left = i + 1, right = n - 1;
//         while(left < right) {
//             int sum = arr[i] + arr[left] + arr[right];
//             int diff = abs(sum - target);

//             if(diff < minDiff) {
//                 minDiff = diff;
//                 closestSum = sum;
//             }

//             if(sum < target) left++;
//             else right--;
//         }
//     }
//     return closestSum;
// }
// Q5. Generalize to K-Sum problem?
// cpp
// bool kSum(int arr[], int n, int k, int target) {
//     sort(arr, arr + n);
//     return kSumHelper(arr, 0, n, k, target);
// }

// bool kSumHelper(int arr[], int start, int n, int k, int target) {
//     if(k == 2) {
//         // Base case: two-sum with two pointers
//         int left = start, right = n - 1;
//         while(left < right) {
//             int sum = arr[left] + arr[right];
//             if(sum == target) return true;
//             else if(sum < target) left++;
//             else right--;
//         }
//         return false;
//     }

//     // Recursive case
//     for(int i = start; i <= n - k; i++) {
//         if(kSumHelper(arr, i + 1, n, k - 1, target - arr[i]))
//             return true;
//     }
//     return false;
// }
// Q6. What if array has duplicates and we want unique triplets only?
// cpp
// bool hasUniqueTriplet(int arr[], int n, int x) {
//     sort(arr, arr + n);

//     for(int i = 0; i < n-2; i++) {
//         if(i > 0 && arr[i] == arr[i-1]) continue; // Skip duplicates

//         int left = i + 1, right = n - 1;
//         while(left < right) {
//             if(left > i + 1 && arr[left] == arr[left-1]) {
//                 left++;
//                 continue;
//             }
//             if(right < n - 1 && arr[right] == arr[right+1]) {
//                 right--;
//                 continue;
//             }

//             int sum = arr[i] + arr[left] + arr[right];
//             if(sum == x) return true;
//             else if(sum < x) left++;
//             else right--;
//         }
//     }
//     return false;
// }
// Q7. Memory-optimized hashing approach?
// cpp
// bool isTripletHashingOptimized(int arr[], int n, int x) {
//     // Use single hash set, clear it for each i
//     unordered_set<int> s;

//     for(int i = 0; i < n-2; i++) {
//         s.clear(); // Reuse same set
//         int target = x - arr[i];

//         for(int j = i + 1; j < n; j++) {
//             int complement = target - arr[j];
//             if(s.find(complement) != s.end())
//                 return true;
//             s.insert(arr[j]);
//         }
//     }
//     return false;
// }

// find median of two sorted array.
// superNaive sol: get both array in temparr and sort them and then get median. Time : NlogN.
// 🧠 Naive approach: merge both arrays in sorted order, then get the middle element(s)
float medianOfTwoArrayNaive(int arr1[], int n1, int arr2[], int n2)
{
    int tempSize = n1 + n2;
    int temp[tempSize];
    int i = 0, j = 0, k = 0;

    // 🔁 Merge two sorted arrays
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            temp[k++] = arr1[i++];
        else
            temp[k++] = arr2[j++];
    }
    while (i < n1)
        temp[k++] = arr1[i++];
    while (j < n2)
        temp[k++] = arr2[j++];

    // 🧮 Calculate median from merged array
    if (tempSize % 2 == 0)
        return (temp[tempSize / 2] + temp[tempSize / 2 - 1]) / 2.0;
    else
        return temp[tempSize / 2];
}

// 💡 Better approach: Two pointers without merging the whole array
float medianOfTwoArrayBetter(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0, k = -1;
    int prev = -1, curr = -1;
    int mid = (n1 + n2) / 2;

    //  Traverse until mid-th element
    while (i < n1 && j < n2)
    {
        prev = curr;
        if (arr1[i] < arr2[j])
            curr = arr1[i++];
        else
            curr = arr2[j++];
        k++;
        if (k == mid)
            break;
    }

    // Remaining elements from arr1
    while (k < mid && i < n1)
    {
        prev = curr;
        curr = arr1[i++];
        k++;
    }

    // Remaining elements from arr2
    while (k < mid && j < n2)
    {
        prev = curr;
        curr = arr2[j++];
        k++;
    }

    // Median logic
    if ((n1 + n2) % 2 == 0)
        return (prev + curr) / 2.0;
    else
        return curr;
}

// Most Efficient solution : yet to be done.

// find repeating element :
// super naive sol : pick one and check from rest. - o(n^2) sol.
// naive sol : sort the arr and check adjacent ele - n logn.

int repeatingElementSuperNaive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                return arr[i];
        }
    }
    return -1;
}

int repeatingElementNaive(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            return arr[i];
    }
    return -1;
}

int repeatingElementBetter(int arr[], int n)
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[arr[i]] == true)
            return arr[i];
        visited[arr[i]] = true;
    }
    return -1;
}

// loop detection technique : to find repeating element
// Problem: Find the duplicate number in an array where:
// Array contains n+1 integers
// Each integer is in the range [1, n]
// There is exactly one repeated number (but it may be repeated more than once)
// You must solve it without modifying the array and using O(1) extra space

// Idea Behind Floyd’s Algorithm:
// We treat the array like a linked list, where:

// The value of each element is the pointer to the next node.

// So, i → arr[i] → arr[arr[i]] → ...

// Because one number is repeated, two indices will point to the same value, creating a cycle in this "linked list". just like if we have a list of addresses and we go one by one like first patna, then delhi, then bhopal,then bangalore and agian delhi. then there must be a loop or a cycle in the list.
// Just like cars on a circular track — one slow, one fast — they’ll eventually be at the same point.
int repeatingEleTechnique(int arr[], int n)
{
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

// Based on your modified code pattern, this appears to be solving the "Find Missing Positive Number" or a variant where:

// Array contains n integers

// Values are in range [0, n-1] or [1, n]

// There's exactly one missing number in the sequence

// The algorithm treats array indices and values as a mapping system
// this code - perplexity give as a bug. to check throughly.
// also go through video to clarify.
int repeatingElementEfficient(int arr[], int n)
{
    int slow = arr[0] + 1;
    int fast = arr[0] + 1;
    do
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1] + 1;
    } while (slow != fast);

    slow = arr[0] + 1;
    while (slow != fast)
    {
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;
    }
    return slow - 1;
}

int main()
{

    int arr1[] = {3, 6, 9, 12, 24};
    int arr2[] = {4, 5, 8, 13, 18};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    float result = medianOfTwoArrayBetter(arr1, n1, arr2, n2);
    cout << result << endl;
    // selectionSort(arr, n);
    // printArray(arr, n);
    cout << endl;
    return 0;
}