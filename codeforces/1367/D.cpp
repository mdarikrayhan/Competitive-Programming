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
    ll t, m, n, a, b;
    string h;
    cin >> h;
    cin >> n;
    sort(h.rbegin(), h.rend());
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    map<char, int> mp;
    for (auto &i : h)
        mp[i]++;
    char ch = 'z';
    int i = 0;
    vector<char> ans(n);
    int cnt = 0;
    dbg(mp);
    while (1)
    {
        dbg(v);
        if (v.size() == 0)
            break;
        vector<int> idx;
        vector<pair<int, int>> v2;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == 0)
                idx.push_back(v[i].second);
        }
        while (mp[ch] < idx.size())
            ch--;

        for (int i = 0; i < idx.size(); i++)
            ans[idx[i]] = ch;
        ch--;
        for (int i = 0; i < idx.size(); i++)
        {
            for (int j = idx.size(); j < v.size(); j++)
            {
                if (v[i].first > 0)
                    continue;
                if (v[j].first)
                {
                    dbg(i, j, v[i]);
                    v[j].first -= abs(v[j].second - v[i].second);
                }
            }
        }
        for (int i = idx.size(); i < v.size(); i++)
        {
            v2.push_back(v[i]);
        }
        sort(v2.begin(), v2.end());
        v = v2;
        dbg(idx);
    }
    for (auto &i : ans)
        cout << i;
    cout << endl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}