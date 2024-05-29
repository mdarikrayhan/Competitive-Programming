#ifdef LOCAL
#include "include/include.h"
#else
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#endif
#ifndef DEBUG
#undef deb
#undef debm
#undef debseg
#define deb(...)
#define debm(...)
#define debseg(...)
#endif

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_set;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxHeap = priority_queue<T>;
#define int long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)s.size()
#define testcases \
    cin >> tt;    \
    for (i = 1; i <= tt; i++)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
using longer = __int128_t;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
const int INF = LONG_LONG_MAX;
const int M = 998244353;

/*
Pass maxn as LARGER than actual max size
Ensure all array inputs are in [0, MOD)
Create global instance of struct NTT
*/
using i32 = int32_t;
using i64 = int64_t;
template <i32 maxn>
struct NTT {
    constexpr static i32 lg2(i32 n) {
        if (n == 1) return 0;
        return 32 - __builtin_clz(n - 1);
    }

    const static i32 MAXN = 1 << lg2(maxn), MOD = 998244353, root = 3;
    i32 rev[MAXN], rt[MAXN];

    i32 mul(i32 a, i32 b) { return (i64)a * b % MOD; }
    i32 sub(i32 a, i32 b) { return b > a ? a - b + MOD : a - b; }
    i32 add(i32 a, i32 b) { return a + b >= MOD ? a + b - MOD : a + b; }

    i32 binExp(i32 base, i64 exp) {
        if (exp == 0)
            return 1;
        return mul(binExp(mul(base, base), exp / 2), exp & 1 ? base : 1);
    }
    NTT() {
        rt[1] = 1;
        for (i32 k = 1; k < lg2(MAXN); k++) {
            i32 z[] = {1, binExp(root, (MOD - 1) >> (k + 1))};
            for (i32 i = (1 << k); i < 2 << k; i++)
                rt[i] = mul(rt[i / 2], z[i & 1]);
        }
    }
    void ntt(i32 *a, i32 n) {
        for (i32 i = 0; i < n; i++)
            rev[i] = (rev[i / 2] | (i & 1) << lg2(n)) / 2;
        for (i32 i = 0; i < n; i++)
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        for (i32 k = 1; k < n; k *= 2)
            for (i32 i = 0; i < n; i += 2 * k)
                for (i32 j = 0; j < k; j++) {
                    i32 z = mul(rt[j + k], a[i + j + k]);
                    a[i + j + k] = sub(a[i + j], z);
                    a[i + j] = add(a[i + j], z);
                }
    }
    i32 in[2][MAXN];
    vector<int> multiply(const vector<int> &a, const vector<int> &b) {
        if (a.empty() || b.empty())
            return {};
        int size = sz(a) + sz(b) - 1, n = 1 << lg2(size);
        fill(in[0], in[0] + n, 0), fill(in[1], in[1] + n, 0);
        copy(all(a), in[0]), copy(all(b), in[1]);
        ntt(in[0], n), ntt(in[1], n);
        int invN = binExp(n, MOD - 2);
        for (int i = 0; i < n; i++)
            in[0][i] = mul(mul(in[0][i], in[1][i]), invN);
        reverse(in[0] + 1, in[0] + n);
        ntt(in[0], n);
        return vector<int>(in[0], in[0] + size);
    }
};

NTT<20'100> ntt;

int solveQuery(vi &arr, int k) {
    int n = sz(arr);
    for (int i = 0; i < n; i++) {
        arr[i] %= M;
        arr[i] += M;
        arr[i] %= M;
    }

    // deb(arr);

    /*  (1 + x)(1 + 2x) = (1 + 3x + 2x^2)
        (1 + x * a1) (1 + x * a2) ... (1 + x * an)
        (deg = 5) * (deg = 5)
        T(10) + 2 * T(5) + (5 + 5) log (5 + 5)
        T(n) = 2 * T(n / 2) + n log n
        T(n) = n log^2 n
    */
    
    function<vi(int, int)> dnq = [&] (int l, int r) {
        if (l == r) {
            return vi({1, arr[l]});
        }
        int m = (l + r) / 2;
        auto left = dnq(l, m);
        auto right = dnq(m + 1, r);
        auto product = ntt.multiply(left, right);
        return product;
    };

    auto prod = dnq(0, n - 1);
    return prod[k];
}       

void solve(__attribute__((unused)) int tt) {
    int n, k; cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int q, i ,d; cin >> q >> i >> d; i--;
            vi cpy = arr;
            cpy[i] = d;

            for (int j = 0; j < n; j++) {
                cpy[j] = q - cpy[j];
            }
            cout << solveQuery(cpy, k) << "\n";
        } else {
            int q, l, r, d; cin >> q >> l >> r >> d; l--; r--;
            vi cpy = arr;
            for (int i = l; i <= r; i++) {
                cpy[i] += d;
            }
            for (int i = 0; i < n; i++) {
                cpy[i] = q - cpy[i];
            }
            cout << solveQuery(cpy, k) << '\n';
        }
    }
}

int32_t main() {
#ifdef LOCAL
    chrono::time_point<chrono::steady_clock> start, end;
    start = chrono::steady_clock::now();
#else
    fast;
#endif

    int tt = 1;
    int i = 1;
    // testcases
    solve(i);

#ifdef LOCAL
    end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cerr << "Took " << 1e3 * elapsed_seconds.count() << "ms " << endl;
#endif
}