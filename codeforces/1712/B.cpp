#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpci vector<pair<char, int>>
#define vpsi vector<pair<string, int>>
#define mii map<int, int>
#define mll map<ll, ll>
#define sei set<int>
#define sec set<char>
#define pqi priority_queue<int>
#define pql priority_queue<ll>
#define pqs priority_queue<int, vi, greater<int>>
#define pb push_back
#define pob pop_back
#define pbf push_front
#define pof pop_front
#define re return
#define ff first
#define ss second
#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define scl(x) scanf("%lld", &x)
#define scc(x) scanf("%c", &x)
#define pr(x) printf("%d ", x)
#define prl(x) printf("%lld", x)
#define prc(x) printf("%c", x)
#define prd(x) printf("%d\n", x)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep1(i, a, b) for (int i = a; i <= b; i++)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define gc getchar()
#define test     \
    int T;       \
    cin >> T;    \
    while (T--)  \
    {            \
        solve(); \
    }
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define INF = 1e18
#define FINF = -1e18
#define ld long double
const int mod = 998244353;
inline int gcd(int a, int b)
{
    re b == 0 ? a : gcd(b, a % b);
}
inline int lcm(int a, int b)
{
    re a / gcd(a, b) * b;
}
ll qmi(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    re res;
}
ll inv(int x)
{
    re qmi(x, mod - 2);
}
inline void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
inline int read()
{
    char c = gc;
    int x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            s = -1;
        c = gc;
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = gc;
    }
    re x;
}
void solve()
{
    int n;
    cin >> n;
    vi a;
    if (n % 2 != 0)
    {
        a.pb(1);
        for (int i = 2; i <= n; i += 2)
        {
            a.pb(i + 1);
            a.pb(i);
        }
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
        {
            a.pb(i + 1);
            a.pb(i);
        }
    }
    for (auto k : a)
        cout << k << " ";
    cout << endl;
    a.clear();
}
int main()
{
    IOS;
    test;
    re 0;
}
