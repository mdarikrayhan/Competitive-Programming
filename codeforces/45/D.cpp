#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(i, a, n) for (int i = (a); i <= (n); i++)
#define ff first
#define ss second
#define UWU ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

const ll N = 1e5 + 5, mod = 998244353, p1 = 31, mod2 = 1e9 + 9, p2 = 37, M = 9e6 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(all(a));
    int cur = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cur = max(cur + 1, a[i].first.first);
        ans[a[i].second] = cur;
        for (int j = i + 1; j < n; j++)
            if (a[j].first.first == cur)
                a[j].first.first++;
        sort(all(a));
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
int main()
{
    UWU;
    int tc = 1;
    // cin >> tc;
    cout << fixed << setprecision(30);
    while (tc--)
    {

        solve();
    }
}
/*
9 10
9 10

*/