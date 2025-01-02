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
    cin >> n >> h;
    int lo = n / 26;
    if (n % 26)
        lo++;
    int hi = n;
    vector<pair<int, char>> v(26);
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[h[i]]++;
    for (auto &i : mp)
        v.push_back({i.second, i.first});
    sort(v.rbegin(), v.rend());
    int cur = 0, avail = 0;
    int ans2 = 1e9;
    dbg(v);
    int ans = 0;
    for (int i = lo; i <= hi; i++)
    {
        cur = 0, avail = 0;
        if (n % i)
            continue;
        for (int j = 0; j < n / i; j++)
        {
            if (v[j].first > i)
            {
                cur += v[j].first - i;
                avail += v[j].first - i;
            }
            else
            {
                int tp = i - v[j].first;
                int tp2 = min(avail, tp);
                avail -= tp2;
                tp -= tp2;
                cur += tp;
            }
        }
        if (ans2 > cur)
        {
            ans2 = min(ans2, cur);
            ans = i;
        }
    }
    dbg(ans);
    cout << ans2 << endl;
    vector<pair<int, char>> v1;
    for (auto &i : mp)
        v1.push_back({i.second, i.first});
    sort(v1.rbegin(), v1.rend());
    char ch = 'a';
    int x = max(0ll, (n / ans) - (ll)v1.size());
    for (int i = 0; i < x; i++)
    {
        while (mp[ch])
            ch++;
        v1.push_back({0, ch});
        ch++;
    }
    while (v1.size() != n / ans)
        v1.pop_back();
    dbg(v1);
    map<char, bool> mp2;
    for (auto &i : v1)
    {
        mp2[i.second] = true;
    }
    dbg(mp2);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (mp2[h[i]])
        {
            if (mp[h[i]] > ans)
            {
                q.push(i);
                mp[h[i]]--;
            }
        }
        else
        {
            q.push(i);
            mp[h[i]]--;
        }
    }
    dbg(q);
    dbg(mp2);

    for (int i = 0; i < n; i++)
    {
        while (mp2[h[i]] && mp[h[i]] < ans)
        {
            int top = q.front();
            q.pop();
            h[top] = h[i];
            mp[h[i]]++;
        }
    }
    dbg(q);
    ch = 'a';
    while (q.size())
    {
        while (mp[ch] < ans)
        {
            int top = q.front();
            q.pop();
            h[top] = ch;
            mp[ch]++;
        }
        while (mp[ch])
            ch++;
    }
    cout << h << endl;
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