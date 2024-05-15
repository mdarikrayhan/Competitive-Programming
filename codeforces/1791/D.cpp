// Code By Praham Periwal
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define for0 for (int i = 0; i < n; ++i)
#define for1 for (int i = 1; i <= n; ++i)
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debugpair(v)                                        \
    for (auto i : {1 : v})                                  \
    {                                                       \
        cerr << "(" << i.first << ", " << i.second << ") "; \
    }                                                       \
    cerr << endl;
#define debugvar(x) cerr << #x << " -> " << x << "\n";
#define debugvector(v)      \
    cerr << #v << " -> [ "; \
    for (const auto &i : v) \
        cerr << i << " ";   \
    cerr << "]\n";
#define fastio()
#else
#define var(x)
#define cont(v)
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#endif

void solve();
signed main()
{
    fastio() int test = 1;
    cin >> test;
    while (test--)
        solve();
}

void solve()
{
    int n, ans = 0;
    string s;
    cin >> n >> s;
    unordered_set<char> st1, st2;
    vector<int> pf(n), sf(n);
    for0
    {
        st1.insert(s[i]);
        pf[i] = st1.size();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        st2.insert(s[i]);
        sf[i] = st2.size();
    }
    for (int i = 0; i < n - 1; i++)
        ans = max(ans, pf[i] + sf[i + 1]);
    cout << ans << '\n';
}