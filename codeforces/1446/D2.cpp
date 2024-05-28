#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) (x).size())
#define pb push_back
#define mp make_pair
//#define int long long

using namespace std;
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> inline bool umin(T &a, const T &b) { if(a > b) { a = b; return 1; } return 0; }
template <typename T> inline bool umax(T &a, const T &b) { if(a < b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const ll base = 1e6 + 9;
const ll inf = 1e18;
const int MAX = 2e5 + 42;
const int LG = 20;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> dis(1, inf);

int brute(vector<int> a) {
    int n = sz(a);
    vector<int> cnt(n + 1);
    for(auto i : a) cnt[i]++;
    int mx = 0;
    int x = 0;
    for(int i = 1; i <= n; i++) {
        if(umax(mx, cnt[i])) x = i;
    }
    int ans = 0;
    for(int y = 1; y <= n; y++) {
        if(x == y) continue;
        vector<int> mn(2 * n + 1, n);
        mn[n] = -1;
        int p = 0;
        for(int i = 0; i < n; i++) {
            p += a[i] == x;
            p -= a[i] == y;
            umax(ans, i - mn[n + p]);
            umin(mn[n + p], i);
        }
    }
    return ans;
}

const int buben = 300;

int get(vector<int> a) {
    int n = sz(a);
    vector<int> cnt(n + 1);
    for(auto i : a) cnt[i]++;
    int mx = 0;
    int x = 0;
    for(int i = 1; i <= n; i++) {
        if(umax(mx, cnt[i])) x = i;
    }
    vector<vector<int>> pos(n + 1);
    for(int i = 0; i < n; i++) pos[a[i]].pb(i);
    for(int i = 1; i <= n; i++) pos[i].pb(n);
    int ans = 0;
    vector<int> b(n + 1);
    vector<int> mn(2 * n + 1, n);
    int SIZ = 0;
    auto calc = [&](int y) {
        for(int i = 1; i < SIZ; i++) assert(b[i - 1] <= b[i]);
//        cout << y << ": "; for(int i = 0; i < SIZ; i++) cout << b[i] << " "; cout << endl;
        int p = n; mn[p] = b[0] - 1;
        for(int j = 0; j < SIZ; j++) {
            int i = b[j];
            p += a[i] == x;
            p -= a[i] == y;
            if(j == 0 || mn[p] != b[j - 1])umax(ans, i - mn[p]);
            umin(mn[p], i);
        }
//        cout << ans << endl;
        for(int i = max(n - SIZ - 2, 0); i < min(2 * n + 1, n + SIZ + 3); i++) mn[i] = n;
    };
    for(int y = 1; y <= n; y++) {
        if(x == y) continue;
        if(cnt[y] < buben) continue;
        int p = n; mn[p] = -1;
        for(int i = 0; i < n; i++) {
            p += a[i] == x;
            p -= a[i] == y;
            umax(ans, i - mn[p]);
            umin(mn[p], i);
        }
        fill(all(mn), n);
    }
    vector<int> used(n);
    for(int y = 1; y <= n; y++) {
        if(x == y) continue;
        if(cnt[y] >= buben) continue;
        SIZ = 0;
        auto add = [&](int p) {
            if(0 <= p && p < n && !used[p]) {
                used[p] = 1;
                b[SIZ++] = p;
            }
        };
        for(int I = 0; I < cnt[y]; I++) {
            int c = cnt[y] + 1;
            int i = pos[y][I];
            int j = lower_bound(all(pos[x]), i) - pos[x].begin();
            j = j - c;
            if(j <= 0) {
                add(0);
                j = 0;
            }
            while(j <= cnt[x]) {
                int p = pos[x][j] - 1;
                if(p >= i) break;
                add(p);
                p++;
                add(p);
                j++;
            }
            add(i - 1); add(i);
            while(c > 0 && j <= cnt[x]) {
                int p = pos[x][j] - 1;
                if(p >= pos[y][I + 1]) break;
                add(p);
                p++;
                add(p);
                j++;
                c--;
            }
        }
        for(int i = 0; i < SIZ; i++) used[b[i]] = 0;
        calc(y);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    int ans = get(a);
    cout << ans << '\n';
}

/*
8
4 8 8 8 8 8 1 4
*/

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ttt = 1;
//    cin >> ttt;
    while(ttt--) {
        solve();
    }
}