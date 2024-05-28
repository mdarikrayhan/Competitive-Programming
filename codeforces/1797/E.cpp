#include <bits/stdc++.h>

#define ft first
#define sd second

using namespace std;

using ll = long long;
using ld = long double;
using pp = pair<int, int>;

template <typename T, typename F>
istream& operator>>(istream& s, pair<T, F>& a) {
    s >> a.ft >> a.sd;
    return s;
}

template <typename T, typename F>
ostream& operator<<(ostream& s, pair<T, F> a) {
    s << a.ft << ' ' << a.sd << (char)(10);
    return s;
}
template <typename T>
istream& operator>>(istream& s, vector<T>& a) {
    for (T& el : a) {
        s >> el;
    }
    return s;
}

template <typename T>
ostream& operator<<(ostream& s, vector<T>& a) {
    for (T& el : a) {
        s << el << ' ';
    }
    s << (char)(10);
    return s;
}

const int maxn = 5e6 + 11, maxlog = 5;
int phi[maxn];
int min_prime_del[maxn];
int primes[maxn], cnt_primes = 0;
int up[maxn][maxlog];
int depth[maxn];
int cnt_mpd[maxn];
int base[maxn];
int pw[maxn];
int timer = 0;


int lca(int a, int b) {
    if (a == 0 || b == 0) {
        return a + b;
    }
    for (int j = maxlog - 1; j >= 0; j--) {
        if (depth[a] - (1 << j) >= depth[b]) {
            a = up[a][j];
        }
    }
    for (int j = maxlog - 1; j >= 0; j--) {
        if (depth[b] - (1 << j) >= depth[a]) {
            b = up[b][j];
        }
    }
    if (a == b) {
        return a;
    }
    for (int j = maxlog - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}


void precount() {
    for (ll i = 2; i < maxn; i++) {
        if (min_prime_del[i] == 0) {
            min_prime_del[i] = i;
            primes[cnt_primes++] = i;
        }
        for (ll j = 0; j < cnt_primes; j++) {
            ll pr = primes[j];
            if (pr * i > maxn || pr > min_prime_del[i]) {
                break;
            }
            min_prime_del[pr * i] = pr;
        }
    }
    phi[1] = 1;
    for (ll i = 2; i < maxn; i++) {
        if (min_prime_del[i / min_prime_del[i]] == min_prime_del[i]) {
            cnt_mpd[i] = cnt_mpd[i / min_prime_del[i]] + 1;
            base[i] = base[i / min_prime_del[i]];
            pw[i] = pw[i / min_prime_del[i]] * min_prime_del[i];
        } else {
            cnt_mpd[i] = 1;
            base[i] = i / min_prime_del[i];
            pw[i] = min_prime_del[i] - 1;
        }
        phi[i] = pw[i] * phi[base[i]];
    }
    for (int v = 2; v < maxn; v++) {
        int prv = phi[v];
        depth[v] = depth[prv] + 1;
        up[v][0] = prv;
        for (int j = 1; j < maxlog; j++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
    }
}

const int maxlg = 1e5 + 11;
int tree[maxlg * 4], dtree[maxn * 4];
int arr[maxlg];

void build(int v, int l, int r) {
    if (l == r) {
        tree[v] = arr[l];
        dtree[v] = depth[arr[l]];
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m + 1, r);
    tree[v] = lca(tree[v * 2 + 1], tree[v * 2 + 2]);
    dtree[v] = dtree[v * 2 + 1] + dtree[v * 2 + 2];
}

pp get(int v, int l, int r, int lq, int rq) {
    if (lq > r || l > rq) {
        return {0, 0};
    }
    if (lq <= l && r <= rq) {
        return {tree[v], dtree[v]};
    }
    int m = (l + r) / 2;
    pp L = get(v * 2 + 1, l, m, lq, rq);
    pp R = get(v * 2 + 2, m + 1, r, lq, rq);
    return {lca(L.first, R.first), L.second + R.second};
}

void upd(int v, int l, int r, int id, int val) {
    if (id < l || r < id) {
        return;
    }
    if (l == r) {
        tree[v] = val;
        dtree[v] = depth[val];
        return;
    }
    int m = (l + r) / 2;
    upd(v * 2 + 1, l, m, id, val);
    upd(v * 2 + 2, m + 1, r, id, val);
    tree[v] = lca(tree[v * 2 + 1], tree[v * 2 + 2]);
    dtree[v] = dtree[v * 2 + 1] + dtree[v * 2 + 2];
}


void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<int> not_ones;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 1) {
            not_ones.insert(i);
        }
    }
    build(0, 0, n - 1);
    // cout << get(0, 0, n - 1, 0, n - 1) << '\n';
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        if (t == 1) {
            vector<set<int>::iterator> to_remove;
            for (auto it = not_ones.lower_bound(l); it != not_ones.end() && *it <= r; it++) {
                arr[*it] = phi[arr[*it]];
                upd(0, 0, n - 1, *it, arr[*it]);
                if (arr[*it] == 1) {
                    to_remove.push_back(it);
                }
            }
            for (auto it : to_remove) {
                not_ones.erase(it);
            }
        } else {
            // int D = 0;
            auto [lca_all, sum_d] = get(0, 0, n - 1, l, r);
            /*for (int i = l; i <= r; i++) {
                sum_d += depth[arr[i]];
                // ans = lca(ans, arr[i]);
            }*/
            cout << sum_d - depth[lca_all] * (r - l + 1) << '\n';
        }
    }
    // cout << clock();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    precount();
    solve();
}