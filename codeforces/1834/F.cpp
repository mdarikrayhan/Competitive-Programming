#include <bits/stdc++.h>

//#define int long long
#define ld long double
#define F first
#define S second
using namespace std;
int maxn;

int maxpow2(int x) {
    int y = 1;
    while (y < x) {
        y <<= 1;
    }
    return y;
}

vector<vector<int>> tr1, tr2;

int getans1(int v, int lv, int rv, int l, int r, int x) {
    if (lv >= l && rv <= r) {
        return tr1[v].end() - upper_bound(tr1[v].begin(), tr1[v].end(), x);
    }
    if (lv >= r || rv <= l) {
        return 0;
    }
    int mid = (lv + rv) / 2;
    return getans1(v * 2, lv, mid, l, r, x) + getans1(v * 2 + 1, mid, rv, l, r, x);
}

int getans2(int v, int lv, int rv, int l, int r, int x) {
    if (lv >= l && rv <= r) {
        return tr2[v].end() - upper_bound(tr2[v].begin(), tr2[v].end(), x);
    }
    if (lv >= r || rv <= l) {
        return 0;
    }
    int mid = (lv + rv) / 2;
    return getans2(v * 2, lv, mid, l, r, x) + getans2(v * 2 + 1, mid, rv, l, r, x);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    maxn = maxpow2(n);
    tr1.resize(maxn * 2);
    tr2.resize(maxn * 2);
    vector<int> id(n), rid(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        id[x] = i;
        tr1[i + maxn] = {i - x};
        rid[x] = n - i - 1;
        tr2[n - i - 1 + maxn] = {n - i - 1 - x};
        if (i > x) {
            cnt++;
        }
    }
    for (int i = maxn - 1; i >= 1; --i) {
        tr1[i].resize(tr1[i * 2].size() + tr1[i * 2 + 1].size());
        tr2[i].resize(tr2[i * 2].size() + tr2[i * 2 + 1].size());
        merge(tr1[i * 2].begin(), tr1[i * 2].end(), tr1[i * 2 + 1].begin(), tr1[i * 2 + 1].end(), tr1[i].begin());
        merge(tr2[i * 2].begin(), tr2[i * 2].end(), tr2[i * 2 + 1].begin(), tr2[i * 2 + 1].end(), tr2[i].begin());
    }
    cout << cnt << '\n';
    int sd = 0;
    bool rev = 0;
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 2) {
            int k;
            cin >> k;
            k %= n;
            if (!rev) {
                sd += k;
                sd %= n;
            } else {
                sd -= k;
                sd += n;
                sd %= n;
            }
        } else if (t == 1) {
            int k;
            cin >> k;
            k %= n;
            if (rev) {
                sd += k;
                sd %= n;
            } else {
                sd -= k;
                sd += n;
                sd %= n;
            }
        } else {
            rev = !rev;
        }
        cnt = 0;
        if (!rev) {
            cnt = getans1(1, 0, maxn, 0, n - sd, -sd) + getans1(1, 0, maxn, n - sd, maxn, n - sd);
        } else {
            cnt = getans2(1, 0, maxn, 0, sd, sd - n) +
                  getans2(1, 0, maxn, sd, maxn, sd);
        }
        cout << cnt << '\n';
    }
    return 0;
}