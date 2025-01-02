#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

#define int long long
// #define double long double
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

mt19937 rn(228);
int rnd() {return abs((int) rn());}

constexpr int N = 2e5 + 52;
constexpr int mod = 998244353;
constexpr long long inf = 1e18 + 556;
constexpr int T = 100;
constexpr int A = 26;
const double pi = acos(-1);
const double eps = pow(2, -20);

struct point {
    int x, c;
};

int n, k, l;
int tr[N << 2], ad[N << 2];

void push(int v, int vl, int vr) {
    if (ad[v] == 0) return;
    if (vr - vl == 1) {
        tr[v] += ad[v];
        ad[v] = 0;
    } else {
        tr[v] += ad[v];
        ad[v * 2 + 1] += ad[v];
        ad[v * 2 + 2] += ad[v];
        ad[v] = 0;
    }
}

void update(int l, int r, int x, int v = 0, int vl = 0, int vr = k + 1) {
    push(v, vl, vr);
    if (vr <= l || r <= vl) return;
    if (l <= vl && vr <= r) {
        ad[v] += x;
        push(v, vl, vr);
        return;
    }
    int vm = vl + vr >> 1;
    update(l, r, x, v * 2 + 1, vl, vm);
    update(l, r, x, v * 2 + 2, vm, vr);
    tr[v] = min(tr[v * 2 + 1], tr[v * 2 + 2]);
}

int get(int l, int r, int v = 0, int vl = 0, int vr = k + 1) {
    push(v, vl, vr);
    if (l >= vr || vl >= r) return inf;
    if (l <= vl && vr <= r) return tr[v];
    int vm = vl + vr >> 1;
    return min(get(l, r, v * 2 + 1, vl, vm), get(l, r, v * 2 + 2, vm, vr));
}

void retarded() {
    memset(tr, 0, sizeof tr);
    memset(ad, 0, sizeof ad);

    cin >> n >> k >> l;
    vector<vector<point>> a(k, vector<point> (0));
    for (int i = 0; i < n; i++) {
        int x, y, c; cin >> x >> y >> c;
        a[y].push_back({x, c});
    }

    vector<int> dp(k + 1, 0);

    for (int i = 1; i < k + 1; i++) {
        update(0, i, l);
        update(i, i + 1, dp[i - 1]);
        for (auto [x, c] : a[k - i]) {
            update(x + 1, i + 1, c);
        }

        if (a[k - i].size()) dp[i] = get(0, i + 1);
        else dp[i] = dp[i - 1];

        // for (int j = 0; j < i + 1; j++) cout << get(j, j + 1) << " \n"[j == i];
    }

    cout << dp[k] << endl;
}

signed main() {
    int tests = 1;

#ifdef LOCALIC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tests;
#else
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#endif

    while (tests --> 0) retarded();
}