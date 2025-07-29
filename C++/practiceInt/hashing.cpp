#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countDistinctElementsNaive(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            res++;
    }
    return res;
}

// using sorting
int countDistinctElementsBetter(int arr[], int n)
{
    sort(arr, arr + n);
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            res++;
    }
    return res;
}

// using hashing
int countDistinctElementsEfficient(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
}

// follow up questions :

// Q2. Count distinct elements in each subarray of size k?
// cpp
// vector<int> countDistinctInSubarrays(int arr[], int n, int k) {
//     vector<int> result;

//     for(int i = 0; i <= n - k; i++) {
//         unordered_set<int> window;
//         for(int j = i; j < i + k; j++) {
//             window.insert(arr[j]);
//         }
//         result.push_back(window.size());
//     }
//     return result;
// }
// Optimized Sliding Window:

// cpp
// vector<int> countDistinctSlidingWindow(int arr[], int n, int k) {
//     vector<int> result;
//     unordered_map<int, int> freq;
//     int distinctCount = 0;

//     // Process first window
//     for(int i = 0; i < k; i++) {
//         if(freq[arr[i]] == 0) distinctCount++;
//         freq[arr[i]]++;
//     }
//     result.push_back(distinctCount);

//     // Slide the window
//     for(int i = k; i < n; i++) {
//         // Remove leftmost element
//         int leftElement = arr[i - k];
//         freq[leftElement]--;
//         if(freq[leftElement] == 0) distinctCount--;

//         // Add rightmost element
//         if(freq[arr[i]] == 0) distinctCount++;
//         freq[arr[i]]++;

//         result.push_back(distinctCount);
//     }
//     return result;
// }
// Q3. What if elements are in a specific range [1 to k]?
// Boolean Array Approach:

// cpp
// int countDistinctInRange(int arr[], int n, int k) {
//     bool present[k + 1] = {false};
//     int count = 0;

//     for(int i = 0; i < n; i++) {
//         if(arr[i] >= 1 && arr[i] <= k && !present[arr[i]]) {
//             present[arr[i]] = true;
//             count++;
//         }
//     }
//     return count;
// }
// Time: O(n), Space: O(k)

// Q4. Count distinct elements with frequency exactly f?
// cpp
// int countDistinctWithFrequency(int arr[], int n, int f) {
//     unordered_map<int, int> freq;
//     for(int i = 0; i < n; i++) {
//         freq[arr[i]]++;
//     }

//     int count = 0;
//     for(auto& p : freq) {
//         if(p.second == f) count++;
//     }
//     return count;
// }
// Q5. Streaming version (elements arrive one by one)?
// cpp
// class DistinctCounter {
// private:
//     unordered_set<int> seen;

// public:
//     void addElement(int x) {
//         seen.insert(x);
//     }

//     int getDistinctCount() {
//         return seen.size();
//     }

//     bool isDistinct(int x) {
//         return seen.find(x) != seen.end();
//     }
// };
// Q6. Memory-constrained version (very large arrays)?
// Bit Vector Approach (for limited range):

// cpp
// int countDistinctBitVector(int arr[], int n, int maxVal) {
//     vector<bool> seen(maxVal + 1, false);
//     int count = 0;

//     for(int i = 0; i < n; i++) {
//         if(arr[i] >= 0 && arr[i] <= maxVal && !seen[arr[i]]) {
//             seen[arr[i]] = true;
//             count++;
//         }
//     }
//     return count;
// }
// Q7. Parallel processing version?
// cpp
// int countDistinctParallel(int arr[], int n) {
//     const int numThreads = 4;
//     vector<unordered_set<int>> threadSets(numThreads);

//     // Divide work among threads
//     #pragma omp parallel for
//     for(int t = 0; t < numThreads; t++) {
//         int start = t * n / numThreads;
//         int end = (t + 1) * n / numThreads;

//         for(int i = start; i < end; i++) {
//             threadSets[t].insert(arr[i]);
//         }
//     }

//     // Merge results
//     unordered_set<int> finalSet;
//     for(int t = 0; t < numThreads; t++) {
//         for(int x : threadSets[t]) {
//             finalSet.insert(x);
//         }
//     }

//     return finalSet.size();
// }
// 4. Comparison Table
// Approach	Time	Space	Modifies Array	Preserves Order	Best For
// Naive	O(n²)	O(1)	❌ No	✅ Yes	Small arrays
// Sorting	O(n log n)	O(1)	✅ Yes	❌ No	Medium arrays, space-constrained
// Hashing	O(n)	O(n)	❌ No	✅ Yes	Large arrays, optimal
// Boolean Array	O(n)	O(k)	❌ No	✅ Yes	Limited range elements
// Bit Vector	O(n)	O(k/8)	❌ No	✅ Yes	Very memory-constrained
// 5. Advanced Follow-ups
// Q8. What's the space-time trade-off sweet spot?
// For arrays with elements in range [1, k]:

