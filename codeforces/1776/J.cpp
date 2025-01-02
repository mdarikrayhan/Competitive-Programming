// #include "lib/temp/base.h"
#include <bits/stdc++.h>
using namespace std;
#define sf sizeof
#define con const
#define cer constexpr
#define ret return
#define let const auto
#define whi while
using is = int32_t;
using il = int64_t;
#define ix __int128_t
using us = uint32_t;
using ul = uint64_t;
#define ux __uint128_t
using fs = double;
using fl = long double;
#ifndef EXT
    template<class T> using gque = std::priority_queue<T>;
    template<class T> using lque = std::priority_queue<T, vector<T>, greater<>>;
#endif

template<class T=is> cer T INF = T(0x3f3f3f3f3f3f3f3f);
extern con us MOD;

template<class T> void mec(con T *src, T *dst, us n) { memcpy(dst, src, n*sf(T)); }
template<class T> void mes(T *arr, us n=1, us b=0) { memset(arr, b, n * sf(T)); }
template<class T> void tmx(T &lhs, con T &rhs) { if(rhs>lhs) lhs = rhs; }
template<class T> void tmn(T &lhs, con T &rhs) { if(rhs<lhs) lhs = rhs; }
template<class T> T md(T x) { ret T(x % MOD); }
#define DEG if(EN_DEG)
#define EN_DEG 0
// <- -- --- ----header end---- --- -- ->
cer con char *ANS[] = {"No", "Yes"};
cer fl EPS = 1e-8;
// cer us MOD = 998244353;
cer us MOD = 1e9 + 7;
cer us MAX = 1e2 + 7;

// 分层图，枚举uv点集和到达层d(第d次增加的层)
// 显然中间路径长度不受变换次数影响
// 若u[0]到v[d]经过偶数次变换，u[0]点扩增d次，那么增量为d
// 若u[0]到v[d]经过奇数次变换，v[d]点扩增k-d次并变换连边，那么增量为k-d

us n, m, K, col[MAX];
us ds[MAX*2][MAX*2];

void solve() {
    let sz = n*2;
    for(us k=0; k<sz; ++k) {
        for(us i=0; i<sz; ++i) {
            for(us j=0; j<sz; ++j) {
                tmn(ds[i][j], ds[i][k]+ds[k][j]);
            }
        }
    }

    us ans = 0;
    for(us i=0; i<n; ++i) {
        for(us j=0; j<n; ++j) {
            for(us d=0; d<=K; ++d) {
                tmx(ans, min(ds[i][j] + d, ds[i][j+n] + (K-d)));
            }
        }
    }
    cout << ans;
}

void pre() {
    cin >> n >> m >> K;
    for(us i=0; i<n; ++i) {
        cin >> col[i];
    }
    mes(ds[0], n*MAX*4, 0x3f);
    for(us i=0; i<n; ++i) {
        ds[i][i] = ds[i+n][i+n] = 0;
        // k次移动后也可到达对应奇变换点
        ds[i][i+n] = ds[i+n][i] = K;
    }
    for(us i=0, u, v; i<m; ++i) {
        cin >> u >> v;
        if(col[--u]==col[--v]) {
            ds[u][v] = ds[u+n][v+n] = 1;
            ds[v][u] = ds[v+n][u+n] = 1;
        } else {
            ds[u][v+n] = ds[u+n][v] = 1;
            ds[v][u+n] = ds[v+n][u] = 1;
        }
    }
}

us _t = 1;
void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // cin >> _t;
    // fin(_t);
    if(!_t) exit(0);
}

void later() { cout << '\n'; }

int main() {
    init();
    for(us i=0;;) {
        DEG { cout << '#' << i << '\n'; }
        pre(); solve();
        (++i<_t)?later():exit(0);
    }
}
