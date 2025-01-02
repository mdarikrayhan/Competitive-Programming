#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define BIT(n) (1ll << n)
#define GBIT(x, i) ((x >> i) & 1)
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define pb push_back
#define endl '\n'

#define fu(i, l, r) for (int i = (int) (l); i <= (int) (r); i++)
#define fd(i, r, l) for (int i = (int) (r); i >= (int) (l); i--)

typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef unsigned long long ull;
typedef long long ll;
typedef double dl;

const int MAXN = 77777 + 5;
const int MOD = 777777777;
const ll oo = 1ll * MOD * MOD;

#define int ll

int n, m;
bool good[4][4];

void rf() {
    cin >> n >> m;
    fu(i, 1, 3) fu(j, 1, 3) cin >> good[i][j];
}

int add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int tree[MAXN * 4][4][4];

void mergetree(int id) {
    memset(tree[id], 0, sizeof tree[id]);

    fu(i, 1, 3) fu(j, 1, 3) if (tree[id << 1][i][j])
        fu(u, 1, 3) fu(v, 1, 3) if (tree[id << 1 | 1][u][v])
            if (good[j][u])
                add(tree[id][i][v], 1ll * tree[id << 1][i][j] * tree[id << 1 | 1][u][v] % MOD);
}

void build(int id, int l, int r) {
    if (l == r) {
        fu(i, 1, 3) tree[id][i][i] = 1;
        return;
    }

    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    mergetree(id);
}

void upd(int id, int l, int r, int u, int val) {
    if (l == r) {
        fu(i, 1, 3) tree[id][i][i] = val == 0;
        tree[id][val][val] = 1;
        return;
    }

    int mid = l + r >> 1;
    if (mid >= u) upd(id << 1, l, mid, u, val);
    else upd(id << 1 | 1, mid + 1, r, u, val);

    mergetree(id);
}

void solve() {
    build(1, 1, n);
    while (m--) {
        int id, x; cin >> id >> x;
        upd(1, 1, n, id, x);
        int res = 0;
        fu(i, 1, 3) fu(j, 1, 3) add(res, tree[1][i][j]);
        cout << res << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #define task "prob"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    int ntest = 1;
//    cin >> ntest;
    fu(i, 1, ntest) rf(), solve();
}