// If k ≤ n: Use boolean array O(k) space

// If k > n: Use hash set O(n) space

// Q9. How to handle very large integers efficiently?
// Hash with Custom Hash Function:

// cpp
// struct CustomHash {
//     size_t operator()(const int& x) const {
//         return hash<int>{}(x) ^ 0x9e3779b9;
//     }
// };

// int countDistinctCustomHash(int arr[], int n) {
//     unordered_set<int, CustomHash> s;
//     for(int i = 0; i < n; i++) {
//         s.insert(arr[i]);
//     }
//     return s.size();
// }
// Q10. Approximate counting for massive datasets?
// HyperLogLog Algorithm (Advanced):

// cpp
// // Simplified version - real implementation is more complex
// class ApproximateDistinctCounter {
// private:
//     static const int B = 8; // 2^B buckets
//     vector<int> buckets;

// public:
//     ApproximateDistinctCounter() : buckets(1 << B, 0) {}

//     void addElement(int x) {
//         size_t hash_val = hash<int>{}(x);
//         int bucket = hash_val & ((1 << B) - 1);
//         int leading_zeros = __builtin_clzll(hash_val >> B) + 1;
//         buckets[bucket] = max(buckets[bucket], leading_zeros);
//     }

//     double estimateCount() {
//         double sum = 0;
//         for(int b : buckets) {
//             sum += pow(2, -b);
//         }
//         return 0.7213 * (1 << B) * (1 << B) / sum;
//     }
// };
// 6. Edge Cases Analysis
// ✅ Empty array: All approaches handle correctly
// ✅ Single element: Returns 1
// ✅ All same elements: Returns 1
// ✅ No duplicates: Returns n
// ✅ Negative numbers: Hash approach handles best
// ✅ Large numbers: Hash approach most suitable
// ✅ Integer overflow: No issues in counting

// 7. Performance Optimizations
// Optimized Naive (Early Termination):
// cpp
// int countDistinctOptimizedNaive(int arr[], int n) {
//     int count = 0;

//     for(int i = 0; i < n; i++) {
//         bool found = false;

//         // Only check previous elements
//         for(int j = 0; j < i; j++) {
//             if(arr[j] == arr[i]) {
//                 found = true;
//                 break;
//             }
//         }

//         if(!found) count++;
//     }
//     return count;
// }
// Hybrid Approach:
// cpp
// int countDistinctHybrid(int arr[], int n) {
//     if(n < 100) {
//         // Use naive for small arrays
//         return countDistinctElementsNaive(arr, n);
//     } else {
//         // Use hashing for large arrays
//         return countDistinctElementsEfficient(arr, n);
//     }
// }
// Verdict
// Your implementations are excellent and demonstrate perfect understanding of different approaches to count distinct elements!

// ✅ All three approaches are correct and well-implemented
// ✅ Proper complexity analysis across different scenarios
// ✅ Clean, readable code
// ✅ Good progression from naive to optimal

// The hashing approach is typically preferred in interviews due to its O(n) time complexity and ability to preserve original array order. However, the sorting approach is valuable when space is constrained.

// Key Interview Points:

// Understand when to use each approach

// Know the trade-offs between time, space, and array modification

// Be ready to extend to related problems like sliding window variants

// Handle edge cases appropriately

// This demonstrates solid algorithmic thinking and is exactly what interviewers want to see! 🎯

// count freq. of ele in array;
// naive : check if already counted and then count each.- note
// better : sort and then count
// efficient : hashing - store in unorderedMap

