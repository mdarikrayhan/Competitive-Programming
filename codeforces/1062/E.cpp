#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

// #define int long long
#define endl "\n"

ostream& operator << (ostream& out, pair<int, int> a) {
    out << "| " << a.first << " " << a.second << " |";
    return out;
}

template<typename T>
istream& operator >> (istream& in, vector<T>& a) {
    for (int i = 0; i < a.size(); i++) in >> a[i];
    return in;
}

template<typename T>
ostream& operator << (ostream& out, vector<T>& a) {
    for (int i = 0; i < a.size(); i++) out << a[i] << " ";
    return out;
}


constexpr int N = 1e5 + 556;
constexpr int mod = 1e9 + 7;
constexpr long long inf = 1e9 + 556;
constexpr int T = 20;
constexpr int A = 26;
const double pi = acos(-1);

int n, q;

int bp[T][N];
int tin[N], tout[N];
int t1[N << 2], t2[N << 2], t3[N << 2];

int anc(int a, int b) {
    // a --> b
    if (tin[a] <= tin[b] && tin[b] <= tout[a]) return 1;
    else return 0;
}

int lca(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    if (anc(a, b)) return a;
    if (anc(b, a)) return b;

    for (int j = T - 1; j >= 0; j--) {
        if (!anc(bp[j][a], b)) {
            a = bp[j][a];
        }
    }
    return bp[0][a];
}

void build(int v = 0, int vl = 0, int vr = n + 1) {
    if (vr - vl == 1) {
        t1[v] = vl;
        t2[v] = vl;
        t3[v] = vl;
        return;
    }
    int vm = vl + vr >> 1;
    build(v * 2 + 1, vl, vm);
    build(v * 2 + 2, vm, vr);
    t1[v] = lca(t1[v * 2 + 1], t1[v * 2 + 2]);

    if (tin[t2[v * 2 + 1]] < tin[t2[v * 2 + 2]]) t2[v] = t2[v * 2 + 1];
    else t2[v] = t2[v * 2 + 2];
    if (tin[t3[v * 2 + 1]] > tin[t3[v * 2 + 2]]) t3[v] = t3[v * 2 + 1];
    else t3[v] = t3[v * 2 + 2];
}

int get(int l, int r, int v = 0, int vl = 0, int vr = n + 1) {
    if (l >= vr || vl >= r) return 0;
    if (l <= vl && vr <= r) return t1[v];
    int vm = vl + vr >> 1;
    int lans = get(l, r, v * 2 + 1, vl, vm);
    int rans = get(l, r, v * 2 + 2, vm, vr);
    return lca(lans, rans);
}

void update(int p, int x, int v = 0, int vl = 0, int vr = n + 1) {
    if (vr - vl == 1) {
        t1[v] = x;
        return;
    }
    int vm = vl + vr >> 1;
    if (p < vm) update(p, x, v * 2 + 1, vl, vm);
    else update(p, x, v * 2 + 2, vm, vr);
    t1[v] = lca(t1[v * 2 + 1], t1[v * 2 + 2]);
}

int getmn(int l, int r, int v = 0, int vl = 0, int vr = n + 1) {
    if (l >= vr || vl >= r) return 0;
    if (l <= vl && vr <= r) return t2[v];
    int vm = vl + vr >> 1;
    int lans = getmn(l, r, v * 2 + 1, vl, vm);
    int rans = getmn(l, r, v * 2 + 2, vm, vr);
    if (lans == 0) return rans;
    if (rans == 0) return lans;
    if (tin[lans] < tin[rans]) return lans;
    else return rans;
}

int getmx(int l, int r, int v = 0, int vl = 0, int vr = n + 1) {
    if (l >= vr || vl >= r) return 0;
    if (l <= vl && vr <= r) return t3[v];
    int vm = vl + vr >> 1;
    int lans = getmx(l, r, v * 2 + 1, vl, vm);
    int rans = getmx(l, r, v * 2 + 2, vm, vr);
    if (lans == 0) return rans;
    if (rans == 0) return lans;
    if (tin[lans] > tin[rans]) return lans;
    else return rans;
}

void talentless() {
    memset(bp, 0, sizeof bp);
    fill(tin, tin + N, -1);
    fill(tout, tout + N, inf);

    cin >> n >> q;
    vector<vector<int>> gr(n + 1, vector<int> (0));
    for (int i = 2; i < n + 1; i++) {cin >> bp[0][i]; gr[bp[0][i]].push_back(i);}

    int t = 0;

    vector<int> d(n + 1, 0);

    auto dfs1 = [&](auto dfs, int v) -> void {
        tin[v] = t++;
        for (int to : gr[v]) {
            d[to] = d[v] + 1;
            dfs(dfs, to);
        }
        tout[v] = t++;
    };

    dfs1(dfs1, 1);

    for (int j = 1; j < T; j++) for (int i = 1; i < n + 1; i++) bp[j][i] = bp[j - 1][bp[j - 1][i]];

    build();

    while (q --> 0) {
        int l, r; cin >> l >> r; r++;
        int p1 = getmn(l, r);
        int p2 = getmx(l, r);


        update(p1, 0);
        int ans1 = get(l, r);
        update(p1, p1);

        update(p2, 0);
        int ans2 = get(l, r);
        update(p2, p2);

        if (d[ans1] > d[ans2]) cout << p1 << " " << d[ans1] << endl;
        else cout << p2 << " " << d[ans2] << endl;
    }
}

signed main() {
    int tests = 1;

#ifdef LOCALIC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tests;
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#endif

    while (tests --> 0) talentless();
}