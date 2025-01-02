#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(),a.end()


void _()
{   
    ll n, k;
    cin >> n >> k;
    cout << ((k - 1) / (n - 1)) + k << endl;
}


signed main()
{
    int tc;
    cin >> tc;
    while(tc--)
        _();
}