// intersection of two array./ count distinct elements which are there in both array.
int intersectionNaive(int arr[], int n1, int brr[], int n2)
{
    int res = 0;
    for (int i = 0; i < n1; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == arr[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;

        for (int j = 0; j < n2; j++)
        {
            if (arr[i] == brr[j])
            {
                res++;
                break;
            }
        }
    }
    return res;
}

int intersectionEfficient(int arr[], int n1, int brr[], int n2)
{
    unordered_set<int> s;
    int res = 0;
    for (int i = 0; i < n1; i++)
    {
        s.insert(arr[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        if (s.find(brr[i]) != s.end())
        {
            res++;
            s.erase(brr[i]);
        }
    }
    return res;
}

int intersectionEfficient2(int arr[], int n1, int brr[], int n2)
{
    unordered_set<int> s1;
    unordered_set<int> s2;
    int res = 0;
    for (int i = 0; i < n1; i++)
    {
        s1.insert(arr[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        s2.insert(brr[i]);
    }
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        if (s2.find(*it) != s2.end())
            res++;
    }
    return res;
}

// follow up question.
// Q4. Intersection of k arrays?
// cpp
// vector<int> intersectionKArrays(vector<vector<int>>& arrays) {
//     if(arrays.empty()) return {};

//     unordered_set<int> result;
//     for(int x : arrays[0]) result.insert(x);

//     for(int i = 1; i < arrays.size(); i++) {
//         unordered_set<int> current;
//         for(int x : arrays[i]) current.insert(x);

//         unordered_set<int> newResult;
//         for(int x : result) {
//             if(current.find(x) != current.end()) {
//                 newResult.insert(x);
//             }
//         }
//         result = newResult;
//     }

//     return vector<int>(result.begin(), result.end());
// }

// Union of two arrays?

int unionCount(int arr[], int n1, int brr[], int n2)
{
    unordered_set<int> s;

    for (int i = 0; i < n1; i++)
        s.insert(arr[i]);
    for (int i = 0; i < n2; i++)
        s.insert(brr[i]);

    return s.size();
}

bool isSubArraySumZeroNaive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
                return true;
        }
    }
    return false;
}

// logic is - if sum from start to a point p and sum from start to a point p+(some point n)= p+n are same then from p to n - must be zero.
bool isSubArraySumZeroEfficient(int arr[], int n)
{
    unordered_set<int> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0) // needed if start element is zero or the whole arr sum is zero
            return true;
        if (s.find(sum) != s.end())
            return true;

        s.insert(sum);
    }
    return false;
}

// Function to check if a subarray with the given sum exists
bool isSubArraySumGivenSumEfficient(int arr[], int n, int givenSum)
{
    unordered_set<int> s; // Stores prefix sums
    int sum = 0;          // Initialize prefix sum

    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // Update the running sum

        // Case 1: Subarray starts from index 0 to i
        if (sum == givenSum)
            return true;

        // Case 2: Subarray with sum = givenSum exists between some indices
        // sum - givenSum = prefix sum seen before
        if (s.find(sum - givenSum) != s.end())
            return true;

        // Store the current prefix sum
        s.insert(sum);
    }

    // No subarray with given sum found
    return false;
}

// 3. Follow-Up Questions & Solutions
// Q1. What's the naive approach?
// cpp
// bool isSubArraySumGivenSumNaive(int arr[], int n, int givenSum) {
//     for(int i = 0; i < n; i++) {
//         int sum = 0;
//         for(int j = i; j < n; j++) {
//             sum += arr[j];
//             if(sum == givenSum)
//                 return true;
//         }
//     }
//     return false;
// }
// Time: O(n²), Space: O(1)

// Q2. Return the actual subarray with given sum?
// cpp
// vector<int> findSubarrayWithSum(int arr[], int n, int givenSum) {
//     unordered_map<int, int> prefixIndex; // sum -> first occurrence index
//     int sum = 0;

//     for(int i = 0; i < n; i++) {
//         sum += arr[i];

//         // Case 1: Subarray from start
//         if(sum == givenSum)
//             return vector<int>(arr, arr + i + 1);

//         // Case 2: Subarray in middle
//         if(prefixIndex.find(sum - givenSum) != prefixIndex.end()) {
//             int start = prefixIndex[sum - givenSum] + 1;
//             return vector<int>(arr + start, arr + i + 1);
//         }

//         prefixIndex[sum] = i;
//     }
//     return {}; // No subarray found
// }
// Q3. Return start and end indices?
// cpp
// pair<int,int> findSubarrayIndices(int arr[], int n, int givenSum) {
//     unordered_map<int, int> prefixIndex;
//     int sum = 0;

//     for(int i = 0; i < n; i++) {
//         sum += arr[i];

//         if(sum == givenSum)
//             return {0, i};

//         if(prefixIndex.find(sum - givenSum) != prefixIndex.end()) {
//             int start = prefixIndex[sum - givenSum] + 1;
//             return {start, i};
//         }

//         prefixIndex[sum] = i;
//     }
//     return {-1, -1}; // Not found
// }
// Q4. Count ALL subarrays with given sum?
// cpp
// int countSubarraysWithSum(int arr[], int n, int givenSum) {
//     unordered_map<int, int> prefixCount;
//     int sum = 0, count = 0;

//     prefixCount[0] = 1; // For subarrays starting from index 0

