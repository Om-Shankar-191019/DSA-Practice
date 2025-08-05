// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Iterative approach to count digits in a number
int countDigits(long long n)
{
    // Handle zero as a special case (it has 1 digit)
    if (n == 0)
        return 1;

    // Convert negative number to positive
    n = llabs(n);

    int count = 0;
    // Keep dividing by 10 until the number becomes 0
    while (n != 0)
    {
        n /= 10; // Remove the last digit
        count++; // Increment digit count
    }
    return count;
}

// Recursive approach to count digits in a number
// Recursive approach to count digits correctly
int countDigitsRecursive(long long n)
{
    // Handle negative numbers
    if (n < 0)
        n = -n;

    // Base case: single-digit number has 1 digit
    if (n < 10)
        return 1;

    // Recursive call: count current digit + remaining digits
    return 1 + countDigitsRecursive(n / 10);
}

int reverseDigits(int n)
{
    int temp = n;
    int y = 0;
    while (temp != 0)
    {
        int rem = temp % 10;
        y = y * 10 + rem;
        temp = temp / 10;
    }
    return y;
}

bool isPalindrome(int n)
{
    int temp = n;
    int y = 0;
    while (temp != 0)
    {
        int rem = temp % 10;
        y = y * 10 + rem;
        temp = temp / 10;
    }
    return y == n;
}

int factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res = res * i;
    }
    return res;
}

int factorialRecursive(int n)
{
    if (n == 0)
        return 1;
    return n * factorialRecursive(n - 1);
}

// For negative numbers, GCD is always positive.
int gcdNaive(int a, int b)
{
    a = abs(a);
    b = abs(b);
    int res = min(a, b);
    for (int i = res; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

int lcmNaive(int a, int b)
{
    a = abs(a);
    b = abs(b);
    int res = max(a, b);
    while (true)
    {
        if (res % a == 0 && res % b == 0)
            return res;
        res++;
    }
}

int gcdMultiple(const vector<int> &nums)
{
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++)
        result = gcdNaive(result, nums[i]);
    return result;
}
// Example: vector<int> arr{24, 36, 60}; // gcdMultiple(arr) should return 12

// formulat a*b = lcm(a,b) * gcd(a,b) ;
int lcm(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0)
        return 0; // LCM of zero with any number is zero
    return (a * b) / gcdNaive(a, b);
}

void printAllDivisorNaive(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
}

// efficient logic : divisor appears in pair. and the pair is x , n/x because x * n/x = n.
void printAllDivisorEfficient(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
                cout << n / i << " "; // it should be printed without if condition but the condition is given for if both x,y in pair is same number , it would print twice.like (5,5) for 25.
        }
    }
}

void printAllDivisorEfficientAscendingPrint(int n)
{
    int i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }

    for (; i >= 1; i--)
    {
        if (n % i == 0)
        {
            cout << n / i << " ";
        }
    }
}
bool isPrimeNaive(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// logic : divisor always appeas in pair
bool isPrimeBetter(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPrimeEfficient(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// prime factors of a given number :O(n * √n) complexity.
vector<int> primeFactorsNaive(int n)
{
    vector<int> res;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0 && isPrimeEfficient(i))
            res.push_back(i);
    }
    return res;
}

// O(√n * √n) - it gives unique prime factors
void primeFactorsBetter(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrimeEfficient(i))
                cout << i << " ";
            if (i != n / i)
            {
                if (isPrimeEfficient(n / i))
                    cout << n / i << " "; // it should be printed without if condition but the condition is given for if both x,y in pair is same number , it would print twice.like (5,5) for 25.
            }
        }
    }
}

// void primeFactorsEfficient(int n) {
//     if (n <= 1) return;

//     // Handle factor 2
//     while (n % 2 == 0) {
//         cout << 2 << " ";
//         n /= 2;
//     }

//     // Handle odd factors
//     for (int i = 3; i * i <= n; i += 2) {
//         while (n % i == 0) {
//             cout << i << " ";
//             n /= i;
//         }
//     }

//     // If remaining n is a prime > 2
//     if (n > 2)
//         cout << n << " ";
// }
// Print all primes up to n : T(n*rootn)
void printAllPrimesNaive(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (isPrimeEfficient(i))
            cout << i << " ";
    }
}

int main()
{
    printAllDivisorEfficientAscendingPrint(25);
    int result = gcdNaive(5, 20);
    // cout << result << endl;

    return 0;
}