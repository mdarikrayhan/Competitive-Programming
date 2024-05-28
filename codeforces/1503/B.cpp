#include <bits/stdc++.h>
#include <vector>
// #define endl         '\n'
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

bool vis[maxn][maxn];
int need[maxn][maxn];

void solve() {
    int n; cin >> n;
    vector<PII> v[3];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if ((i + j) % 2 == 0) v[1].pb({i, j});
            else v[2].pb({i, j});
        }
    }
    for (int i = 1; i <= n * n; i ++) {
        int x; cin >> x;
        if (x == 3) {
            if (v[1].size()) {
                cout << 1 << " " << v[1].back().fi << " " << v[1].back().se << endl;
                v[1].pop_back();
            } else {
                cout << 2 << " " << v[2].back().fi << " " << v[2].back().se << endl;
                v[2].pop_back();
            }
        } else if (x == 1) {
            if (v[2].size()) {
                cout << 2 << " " << v[2].back().fi << " " << v[2].back().se << endl;
                v[2].pop_back();
            } else {
                cout << 3 << " " << v[1].back().fi << " " << v[1].back().se << endl;
                v[1].pop_back();
            }
        } else {
            if (v[1].size()) {
                cout << 1 << " " << v[1].back().fi << " " << v[1].back().se << endl;
                v[1].pop_back();
            } else {
                cout << 3 << " " << v[2].back().fi << " " << v[2].back().se << endl;
                v[2].pop_back();
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    just Yoimiya;
}
