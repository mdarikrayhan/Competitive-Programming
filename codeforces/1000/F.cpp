#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void print() { cout << '\n'; }
template <typename T, typename...Args>
void print(T t, Args...args) { cout << t << ' '; print(args...); }
using P = pair<int, int>;
using ll = long long;
const int N = 500010;
// function

template <typename T> void chmax(T &x, T y) { x = max(x, y); }
template <typename T> void chmin(T &x, T y) { x = min(x, y); }

#define ls u << 1
#define rs u << 1 | 1
#define mid ((l + r) >> 1)

int mn[N << 2], pre[N], a[N], ans[N], n;

void modify (int u, int l, int r, int p, int v) {
    if (l == r) {
        mn[u] = v;
        return;
    }
    if (p <= mid) {
        modify(ls, l, mid, p, v);
    } else {
        modify(rs, mid + 1, r, p, v);
    }
    mn[u] = min(mn[ls], mn[rs]);
}

void modify (int p, int v) {
    modify(1, 1, n, p, v);
}

int query (int u, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return mn[u];
    }
    int res = N;
    if (x <= mid) {
        chmin(res, query(ls, l, mid, x, y));
    }
    if (y > mid) {
        chmin(res, query(rs, mid + 1, r, x, y));
    }
    return res;
}

int query (int l, int r) {
    return query(1, 1, n, l, r);
}

void solve(){
    cin >> n;
    
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    
    int q;
    cin >> q;
    
    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; i ++) {
        auto& [l, r, id] = queries[i];
        cin >> l >> r;
        id = i;
    }
    
    sort (all(queries), [&] (auto& a, auto& b) {
        return a[1] < b[1];
    });
    
    set<int> s;
    for (int i = 1, j = 0; i <= n && j < q; i ++) {
        int x = a[i];
        if (!pre[x]) {
            s.insert(i);
        } else {
            s.erase(pre[x]);
            modify(pre[x], n + 1);
            modify(i, pre[x]);
        }
        pre[x] = i;
        
        while (j < q && queries[j][1] == i) {
            auto& [l, r, id] = queries[j ++];
            int p = query(l, r);
            if (p >= l) {
                continue;
            }
            if (!p) {
                ans[id] = a[*s.rbegin()];
            } else {
                ans[id] = a[p];
            }
        }
    }
    
    for (int i = 0; i < q; i ++) {
        cout << ans[i] << '\n';
    }
}

int main() {
	ios
	int t = 1; //cin >> t;
	while(t --) solve();

	return 0;
}