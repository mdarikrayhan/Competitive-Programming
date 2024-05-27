//by 72
#include<bits/stdc++.h>
#define F(i, a, b) for(int i = a; i <= b; i ++)
#define Fd(i, a, b) for(int i = a; i >= b; i --)
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int inf = 1e18;
typedef array<int, 3> a3; 
typedef long long ll;
typedef unsigned long long ull;
const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();
ull shift(ull x) {
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}
int n;
ull w[N];
vector<int> ed[N];
ull get_hash(int u, int f) {
    ull res = 1;
    for(auto v : ed[u]) {
        if(v == f) continue;
        res += shift(get_hash(v, u));
    }
    w[u] = res;
    return res;
}
void sol() {
    cin >> n;
    F(i, 1, n) ed[i].clear();
    F(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        ed[u].pb(v), ed[v].pb(u);
    }
    // if(n <= 3) {
    //     cout << "YES\n";
    //     return;
    // }
    get_hash(1, 1);
    int qaq = 1, lst = 1;
    while(1) {
        map<ull, int> cnt;
        int tmp = 0;
        for(auto v : ed[qaq]) {
            if(v == lst) continue;
            cnt[w[v]] ++;
            tmp ++;
        } 
        int ans = -1;
        for(auto [x, y] : cnt) {
            if(y % 2) {
                if(ans != -1) {
                    cout << "NO\n";
                    return;
                }
                ans = x;
            }
        }
        if(tmp % 2 == 0) break;
        for(auto v : ed[qaq]) {
            if(v == lst) continue;
            if(w[v] == ans) {
                lst = qaq;
                qaq = v;
                break;
            }
        }
    }
    cout << "YES\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t --) sol();
    return 0;
}
//sldl