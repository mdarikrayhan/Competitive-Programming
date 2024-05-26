#include <bits/stdc++.h>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define fix(a, k) ((a % k) + k) % k
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()
#define ll long long
#define ull unsigned long long
using namespace std;
void File() // low l r high
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
vector<ll> tot;
void solve()
{
    ll l, r;
    cin >> l >> r;
    ll e = upper_bound(all(tot), r) - tot.begin();
    ll s = upper_bound(all(tot), l - 1) - tot.begin();
    // for(int i=0;i<5;i++)
    // {
    //     cout<<tot[i]<<' ';
    // }
    // cout<<'\n';
    cout << e - s + (ll)sqrtl(r) - (ll)sqrtl(l-1) << '\n';
}

int main()
{
    IOS;
    File();
    int t = 1;
    cin >> t;
    __int128_t lim = 1e18 + 5;
    set<ll> st;
    for (int i = 2; i <= 1e6; i++)
    {
        __int128_t num = i;
        while (num * i <= 1e18)
        {
            num *= i;
            st.insert(num);
        }
    }
    for (auto &it : st)
    {
        ll sq = sqrtl(it);
        if (sq * sq != it)
        {
            tot.push_back(it);
        }
    }
    while (t--)
    {
        solve();
    }
} // 15