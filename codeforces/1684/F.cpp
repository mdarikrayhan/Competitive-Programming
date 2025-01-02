#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 Rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 1e6 + 200;
const int M = 1e6;
const int inf = 2e9 + 3;
const ll INF = 1e18;

int T;
int n, m, a[N], mx[N], p[N];
vector<int> pos[N], v;

int getL(int i, int x) {
    if (pos[x][0] >= i) return 0;
    return *(lower_bound(all(pos[x]), i) - 1);
}

int getR(int i, int x) {
    if (pos[x].end()[-1] <= i) return n + 1;
    return *(upper_bound(all(pos[x]), i));
}

void solve() {
    cin >> n >> m;
    v.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
        pos[i].clear();
    }
    make_unique(v);
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
        pos[a[i]].push_back(i);
        mx[i] = i;
    }
    for (int i = 1, l, r; i <= m; ++i) {
        cin >> l >> r;
        mx[l] = max(mx[l], r);
    }
    for (int i = 2; i <= n; ++i) {
        mx[i] = max(mx[i], mx[i - 1]);
    }
    for (int i = 1, j = 1; i <= n; ++i) {
        p[i] = max(p[i - 1], getL(i, a[i]) + 1);
        //cerr << i << ": " << mx[i] << " " << p[i] << '\n';
    }
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        //[i, mx[i]]
        //p[mx[i]]
        if (p[mx[i]] > i) {
            j = max(j, p[mx[i]] - 1);
        }
    }
    if (j == 0) {
        cout << 0 << '\n';
        return;
    }
    multiset<int> R;
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        //i...j
        //cerr << i << " " << j << '\n';
        ans = min(ans, j - i + 1);
        int k = getR(j, a[i]);
        R.insert(mx[i]);
        int r = *R.rbegin();
        int l = lower_bound(mx + 1, mx + n + 1, i) - mx;
        if (getL(i, a[i]) >= l) {
            break;
        }
        if (k <= r) {
            j = k;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) solve();
}