//     for(int i = 0; i < n; i++) {
//         sum += arr[i];

//         // Count subarrays ending at current index
//         if(prefixCount.find(sum - givenSum) != prefixCount.end())
//             count += prefixCount[sum - givenSum];

//         prefixCount[sum]++;
//     }
//     return count;
// }
// Q5. Find longest subarray with given sum?
// cpp
// int longestSubarrayWithSum(int arr[], int n, int givenSum) {
//     unordered_map<int, int> prefixIndex;
//     int sum = 0, maxLen = 0;

//     for(int i = 0; i < n; i++) {
//         sum += arr[i];

//         if(sum == givenSum) {
//             maxLen = max(maxLen, i + 1);
//         }
//         else if(prefixIndex.find(sum - givenSum) != prefixIndex.end()) {
//             maxLen = max(maxLen, i - prefixIndex[sum - givenSum]);
//         }

//         // Only store first occurrence for maximum length
//         if(prefixIndex.find(sum) == prefixIndex.end())
//             prefixIndex[sum] = i;
//     }
//     return maxLen;
// }
// Q6. What if array contains only positive numbers?
// Sliding Window Approach (More Efficient):

// cpp
// bool hasSubarrayWithSumPositive(int arr[], int n, int givenSum) {
//     int left = 0, sum = 0;

//     for(int right = 0; right < n; right++) {
//         sum += arr[right];

//         while(sum > givenSum && left <= right) {
//             sum -= arr[left];
//             left++;
//         }

//         if(sum == givenSum)
//             return true;
//     }
//     return false;
// }
// Time: O(n), Space: O(1)

int longestSubarrayWithGivenSumNaive(int arr[], int n, int givenSum)
{
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == givenSum)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int longestSubarrayWithGivenSumEfficient(int arr[], int n, int givenSum)
{
    int res = 0;                // Stores maximum subarray length
    int presum = 0;             // Running prefix sum
    unordered_map<int, int> mp; // Maps prefix sum -> first index

    for (int i = 0; i < n; i++)
    {
        presum += arr[i];

        // Case 1: Subarray from start has sum = givenSum
        if (presum == givenSum)
            res = i + 1;

        // Case 2: Subarray from some index after previous prefix sum
        if (mp.find(presum - givenSum) != mp.end())
            res = max(res, i - mp[presum - givenSum]);

        // Store prefix sum if first occurrence (important for longest length)
        if (mp.find(presum) == mp.end())
            mp[presum] = i;
    }
    return res;
}

// Why "First Occurrence" is Crucial
// Your code correctly stores only the first occurrence of each prefix sum:

// cpp
// if (mp.find(presum) == mp.end())
//     mp[presum] = i;
// Why this matters:

// For maximum length, we want the earliest possible start index

// If we stored the latest occurrence, we'd get shorter subarrays

// Example:

// cpp
// arr[] = {1, 0, -1, 0, 1}; givenSum = 0;
// Prefix sums: 1, 1, 0, 0, 1

// When i=3 (presum=0), we look for presum-givenSum = 0-0 = 0

// We find 0 at index 2, giving length = 3-2 = 1

// If we had stored latest occurrence of 0, we'd get length 0!

// Follow up : Return the actual longest subarray?

vector<int> longestSubarrayWithGivenSum(int arr[], int n, int givenSum)
{
    int presum = 0;
    unordered_map<int, int> mp; // prefix sum -> first index
    int maxLen = 0;
    int startIdx = -1, endIdx = -1;

    for (int i = 0; i < n; i++)
    {
        presum += arr[i];

        // Case 1: From start to current index
        if (presum == givenSum)
        {
            if (i + 1 > maxLen)
            {
                maxLen = i + 1;
                startIdx = 0;
                endIdx = i;
            }
        }

        // Case 2: Between some previous index and current index
        if (mp.find(presum - givenSum) != mp.end())
        {
            int len = i - mp[presum - givenSum];
            if (len > maxLen)
            {
                maxLen = len;
                startIdx = mp[presum - givenSum] + 1; // +1 because the start index will start from next element which is found at map. and this is the same reason why we do presum - givenSum and Not presum - givenSum + 1 as we think to get the size between index we do (j-i+1)
                endIdx = i;
            }
        }

        // Store first occurrence of prefix sum
        if (mp.find(presum) == mp.end())
        {
            mp[presum] = i;
        }
    }

    // If no subarray found
    if (startIdx == -1)
        return {};

    // Extract the subarray
    vector<int> subarray;
    for (int i = startIdx; i <= endIdx; i++)
    {
        subarray.push_back(arr[i]);
    }
    return subarray;
}

