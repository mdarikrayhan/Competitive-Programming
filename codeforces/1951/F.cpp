#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct fenwick_tree {
    vector<T> bit;
    int n;

    fenwick_tree(int n) : n(n), bit(n + 1) {}

    T sum(int x) {
        T ans = 0;
        for (; x > 0; x -= x & -x) {
            ans += bit[x];
        }
        return ans;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l);
    }

    void add(int x, T v) {
        for (++x; x <= n; x += x & -x) {
            bit[x] += v;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int64_t k; cin >> k;
        fenwick_tree<int> fen(n);
        vector<int> p(n), ip(n), cnt(n);
        int64_t inv = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i]; p[i]--;
            ip[p[i]] = i;
            inv += i - (cnt[i] = fen.sum(0, p[i]));
            fen.add(p[i], 1);
        }
        if (k < inv || k > 1LL * n * (n - 1) - inv || (k - inv) % 2 == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            k = (k - inv) / 2;
            vector<int> qp(n);
            for (int i = 0; i < n; i++) {
                if (cnt[i] < k) {
                    k -= cnt[i];
                } else {
                    for (int j = 0, v = i; j < i; j++) {
                        qp[j] = v--;
                        if (p[j] < p[i] && --k == 0) {
                            qp[i] = v--;
                        }
                    }
                    for (int j = i + 1; j < n; j++) {
                        qp[j] = j;
                    }
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << qp[ip[i]] + 1 << " \n"[i + 1 == n];
            }
        }
    }
}