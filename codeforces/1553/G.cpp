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

struct disjoint_set {
    int n; vector <int> lab;

    disjoint_set(int n) : n(n), lab(n + 1, -1) {}

    int find(int u) {
        assert(0 < u && u < n + 1);
        return lab[u] < 0 ? u : lab[u] = find(lab[u]);
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return false;

        if(lab[u] > lab[u]) swap(u, v);

        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool isRoot(int u) { 
        return u == find(u);
    }

    int size(int u) {
        return -lab[u];
    }
};

const int MAX = 1e6 + 5;

int n, q, a[MAX], lpf[MAX];
vector <int> divi[MAX], pdiv[MAX], primes;
set <pair <int, int>> spe; 

void init(void) {
    for (int i = 2; i < MAX; ++i) {
        if(lpf[i] == false) {
            primes.emplace_back(i);
            lpf[i] = i;
        }

        for (int j = 0; j < (int) primes.size() and primes[j] <= lpf[i] and 1LL * i * primes[j] < MAX; ++j) {
            lpf[i * primes[j]] = primes[j];
        }
    }

    for (int i = 1; i < MAX; ++i) {
        int x = i;
        while(x > 1) {
            int p = lpf[x];
            while(x % p == 0) {
                x /= p;
            }
            divi[i].emplace_back(p);
        }
    }
}

void you_make_it(void) {
    cin >> n >> q; 
    disjoint_set dsu(n);
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (auto p : divi[a[i]]) {
            pdiv[p].emplace_back(i);
        }
    }

    for (int i = 2; i < MAX; ++i) {
        for (int j = 0; j < (int) pdiv[i].size() - 1; ++j) {
            dsu.merge(pdiv[i][j], pdiv[i][j + 1]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        vector <int> merge = divi[a[i]];
        merge.insert(merge.end(), divi[a[i] + 1].begin(), divi[a[i] + 1].end());
        for (auto x : merge) for (auto y : merge) if(x < y) {
            if(pdiv[x].empty() or pdiv[y].empty()) continue;
            int u = dsu.find(pdiv[x][0]), v = dsu.find(pdiv[y][0]);
            // cerr << u << " " << v << endl;
            if(u == v) continue;
            if(u > v) {
                swap(u, v);
            }
            spe.insert(make_pair(u, v));
        }
    }


    while(q--) {
        int s, t; cin >> s >> t; 
        if(dsu.same(s, t)) {
            cout << 0 << '\n'; 
            continue;
        } 

        int ans = 2;
        for (auto x : divi[a[s]]) {
            for (auto y : divi[a[t]]) {
                int u = dsu.find(pdiv[x][0]), v = dsu.find(pdiv[y][0]);
                if(u > v) swap(u, v);
                if(spe.count(make_pair(u, v))) {
                    ans = 1; break;
                }
            }
            if(ans == 1) break;
        }
        cout << ans << '\n';
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
