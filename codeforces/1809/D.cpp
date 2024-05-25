#include <bits/stdc++.h>
#include <vector>
#define endl         '\n'
#define mem(a, k)    memset(a, k, sizeof(a))
#define debug(a)     cout << "Debuging...|" << #a << ": " << (a) << "\n";
#define SZ(x)        ((int)(x.size()))
#define all(x)       (x).begin(), (x).end()
#define allr(x)      (x).rbegin(), (x).rend()
#define just         return
#define Yoimiya      0
#define fi           first
#define se           second
#define pb           push_back
#define eb           emplace_back
#define mk           make_pair
#define int          long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > PII;
typedef pair< ll, ll > PLL;
typedef pair< double, double > PDD;

mt19937 mrand(random_device{}());
inline int rnd(int x) {return mrand() % x;}
inline int lowbit(int x) {return x & -x;}
ll qmi(ll a,ll k,ll p){ll res = 1;while (k) {if (k&1) res = res * a % p; k >>= 1;a = a * a % p;}return res;}
const double eps = 1e-8;
const double pi = acos(-1.0);
const ll INF = 1e18;
const int maxn = 1e2 + 10, maxm = 2 * maxn, mod = 1000000007;


void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> f(n + 1, INF);
    f[0] = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        a[i] = a[i - 1] + (s[i] == '1');
    }
    vector<int> b(n + 2);
    for (int i = n; i >= 1; i --) {
        b[i] = b[i +1] + (s[i] == '0');
    }
    int ans = INF;
    int del = (1e12) + 1;
    int swa = (1e12);
    for (int i = 0; i <= n; i ++) {
        ans = min(ans, del * (a[i] + b[i + 1]));
    }
    for (int i = 1; i < n; i ++) {
        if (s[i] == '1' && s[i + 1] == '0') ans = min(ans, swa + del * (a[i - 1] + b[i + 2]));
    }
    cout << ans <<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    just Yoimiya;
}