// Return start and end indices of longest subarray?

pair<int, int> longestSubarrayIndices(int arr[], int n, int givenSum)
{
    int presum = 0;
    unordered_map<int, int> mp; // prefix sum -> first index
    int maxLen = 0;
    int startIdx = -1, endIdx = -1;

    for (int i = 0; i < n; i++)
    {
        presum += arr[i];

        // Case 1: Subarray starts from index 0
        if (presum == givenSum)
        {
            if (i + 1 > maxLen)
            {
                maxLen = i + 1;
                startIdx = 0;
                endIdx = i;
            }
        }

        // Case 2: Subarray between two indices
        if (mp.find(presum - givenSum) != mp.end())
        {
            int len = i - mp[presum - givenSum];
            if (len > maxLen)
            {
                maxLen = len;
                startIdx = mp[presum - givenSum] + 1;
                endIdx = i;
            }
        }

        // Store first occurrence of this prefix sum
        if (mp.find(presum) == mp.end())
        {
            mp[presum] = i;
        }
    }

    return {startIdx, endIdx}; // returns {-1, -1} if no subarray found
}

// What if array contains only positive numbers?
// Sliding Window Approach (More Efficient):

// cpp
// int longestSubarrayPositive(int arr[], int n, int givenSum) {
//     int left = 0, sum = 0, maxLen = 0;

//     for(int right = 0; right < n; right++) {
//         sum += arr[right];

//         while(sum > givenSum && left <= right) {
//             sum -= arr[left];
//             left++;
//         }

//         if(sum == givenSum) {
//             maxLen = max(maxLen, right - left + 1);
//         }
//     }
//     return maxLen;
// }
// Time: O(n), Space: O(1)

// given binary array , find longest subarray with equal number of zeros and ones.
int longestSubarrayWithEqZeroOneNaive(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int c0 = 0, c1 = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                c0++;
            else
                c1++;
            if (c0 == c1)
                res = max(res, j - i + 1);
        }
    }
    return res;
}

int longestSubarrayWithEqZeroOneEfficient(int arr[], int n)
{
    int res = 0;
    int presum = 0;
    unordered_map<int, int> mp; // stores prefix sum -> first index

    for (int i = 0; i < n; i++)
    {
        // Treat 0 as -1, so equal number of 0s and 1s → prefix sum = 0
        int t = (arr[i] == 1) ? 1 : -1;
        presum += t;

        // Case 1: From start to current index
        if (presum == 0)
            res = i + 1;

        // Case 2: Subarray found between two prefix sums
        if (mp.find(presum) != mp.end())
            res = max(res, i - mp[presum]);

        // Store first occurrence of prefix sum
        if (mp.find(presum) == mp.end())
            mp[presum] = i;
    }
    return res;
}

// Follow-Up Questions & Solutions
// Q1. Return the actual longest balanced subarray?
// cpp
// vector<int> getLongestBalancedSubarray(int arr[], int n) {
//     unordered_map<int, int> mp;
//     int presum = 0, maxLen = 0, endIndex = -1;

//     for(int i = 0; i < n; i++) {
//         int t = (arr[i] == 1) ? 1 : -1;
//         presum += t;

//         if(presum == 0) {
//             if(i + 1 > maxLen) {
//                 maxLen = i + 1;
//                 endIndex = i;
//             }
//         }

//         if(mp.find(presum) != mp.end()) {
//             int len = i - mp[presum];
//             if(len > maxLen) {
//                 maxLen = len;
//                 endIndex = i;
//             }
//         }

//         if(mp.find(presum) == mp.end())
//             mp[presum] = i;
//     }

//     if(maxLen == 0) return {};

//     int startIndex = endIndex - maxLen + 1;
//     return vector<int>(arr + startIndex, arr + endIndex + 1);
// }
// Q2. Count ALL balanced subarrays?
// cpp
// int countBalancedSubarrays(int arr[], int n) {
//     unordered_map<int, int> prefixCount;
//     int presum = 0, count = 0;

//     prefixCount[0] = 1; // For subarrays starting from index 0

//     for(int i = 0; i < n; i++) {
//         int t = (arr[i] == 1) ? 1 : -1;
//         presum += t;

//         // Count subarrays ending at current index
//         if(prefixCount.find(presum) != prefixCount.end())
//             count += prefixCount[presum];

//         prefixCount[presum]++;
//     }
//     return count;
// }
// Q3. Find balanced subarray with maximum sum of indices?
// cpp
// pair<int,int> getBalancedSubarrayMaxIndexSum(int arr[], int n) {
//     unordered_map<int, int> mp;
//     int presum = 0;
//     pair<int,int> result = {-1, -1};
//     int maxIndexSum = -1;

