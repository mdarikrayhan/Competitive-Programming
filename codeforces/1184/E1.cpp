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
struct DSU{
public:
    static const int MAX = 1e5 + 50;
    int bcj[MAX];
    int siz[MAX];
    void Init(int n){
        for (int i = 1; i <= n; ++i) {
            bcj[i] = i;
        }
    }
    int Find(int x){
        if(bcj[x] == x)
            return x;
        return bcj[x] = Find(bcj[x]);
    }
    //按秩合并
    void Union(int x,int y){
        x = Find(x),y = Find(y);
        if(x == y)
            return;
        if(siz[x] > siz[y])
            swap(x,y);
        bcj[x] = y;
        siz[y] += siz[x];
    }
//普通合并
//void Union(int x, int y){
//    bcj[Find(x)] = Find(y);
//}
};
DSU dsu;
struct edge{
    int u,v,w;
};
void NeverSayNever() {
    int n,m; cin >> n >> m;
    vector<edge> E(m);
    dsu.Init(n+1);
    for (auto & x : E) cin >> x.u >> x.v >> x.w;
    std::sort(E.begin() + 1, E.end(),[](edge x,edge y){
        return x.w < y.w;
    });
    int cnt = 0;
    for (int i = 1; i < m; ++i) {
        auto [u,v,w] = E[i];
        if(dsu.Find(u) == dsu.Find(v)) continue;
        dsu.Union(u,v);
        cnt++;
        if(dsu.Find(E[0].u) == dsu.Find(E[0].v)){
            cout << E[i].w << endl;
            return;
        }
    }
    if(cnt < n - 1) cout << (int)1e9 << endl;
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