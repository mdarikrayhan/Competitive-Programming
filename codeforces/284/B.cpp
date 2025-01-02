// Hey stalker :)
#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007

#define by_DevanshuSharma        \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);

#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve()
{
    int ans = 0;
    bool flag = false;
    vector<int> vec;
    unordered_map<char, int> mpp;
    unordered_set<int> set;

    int n;
    cin >> n;
    string s;
    cin >> s;
    int temp = 0;
    for (auto it : s)
    {
        if (it == 'A')
        {
            ans++;
        }
        else if (it == 'I')
        {
            temp++;
        }
    }
    if (temp == 1)
    {
        cout << 1;
    }
    else if (temp > 1)
    {
        cout << 0;
    }
    else
    {
        cout << ans;
    }
}

int main()
{
    by_DevanshuSharma
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1, t = 0;
    // cin >> T;
    while (t++ < T)
    {
        // cout<<"Case #"<<ans<<":"<<' ';
        solve();
        // cout<<'\temp';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
}