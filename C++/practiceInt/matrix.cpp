#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void displayMatrix(int arr[][4], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void printMatrix(const vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void printMatrixInSnakePattern(const vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        if (i % 2 == 0)
        {

            for (int j = 0; j < mat[i].size(); j++)
                cout << mat[i][j] << " ";
        }
        else
        {

            for (int j = mat[i].size() - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// follow up :
// Return flattened snake order as vector?
// cpp
// vector<int> snakeOrder(const vector<vector<int>>& mat){
//     vector<int> res;
//     for(int i=0;i<mat.size();i++){
//         if(i%2==0)
//             res.insert(res.end(), mat[i].begin(), mat[i].end());
//         else
//             res.insert(res.end(), mat[i].rbegin(), mat[i].rend());
//     }
//     return res;
// }

// boundryTraversal
void boundryTraversal(const vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();

    if (r == 1)
    {

        for (int i = 0; i < c; i++)
            cout << mat[0][i] << " ";
    }
    else if (c == 1)
    {

        for (int i = 0; i < r; i++)
            cout << mat[i][0] << " ";
    }
    else
    {

        for (int i = 0; i < c; i++)
            cout << mat[0][i] << " ";

        for (int i = 1; i < r; i++)
            cout << mat[i][c - 1] << " ";

        for (int i = c - 2; i >= 0; i--)
            cout << mat[r - 1][i] << " ";

        for (int i = r - 2; i >= 1; i--)
            cout << mat[i][0] << " ";
    }
}

void boundaryTraversal2(const vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();

    // Top row
    for (int i = 0; i < c; i++)
        cout << mat[0][i] << " ";

    // Right column (excluding top row)
    for (int i = 1; i < r; i++)
        cout << mat[i][c - 1] << " ";

    // Bottom row (only if more than one row) // the condition is necessary as while returning , for single row/col , prints the duplicate elements.
    if (r > 1)
    {
        for (int i = c - 2; i >= 0; i--)
            cout << mat[r - 1][i] << " ";
    }

    // Left column (only if more than one column)
    if (c > 1)
    {
        for (int i = r - 2; i >= 1; i--)
            cout << mat[i][0] << " ";
    }
}

void transposeSquareMatrixEfficient(vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

void rotateMatrix90Anticlock(vector<vector<int>> &mat)
{
    // logic : reverse each row and get transpose.
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        int l = 0, h = n - 1;
        while (l < h)
        {
            swap(mat[i][l], mat[i][h]);
            l++;
            h--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
}
void rotateMatrix90Anticlock2(vector<vector<int>> &mat)
{
    // logic : first transpose and then reverse each column .
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int l = 0, h = n - 1;
        while (l < h)
        {
            swap(mat[l][i], mat[h][i]);
            l++;
            h--;
        }
    }
}

void rotateMatrix90Clock2(vector<vector<int>> &mat)
{
    // logic : first transpose and then reverse each row .
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int l = 0, h = n - 1;
        while (l < h)
        {
            swap(mat[i][l], mat[i][h]);
            l++;
            h--;
        }
    }
}
void spiralTraversal(const vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right)
    {
        // Traverse top row
        for (int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;

        // Traverse bottom row  // handles if only one row or col
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
            bottom--;
        }

        // Traverse left column
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left++;
        }
    }
}
bool searchInSortedMatrix(const vector<vector<int>> &mat, int key)
{
    int r = mat.size();
    int c = mat[0].size();
    int i = 0;
    int j = c - 1;

    while (i < r && j >= 0)
    {
        if (mat[i][j] == key)
            return true;
        else if (mat[i][j] > key)
            j--;
        else
            i++;
    }
    return false; // key not found
}

// Follow-up Interview Questions / Variants:
// 1. What if the matrix is sorted row-wise but not column-wise?
// You cannot use this algorithm.

// You might do binary search on each row → O(r * log c).

// 2. What if the matrix is sorted column-wise but not row-wise?
// Do binary search on each column → O(c * log r).

// 3. Can you find the position (row, col) of the key instead of boolean?
// Simply return a pair (i, j) when found; else return (-1, -1).

// 4. How to find key in a matrix sorted both row-wise and column-wise using divide and conquer?
// Apply a recursive partitioning similar to quadtree search.

// Time complexity can be around O(log rc), but more complex to implement.

// 5. What if matrix is sorted but contains duplicates?
// Your search still works as it only moves based on comparisons.

// 6. How to find the minimum or maximum in such a matrix efficiently?
// Min is always top-left.

// Max is always bottom-right.

// . If the matrix is sorted row-wise but not column-wise
// You should run binary search on each row:

// Returns true if key is found in any row of a row-wise sorted matrix
bool searchRowWiseSorted(const vector<vector<int>> &mat, int key)
{
    int r = mat.size();
    if (r == 0)
        return false;
    int c = mat[0].size();

    for (int i = 0; i < r; i++)
    {
        int left = 0, right = c - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mat[i][mid] == key)
                return true;
            else if (mat[i][mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}
// Complexity: O(r × log c)

// Explanation: Binary search each row since each is sorted.

// 2. If the matrix is sorted column-wise but not row-wise
// You should run binary search on each column:

// Returns true if key is found in any column of a column-wise sorted matrix
bool searchColumnWiseSorted(const vector<vector<int>> &mat, int key)
{
    int r = mat.size();
    if (r == 0)
        return false;
    int c = mat[0].size();

    for (int j = 0; j < c; j++)
    {
        int top = 0, bottom = r - 1;
        while (top <= bottom)
        {
            int mid = top + (bottom - top) / 2;
            if (mat[mid][j] == key)
                return true;
            else if (mat[mid][j] < key)
                top = mid + 1;
            else
                bottom = mid - 1;
        }
    }
    return false;
}

int main()
{
    int r = 4, c = 4;
    int arr[r][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    spiralTraversal(matrix);
    // printMatrixInSnakePattern(matrix);
    // displayMatrix(arr,r,c);

    return 0;
}