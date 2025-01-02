#include <iostream>
#include <strings.h>
#include <vector>
using namespace std;

int main()
{
    vector<string> s(8);

    for (int i = 0; i < 8; i++)
    {
        cin >> s[i];
    }
    int flag = 1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (s[i][j] == s[i][j + 1])
            {
                flag = 0;
            }
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}