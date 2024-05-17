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

const int SIZE = 2e5 + 5;

int n;
ll ans;
int p[SIZE];

void solve() {
    cin >> n;
    FOR (i, 1, n) {
        int x;
        cin >> x;
        p[x] = i;
    }
    FOR (i, 2, n) ans += abs(p[i] - p[i - 1]);
    cout << ans << '\n';
}

int main() {
    Waimai;
    solve();
}