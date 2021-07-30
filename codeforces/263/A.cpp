#include <iostream>
using namespace std;
int main()
{
    int i, j, x, y, arr[5][5];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (arr[i][j] == 1)
            {
                if (i <= 2)
                {
                    x = 2 - i;
                }
                else if (i > 2)
                {
                    x = i - 2;
                }
                if (j <= 2)
                {
                    y = 2 - j;
                }
                else if (j > 2)
                {
                    y = j - 2;
                }
                cout << x + y;
            }
        }
    }
}
