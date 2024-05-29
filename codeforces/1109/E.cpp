#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 5;

int pr[N];
int n, mod;

int add(int a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
    return a;
}
int mul(int a, int b) { return 1LL * a * b % mod; }

struct SegTree {
    vector<int> st;           //
    vector<int> lzSum, lzSt;  // lazy of multiple x
    vector<int> sum;          // store sum of segment

    int n;
    SegTree() {}
    SegTree(int _n) {
        n = _n;
        st.assign(n * 4 + 5, 1);
        sum.assign(n * 4 + 5, 1);
        lzSt.assign(4 * n + 5, 1);
        lzSum.assign(4 * n + 5, 1);
    }

   private:
    void down(int i, vector<int>& sum, vector<int>& lz) {
        for (int j = 2 * i; j <= 2 * i + 1; ++j) {
            sum[j] = mul(sum[j], lz[i]);
            lz[j] = mul(lz[j], lz[i]);
        }
        lz[i] = 1;
    }
    void update(int i, int l, int r, int u, int v, int val1, int val2) {
        if (u > r || v < l) {
            return;
        }
        if (u <= l && r <= v) {
            sum[i] = mul(sum[i], val1);
            lzSum[i] = mul(lzSum[i], val1);
            st[i] = mul(st[i], val2);
            lzSt[i] = mul(lzSt[i], val2);
            return;
        }
        down(i, st, lzSt);
        down(i, sum, lzSum);
        int mid = (l + r) / 2;
        update(i * 2, l, mid, u, v, val1, val2);
        update(i * 2 + 1, mid + 1, r, u, v, val1, val2);
        sum[i] = add(sum[i * 2], sum[i * 2 + 1]);
    }
    void updateOne(int i, int l, int r, int p, int val1, int val2) {
        if (l == r) {
            st[i] = mul(st[i], val1);
            sum[i] = mul(st[i], val2);
            return;
        }
        int mid = (l + r) >> 1;
        down(i, st, lzSt);
        down(i, sum, lzSum);
        if (p <= mid) {
            updateOne(i * 2, l, mid, p, val1, val2);
        } else {
            updateOne(i * 2 + 1, mid + 1, r, p, val1, val2);
        }
        sum[i] = add(sum[i * 2], sum[i * 2 + 1]);
    }
    int get(int i, int l, int r, int u, int v) {
        if (u > r || v < l) {
            return 0;
        }
        if (u <= l && r <= v) {
            return sum[i];
        }
        down(i, st, lzSt);
        down(i, sum, lzSum);
        int mid = (l + r) >> 1;
        return add(get(i * 2, l, mid, u, v), get(i * 2 + 1, mid + 1, r, u, v));
    }

   public:
    void update(int l, int r, int val1, int val2) {
        update(1, 0, n - 1, l, r, val1, val2);
    }
    void updateOne(int p, int val1, int val2) {
        updateOne(1, 0, n - 1, p, val1, val2);
    }
    int get(int l, int r) { return get(1, 0, n - 1, l, r); }
};

struct BIT {
    int n;
    vector<int> bit;
    BIT() {}
    BIT(int _n) {
        n = _n;
        bit.assign(n + 5, 0);
    }
    void update(int i, int val) {
        for (i++; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }
    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
    int get(int i) {
        int res = 0;
        for (i++; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }
};

int fpow(int n, int k) {
    int ans = 1;
    for (int i = k; i > 0; i >>= 1) {
        if (i & 1) {
            ans = 1LL * ans * n % mod;
        }
        n = 1LL * n * n % mod;
    }
    return ans;
};
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int inv(int a) {
    int x, y;
    int g = gcd(a, mod, x, y);
    assert(g == 1);
    x = (x % mod + mod) % mod;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    cin >> n >> mod;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> factor;
    {
        int x = mod;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                factor.push_back(i);
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            factor.push_back(x);
        }
    }

    SegTree st(n);
    vector<BIT> bit(factor.size(), BIT(n));

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        int temp = 1;
        for (int j = 0; j < factor.size(); ++j) {
            int cnt = 0;
            while (x % factor[j] == 0) {
                x /= factor[j];
                cnt++;
            }
            bit[j].update(i, i, cnt);
        }
        st.update(i, i, a[i], x);
    }

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;

            int x1 = x;
            for (int i = 0; i < factor.size(); ++i) {
                int cnt = 0;
                while (x1 % factor[i] == 0) {
                    cnt++;
                    x1 /= factor[i];
                }
                bit[i].update(l, r, cnt);
            }
            st.update(l, r, x, x1);
        } else if (t == 2) {
            int p, x;
            cin >> p >> x;
            --p;

            int temp = 1;
            for (int i = 0; i < factor.size(); ++i) {
                int cnt = 0;
                while (x % factor[i] == 0) {
                    cnt++;
                    x /= factor[i];
                }
                bit[i].update(p, p, -cnt);
                int nval = bit[i].get(p);
                temp = mul(temp, fpow(factor[i], nval));
            }

            st.updateOne(p, inv(x), temp);
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << st.get(l, r) << '\n';
        }
    }
    return 0;
}