//     for(int i = 0; i < n; i++) {
//         int t = (arr[i] == 1) ? 1 : -1;
//         presum += t;

//         if(presum == 0) {
//             int indexSum = (0 + i) * (i + 1) / 2; // Sum of indices 0 to i
//             if(indexSum > maxIndexSum) {
//                 maxIndexSum = indexSum;
//                 result = {0, i};
//             }
//         }

//         if(mp.find(presum) != mp.end()) {
//             int start = mp[presum] + 1;
//             int indexSum = 0;
//             for(int k = start; k <= i; k++) indexSum += k;

//             if(indexSum > maxIndexSum) {
//                 maxIndexSum = indexSum;
//                 result = {start, i};
//             }
//         }

//         if(mp.find(presum) == mp.end())
//             mp[presum] = i;
//     }

//     return result;
// }
// Q4. What if we want k zeros and k ones (generalized)?
// cpp
// int longestSubarrayWithKZerosKOnes(int arr[], int n, int k) {
//     // Need exactly k zeros and k ones
//     int maxLen = 0;

//     for(int i = 0; i < n; i++) {
//         int zeros = 0, ones = 0;
//         for(int j = i; j < n; j++) {
//             if(arr[j] == 0) zeros++;
//             else ones++;

//             if(zeros == k && ones == k) {
//                 maxLen = max(maxLen, j - i + 1);
//                 break; // Found k of each, can't extend further
//             }
//             if(zeros > k || ones > k) break; // Exceeded limit
//         }
//     }
//     return maxLen;
// }

int longestCommonSubarrayWithSameSumNaive(int arr1[], int arr2[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int s1 = 0, s2 = 0;
        for (int j = i; j < n; j++)
        {
            s1 += arr1[j];
            s2 += arr2[j];
            if (s1 == s2)
                res = max(res, j - i + 1);
        }
    }
    return res;
}

int longestCommonSubarrayWithSameSumEfficient(int arr1[], int arr2[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr1[i] - arr2[i];
    }

    // now find longest subarray with given sum 0.
    int presum = 0;
    int res = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        presum += temp[i];
        if (presum == 0)
            res = i + 1;
        if (mp.find(presum) != mp.end())
            res = max(res, i - mp[presum]);
        if (mp.find(presum) == mp.end())
            mp[presum] = i;
    }
    return res;
}

// 4. Follow-Up Questions & Solutions
// Q1. Return the actual longest common subarray?
// cpp
// pair<vector<int>, vector<int>> getLongestCommonSubarray(int arr1[], int arr2[], int n) {
//     vector<int> temp(n);
//     for(int i = 0; i < n; i++) {
//         temp[i] = arr1[i] - arr2[i];
//     }

//     unordered_map<int, int> mp;
//     int presum = 0, maxLen = 0, endIndex = -1;

//     for(int i = 0; i < n; i++) {
//         presum += temp[i];

//         if(presum == 0) {
//             if(i + 1 > maxLen) {
//                 maxLen = i + 1;
//                 endIndex = i;
//             }
//         }

//         if(mp.find(presum) != mp.end()) {
//             int len = i - mp[presum];
//             if(len > maxLen) {
//                 maxLen = len;
//                 endIndex = i;
//             }
//         }

//         if(mp.find(presum) == mp.end())
//             mp[presum] = i;
//     }

//     if(maxLen == 0) return {{}, {}};

//     int startIndex = endIndex - maxLen + 1;
//     return {
//         vector<int>(arr1 + startIndex, arr1 + endIndex + 1),
//         vector<int>(arr2 + startIndex, arr2 + endIndex + 1)
//     };
// }
// Q2. Count ALL common subarrays with same sum?
// cpp
// int countCommonSubarraysWithSameSum(int arr1[], int arr2[], int n) {
//     vector<int> temp(n);
//     for(int i = 0; i < n; i++) {
//         temp[i] = arr1[i] - arr2[i];
//     }

//     unordered_map<int, int> prefixCount;
//     int presum = 0, count = 0;

//     prefixCount[0] = 1; // For subarrays starting from index 0

//     for(int i = 0; i < n; i++) {
//         presum += temp[i];

//         // Count subarrays ending at current index
//         if(prefixCount.find(presum) != prefixCount.end())
//             count += prefixCount[presum];

//         prefixCount[presum]++;
//     }
//     return count;
// }
// Q3. What if arrays have different lengths?
// cpp
// int longestCommonSubarrayDifferentSizes(int arr1[], int n1, int arr2[], int n2) {
//     int maxLen = 0;
//     int minLen = min(n1, n2);

