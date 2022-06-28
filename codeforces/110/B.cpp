#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout<<'a'<<nl;
    }
    else if (n == 2)
    {
        cout<<"ab"<<nl;
    }
    else if (n == 3)
    {
        cout<<"abc"<<nl;
    }
    else
    {
        for (int i = 0; i < n / 4; i++)
        {
            cout<<"abcd";
        }

        int t = n % 4;
        if (t == 1)
        {
            cout<<'a'<<nl;
        }
        else if (t == 2)
        {
            cout<<"ab"<<nl;
        }
        else if (t == 3)
        {
            cout<<"abc"<<nl;
        }
    }
    return 0;
}