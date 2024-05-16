#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
using namespace std;
using ll = long long;
#define int ll
#define endl '\n'
const int mod = 1000000007;
// clang-format off
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// clang-format on

void solve()
{
    ll t, m, n, A;
    string h;
    cin >> n;
    map<string, int> mp;
    bool a = 0, b = 0, c = 0;
    while (n--)
    {
        cin >> A >> h;
        int cnta = 0, cntb = 0, cntc = 0;
        for (auto &i : h)
        {
            a |= (i == 'A');
            b |= (i == 'B');
            c |= (i == 'C');
            cnta += (i == 'A');
            cntb += (i == 'B');
            cntc += (i == 'C');
        }
        h = "";
        if (cnta)
            h += "A";
        if (cntb)
            h += "B";
        if (cntc)
            h += "C";
        dbg(h);
        if (mp.count(h))
        {
            mp[h] = min(mp[h], A);
        }
        else
        {
            mp[h] = A;
        }
    }
    dbg(a, b, c);
    if (!a || !b || !c)
    {
        cout << "-1\n";
        return;
    }
    int ans = 1e18;
    dbg(mp);
    if (mp["ABC"])
        ans = min(ans, mp["ABC"]);
    if (mp["AB"] && mp["C"])
        ans = min(ans, mp["AB"] + mp["C"]);
    if (mp["BC"] && mp["A"])
        ans = min(ans, mp["BC"] + mp["A"]);
    if (mp["AC"] && mp["B"])
        ans = min(ans, mp["AC"] + mp["B"]);
    if (mp["A"] && mp["C"] && mp["B"])
        ans = min(ans, mp["A"] + mp["C"] + mp["B"]);
    if (mp["AB"] && mp["AC"])
        ans = min(ans, mp["AB"] + mp["AC"]);
    if (mp["AB"] && mp["BC"])
        ans = min(ans, mp["BC"] + mp["AB"]);
    if (mp["AC"] && mp["BC"])
        ans = min(ans, mp["BC"] + mp["AC"]);
    cout << ans << endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    // cin >> t;
    // while (t--)
    {
        solve();
    }
    return 0;
}