//     // Try all possible starting positions
//     for(int start1 = 0; start1 <= n1 - 1; start1++) {
//         for(int start2 = 0; start2 <= n2 - 1; start2++) {
//             int len = min(n1 - start1, n2 - start2);

//             // Create difference array for this alignment
//             vector<int> temp(len);
//             for(int i = 0; i < len; i++) {
//                 temp[i] = arr1[start1 + i] - arr2[start2 + i];
//             }

//             // Find longest zero-sum subarray
//             int currentMax = longestZeroSumSubarray(temp.data(), len);
//             maxLen = max(maxLen, currentMax);
//         }
//     }
//     return maxLen;
// }

// subseq means if - one after next number. like 5,6,7 are subseq, if start is 2 then 2,3,4.. are in subseq.
int longestConsecutiveSubsequenceNaive(int arr[], int n)
{
    if (n == 0)
        return 0;

    sort(arr, arr + n);
    int res = 1;
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            // Skip duplicates int arr[] = {1, 2, 2, 3}; After sorting: [1, 2, 2, 3]
            continue;
        }
        else if (arr[i] == arr[i - 1] + 1)
        {
            count++;
            res = max(res, count);
        }
        else
        {
            count = 1;
        }
    }
    return res;
}

int longestConsecutiveSubsequenceEfficient(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (s.find(arr[i] - 1) == s.end())
        {
            count++;
            while (s.find(arr[i] + count) != s.end())
                count++;
            res = max(res, count);
        }
    }
    return res;
}

// Follow-Up Questions & Solutions
// Q1. Return the actual longest consecutive subsequence?
// cpp
// vector<int> getLongestConsecutiveSubsequence(int arr[], int n) {
//     if(n == 0) return {};

//     unordered_set<int> s(arr, arr + n);
//     vector<int> result;
//     int maxLen = 0;

//     for(int i = 0; i < n; i++) {
//         if(s.find(arr[i] - 1) == s.end()) {
//             vector<int> current;
//             int num = arr[i];

//             while(s.find(num) != s.end()) {
//                 current.push_back(num);
//                 num++;
//             }

//             if(current.size() > maxLen) {
//                 maxLen = current.size();
//                 result = current;
//             }
//         }
//     }
//     return result;
// }
// Q2. Count ALL consecutive subsequences?
// cpp
// int countConsecutiveSubsequences(int arr[], int n) {
//     unordered_set<int> s(arr, arr + n);
//     int count = 0;

//     for(int i = 0; i < n; i++) {
//         if(s.find(arr[i] - 1) == s.end()) {
//             // Found start of a sequence
//             count++;
//         }
//     }
//     return count;
// }
// Q3. Find all consecutive subsequences of length >= k?
// cpp
// vector<vector<int>> getConsecutiveSubsequencesMinLength(int arr[], int n, int k) {
//     unordered_set<int> s(arr, arr + n);
//     vector<vector<int>> result;

//     for(int i = 0; i < n; i++) {
//         if(s.find(arr[i] - 1) == s.end()) {
//             vector<int> current;
//             int num = arr[i];

//             while(s.find(num) != s.end()) {
//                 current.push_back(num);
//                 num++;
//             }

//             if(current.size() >= k) {
//                 result.push_back(current);
//             }
//         }
//     }
//     return result;
// }
// Q4. What if we want k longest consecutive subsequences?
// cpp
// vector<vector<int>> getKLongestConsecutive(int arr[], int n, int k) {
//     unordered_set<int> s(arr, arr + n);
//     vector<pair<int, vector<int>>> sequences; // {length, sequence}

//     for(int i = 0; i < n; i++) {
//         if(s.find(arr[i] - 1) == s.end()) {
//             vector<int> current;
//             int num = arr[i];

//             while(s.find(num) != s.end()) {
//                 current.push_back(num);
//                 num++;
//             }

//             sequences.push_back({current.size(), current});
//         }
//     }

//     // Sort by length in descending order
//     sort(sequences.begin(), sequences.end(),
//          [](const auto& a, const auto& b) { return a.first > b.first; });

//     vector<vector<int>> result;
//     for(int i = 0; i < min(k, (int)sequences.size()); i++) {
//         result.push_back(sequences[i].second);
//     }

//     return result;
// }
// Q5. Handle very large numbers efficiently?
// cpp
// int longestConsecutiveLargeNumbers(vector<long long>& arr) {
//     unordered_set<long long> s(arr.begin(), arr.end());
//     int maxLen = 0;

