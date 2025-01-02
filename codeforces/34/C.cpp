#include <iostream>
#include <string>
using namespace std;
int main()
{
    string arr;
    cin >> arr;
    int a[100];
    int j = 0, s = 0;
    for (int i = 0; i < 100; i++)
    {
        a[i] = 0;
        s += 1;
        while (1)
        {
            if (j == arr.size())
                break;
            if (arr[j] == ',')
            {
                j++;
                break;
            }
            else
            {
                a[i] = 10 * a[i] + (arr[j] - '0');
                j++;
            }
        }

        if (j == arr.size())
            break;
    }
    for (int i = 0; i < s - 1; i++)
    {
        for (j = i + 1; j < s; j++)
        {
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    j = 0;
    for (int i = 0; i < s; i++)
    {
        if (i == s - 1)
        {
            if (j == 0)
                cout << a[i];
            else
                cout << a[i] - j << "-" << a[i];
        }
        else
        {
            if (a[i] == a[i + 1] - 1)
                j += 1;
            if (a[i] < a[i + 1] - 1)
            {
                if (j == 0)
                    cout << a[i] << ",";
                else
                    cout << a[i] - j << "-" << a[i] << ",";
                j = 0;
            }
        }
    }
}