#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int>arr(n + 1);
    for(int i = 1;i <= n;++i)
        cin >> arr[i];

    for(int i = 2;i <= n;++i)
    {
        if(arr[i] > arr[i - 1])
        {
            cout << "NO\n";
            return;
        }
    }

    int yes = 1;
    for(int i = 1;i <= n;++i)
    {
        if(arr[i] > n){yes = 0;break;}
        if(arr[arr[i]] < i){yes = 0;break;}
    }

    if(yes){cout << "YES\n";}
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}