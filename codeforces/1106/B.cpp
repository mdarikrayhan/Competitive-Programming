//  __      __          ___                                         ___    __ __
// /\ \  __/\ \        /\_ \                                      /'___'\ /\ \ \
// \ \ \/\ \ \ \     __\//\ \     ___    ___     ___ ___      __ /\_\ /\ \ \ \ \       __   __  __     __   _ __
//  \ \ \ \ \ \ \  /'__'\ \ \   /'___\ / __'\ /' __' __'\  /'__'\/_/// /__\ \ \ \_   /'__'\/\ \/\ \  /'__'\/\''__\
//   \ \ \_/ \_\ \/\  __/ \_\ \_/\ \__//\ \L\ \/\ \/\ \/\ \/\  __/  // /_\ \ \__ ,__\/\  __/\ \ \_/ |/\  __/\ \ \/
//    \ '\___x___/\ \____\/\____\ \____\ \____/\ \_\ \_\ \_\ \____\/\______/ \/_/\_\_/\ \____\ \___/ \ \____\ \_\
//     '\/__//__/  \/____/\/____/\/____/\/___/  \/_/\/_/\/_/\/____/\/_____/     \/_/   \/____/ \/__/   \/____/ \/_/
//   bilibili:24Records
//   link:https://space.bilibili.com/3546387113314828
#include "bits/stdc++.h"
using namespace std;
const int Welcome24ever = 0;
typedef long long ll;
typedef pair<int,int> PII;
long double pi = acos(-1);
int MOD = 998244353;
const int N = 2e5 + 5;
#define endl '\n'
#define fixset(x) fixed << setprecision(x)
#define int long long
void NeverSayNever() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1),c(n+1),tmp(n + 1);
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 1; i <= n; i += 1) cin >> c[i];
    for(int i = 1; i <= n; i += 1) tmp[i] = i;
    sort(tmp.begin() + 1, tmp.begin() + n + 1, [&](int x, int y){
        if(c[x] == c[y]) return x < y;
        return c[x] < c[y];
    });
    int L = 1;
    for(int i = 0; i < m; i += 1){
        int tmp1, tmp2, ans = 0;
        cin >> tmp1 >> tmp2;
        int mi = min(a[tmp1], tmp2);
        a[tmp1] -= mi, tmp2 -= mi, ans += mi * c[tmp1];
        while(L <= n && tmp2){
            mi = min(a[tmp[L]], tmp2);
            a[tmp[L]] -= mi, tmp2 -= mi, ans += mi * c[tmp[L]];
            if(a[tmp[L]] == 0) L += 1;
        }
        if(tmp2 != 0)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        NeverSayNever();
    }
    return Welcome24ever;
}