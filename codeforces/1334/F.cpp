/*
Problem: 1334F
Date: 24-05-2024 01:00 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5e5 + 5;
int n, m;
ll a[N], b[N], p[N], tree[4 * N], lazy[4 * N];

#define PLUS(a, b) ((a) == LLONG_MAX || (b) == LLONG_MAX ? LLONG_MAX : ((a) + (b)))

void build(int i, int l, int r) {
    if(l == r) {
        if(l == 0) {
            tree[i] = 0;
        }else {
            tree[i] = LLONG_MAX;
        }
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
}
void prop(int i, int l, int r) {
    tree[i] = PLUS(tree[i], lazy[i]);
    if(l < r) {
        lazy[2 * i + 1] = PLUS(lazy[2 * i + 1], lazy[i]);
        lazy[2 * i + 2] = PLUS(lazy[2 * i + 2], lazy[i]);
    }
    lazy[i] = 0;
}
ll query(int i, int l, int r, int idx) {
    prop(i, l, r);
    if(l == r) {
        assert(l == idx);
        return tree[i];
    }
    int m = (l + r) / 2;
    if(idx <= m) return query(2 * i + 1, l, m, idx);
    else return query(2 * i + 2, m + 1, r, idx);
}
void upd(int i, int l, int r, int L, int R, ll x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] = PLUS(lazy[i], x);
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
}
void upd2(int i, int l, int r, int idx, ll x) {
    prop(i, l, r);
    if(l == r) {
        assert(l == idx);
        tree[i] = x;
        return;
    }
    int m = (l + r) / 2;
    if(idx <= m) upd2(2 * i + 1, l, m, idx, x);
    else upd2(2 * i + 2, m + 1, r, idx, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    build(0, 0, m);
    for(int i = 1; i <= n; i++) {
        int j = lower_bound(b + 1, b + m + 1, a[i]) - b;
        int k = j;
        if(j <= m && b[j] == a[i]) {
            ll pp = min(p[i], 0LL);
            ll curr = query(0, 0, m, j), val = query(0, 0, m, j - 1);
            curr = PLUS(curr, pp);
            upd2(0, 0, m, j, min(curr, val));
            k++;
        }
        upd(0, 0, m, 0, j - 1, p[i]);
        if(p[i] < 0) upd(0, 0, m, k, m, p[i]);
    }
    ll ans = query(0, 0, m, m);
    if(ans == LLONG_MAX) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
        cout << ans << "\n";
    }
}