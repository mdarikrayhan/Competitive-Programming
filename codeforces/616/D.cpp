#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,popcnt,sse4,abm")
#include <bits/stdc++.h>
using namespace std;

#ifdef WAIMAI
#define debug(HEHE...) cout << "[" << #HEHE << "] : ", dout(HEHE)
void dout() {cout << '\n';}
template<typename T, typename...U>
void dout(T t, U...u) {cout << t << (sizeof...(u) ? ", " : ""), dout(u...);}
#else
#define debug(...) 7122
#endif

#define ll long long
#define Waimai ios::sync_with_stdio(false), cin.tie(0)
#define FOR(x,a,b) for (int x = a, I = b; x <= I; x++)
#define pb emplace_back
#define F first
#define S second

const int SIZE = 5e5 + 5;

int n, k, L, R;
int sz, a[SIZE], cnt[SIZE << 1];

void add(int x) {
    if (cnt[x]++ == 0) sz++;
}
void del(int x) {
    if (--cnt[x] == 0) sz--;
}

void solve() {
    cin >> n >> k;
    L = 1;
    FOR (i, 1, n) cin >> a[i];
    for (int i = 1, l = 1; i <= n; i++) {
        add(a[i]);
        while (sz > k) del(a[l++]);
        if (i - l > R - L) L = l, R = i;
    }
    cout << L << ' ' << R << '\n';
}

int main() {
    Waimai;
    solve();
}