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
    int n, a, b, k;
    string s;
    cin >> n >> a >> b >> k >> s;
    int cnt = 0;
    int cur = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            cnt++;
        else
        {
            if (cnt >= b)
            {
                pq.push({-cnt, i - cnt});
                cur += cnt / b;
            }
            cnt = 0;
        }
    }
    if (cnt >= b)
    {
        pq.push({-cnt, n - cnt});
        cur += cnt / b;
    }
    debug(cur);
    vector<int> ans;
    while (!pq.empty() && cur >= a)
    {
        auto p = pq.top();
        pq.pop();
        int i = p.second, sz = -p.first;
        cur--;
        ans.push_back(i + b - 1);
        sz -= b;
        if (sz >= b)
            pq.push({-sz, i + b});
    }
    cout << ans.size() << "\n";
    for (int e : ans)
        cout << e + 1 << " ";
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

*/