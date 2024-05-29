#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") 
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
using ll = long long;
using LL = long long;
using i64 = long long;
#define double long double
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define lowbit(x) (x & (-(x)))
constexpr ll mod = 1e9 + 7;
constexpr int M = 3e5 + 3;


void slove(){
    int n, r, c;
    cin >> n >> r >> c;

    vector<int> a(n + 1);
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    vector<int> to(n + 1), d(n + 1);
    for(int i = 1;i <= r;++i)
    {
        int u, v;
        cin >> u >> v;
        swap(u, v);
        to[u] = v, ++d[v];
    }
    vector<int> w(n + 1);
    int tot = 0;
    auto calc = [&](auto&&calc, int u, int dis = 0)->int{
        int ans = a[u];
        tot += a[u] * dis;
        if(to[u])
            ans += calc(calc, to[u], dis + 1);
        return w[u] = ans;
    };
    for(int i = 1;i <= n;++i)
        if(not d[i])
            calc(calc, i), c -= tot, tot = 0;
    if(c < 0) return cout << 0 << endl, void();
    if(c == 0) return cout << 1 << endl, void();


    queue<int> que;
    vector<int> point;
    for(int i = 1;i <= n;++i)
        if(not d[i])
            que.push(i);
    while(que.size())
    {
        auto u = que.front(); que.pop();
        point.push_back(u);
        if(to[u] and --d[to[u]] == 0)
            que.push(to[u]);
    }
    
    if(point.size() != n) return cout << 0 << endl, void();
    vector<int> f(c + 1);
    f[0] = 1;
    for(int i = 1;i <= n;++i)
    {
        for(int j = w[i];j <= c;++j)
            f[j] += f[j - w[i]], f[j] %= mod;
    }
    cout << f[c] << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int t = 1;  
    // cin >> t;
    //init();
    while(t--)
        slove();
    return 0;
}
