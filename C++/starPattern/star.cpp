#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//    *
//   ***
//  *****
// *******
void halfDimond(int r, int c)
{
    int mid = (c + 1) / 2;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {

            // if (j >= (mid + 1 - i) && j <= (mid - 1 + i))
            if (j >= (mid - (i - 1)) && j <= (mid + (i - 1)))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

//     *
//    * *
//   * * *
//  * * * *
// * * * * *
void halfDimondSpaced(int r, int c)
{
    int mid = (c + 1) / 2;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (j >= (mid - (i - 1)) && j <= (mid + (i - 1)))
            {
                if ((i % 2 != 0 && j % 2 != 0) || (i % 2 == 0 && j % 2 == 0))
                    cout << "*";
                else
                    cout << " ";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{

    halfDimondSpaced(5, 9);
    return 0;
}