#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row, col, count = 0;
    cin >> row >> col;
    char arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((arr[i][j] != 'B') && (arr[i][j] != 'W') && (arr[i][j] != 'G'))
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "#Black&White";
    }
    else
    {
        cout << "#Color";
    }
}
