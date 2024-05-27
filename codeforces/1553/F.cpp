#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define fi first
#define se second
#define REP(i, n) for (auto i = 0; i < (n); ++i)
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (auto i = (a); i >= (b); --i)
#define FORE(i, a, b) for (auto i = (a); i < (b); ++i)
#define MASK(x) (1LL << (x))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ALL(x) (x).begin(), (x).end()
#define left ___left 
#define right ___right 
#define __builtin_popcount __builtin_popcountll

template <class T> struct Fenwick_Tree {
    vector<T> bit;
    int n;
    Fenwick_Tree(int _n = 0) : n(_n), bit(_n + 5){}
    
    void clear() { fill(bit.begin(), bit.end(), T(0)); }

    void update(int u, T val) {
        for (; u <= n; u += u & -u) bit[u] += val;
    }
    
    T get(int u) {
        T ans = 0;
        for (; u; u -= u & -u) ans += bit[u];
        return ans; 
    }
    
    T get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

const int MAX = 3e5;

void you_make_it(void) {
    int n; cin >> n; 
    Fenwick_Tree <int> cnt(MAX);
    Fenwick_Tree <long long> tot(MAX), pref(MAX);
    for (int i = 1; i <= n; ++i) {
        static long long res = 0;
        int x; cin >> x; 
        res += 1LL * (i - 1 - cnt.get(x)) * x;
        res += 1LL * cnt.get(x) * x - tot.get(x);
        res += pref.get(x); 
        cnt.update(x, 1);
        pref.update(x, x);
        for (int l = x; l < MAX + 1; l += x) {
            int r = min(l + x - 1, MAX);
            res += pref.get(l, r) - 1LL * cnt.get(l, r) * l;
            tot.update(l, x);
        }
        cout << res << " ";
    }
}

signed main() {

#ifdef LOCAL
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);
#endif // LOCAL
    auto start_time = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test = 1;
    // cin >> test;

    for (int i = 0; i < test; ++i) {
        you_make_it();
        // cout << '\n';
    }
    auto end_time = chrono::high_resolution_clock::now();

    cerr << "\nExecution time : " << chrono::duration_cast <chrono::milliseconds> (end_time - start_time).count() << "[ms]" << endl;
    return (0 ^ 0);
}

// Dream it. Wish it. Do it.