//     for(long long num : arr) {
//         if(s.find(num - 1) == s.end()) {
//             int count = 1;
//             long long current = num;

//             while(s.find(current + 1) != s.end()) {
//                 current++;
//                 count++;
//             }

//             maxLen = max(maxLen, count);
//         }
//     }
//     return maxLen;
// }

// count distinct element in Every window of size k.
vector<int> countDestinctKsizeWindowNaive(int arr[], int n, int k)
{
    vector<int> res;
    int i = 0;
    while (i < n - k + 1)
    {
        unordered_set<int> s(arr + i, arr + i + k);
        res.push_back(s.size());
        i++;
    }
    return res;
}

vector<int> countDestinctKsizeWindowEfficient(int arr[], int n, int k)
{
    vector<int> res;
    unordered_map<int, int> mp;

    // First window
    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }
    res.push_back(mp.size());

    // Slide the window
    for (int i = k; i < n; i++)
    {
        int outgoing = arr[i - k];

        // Decrement count of outgoing element
        if (mp.find(outgoing) != mp.end())
        {
            mp[outgoing]--;
            if (mp[outgoing] == 0)
            {
                mp.erase(outgoing);
            }
        }

        // Add new element
        mp[arr[i]]++;

        res.push_back(mp.size());
    }

    return res;
}

// Follow-Up Questions & Solutions
// Q1. What if we want the actual distinct elements in each window?
// cpp
// vector<vector<int>> getDistinctElementsInWindows(int arr[], int n, int k) {
//     vector<vector<int>> result;
//     unordered_map<int, int> freq;

//     // First window
//     for(int i = 0; i < k; i++) {
//         freq[arr[i]]++;
//     }

//     vector<int> firstWindow;
//     for(auto& p : freq) {
//         firstWindow.push_back(p.first);
//     }
//     result.push_back(firstWindow);

//     // Slide the window
//     for(int i = k; i < n; i++) {
//         int outgoing = arr[i - k];

//         // Remove outgoing element
//         freq[outgoing]--;
//         if(freq[outgoing] == 0) {
//             freq.erase(outgoing);
//         }

//         // Add incoming element
//         freq[arr[i]]++;

//         // Collect distinct elements
//         vector<int> currentWindow;
//         for(auto& p : freq) {
//             currentWindow.push_back(p.first);
//         }
//         result.push_back(currentWindow);
//     }

//     return result;
// }
// Q2. Find window with maximum distinct elements?
// cpp
// pair<int, int> windowWithMaxDistinct(int arr[], int n, int k) {
//     unordered_map<int, int> freq;
//     int maxDistinct = 0;
//     int bestStart = 0;

//     // First window
//     for(int i = 0; i < k; i++) {
//         freq[arr[i]]++;
//     }

//     maxDistinct = freq.size();

//     // Slide the window
//     for(int i = k; i < n; i++) {
//         int outgoing = arr[i - k];

//         freq[outgoing]--;
//         if(freq[outgoing] == 0) {
//             freq.erase(outgoing);
//         }

//         freq[arr[i]]++;

//         if(freq.size() > maxDistinct) {
//             maxDistinct = freq.size();
//             bestStart = i - k + 1;
//         }
//     }

//     return {bestStart, maxDistinct};
// }
// Q3. What if we want distinct count for all possible window sizes?
// cpp
// vector<vector<int>> distinctCountAllWindowSizes(int arr[], int n) {
//     vector<vector<int>> result;

//     for(int k = 1; k <= n; k++) {
//         vector<int> currentResult = countDestinctKsizeWindowEfficient(arr, n, k);
//         result.push_back(currentResult);
//     }

//     return result;
// }

// print those elements which appeared more than n/k times.
vector<int> appearedMoreThanNByKNaive(int arr[], int n, int k)
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;

        int count = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > n / k)
            res.push_back(arr[i]);
    }
    return res;
}

vector<int> appearedMoreThanNByKBetter(int arr[], int n, int k)
{
    sort(arr, arr + n);
    vector<int> res;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            count++;
        else
        {
            if (count > n / k)
                res.push_back(arr[i - 1]);
            count = 1;
        }
    }
    if (count > n / k)
        res.push_back(arr[n - 1]);
    return res;
}

vector<int> appearedMoreThanNByKEfficient(int arr[], int n, int k)
{
    vector<int> res;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second > n / k)
            res.push_back(i.first);
    }
    return res;
}
int main()
{
    int arr[] = {2, 2, 6, 8, 2, 6, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = countDistinctElementsEfficient(arr, n);
    cout << result << endl;

    return 0;
}