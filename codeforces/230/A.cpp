// This code is written by AryanSingh77
#include <bits/stdc++.h>
using namespace std;

#define ll long long
//>>>>>>>--SOLVE function--<<<<<<<
bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first < b.first)
        return true;
    if (a.first > b.first)
    {
        return false;
    }
    if (a.second > b.second)
        return true;
    return false;
}
void solve()
{
    ll s, n;
    cin >> s >> n;
    vector<pair<ll, ll>> v;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), comp);
    int flag = 0;
    for (auto it : v)
    {
        if (s > it.first)
        {
            s += it.second;
        }
        else
        {
            flag = 1;
            break;
        }
        // cout << it.first << " " << it.second << "\n";
    }
    if (flag == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}