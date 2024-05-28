#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") 

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// #define int long long
using ll = long long;
using LL = long long;
using i64 = long long;
#define double long double
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define lowbit(x) (x & (-(x)))
template <int x> using arr = array<int, x>;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1e16 + 7;
constexpr ll M = 1e5 + 13;
constexpr int N = 1e6 + 114;


void init()
{

}

void slove()
{
    int n; cin >> n;
    vector<int> a(5);
    for(int i = 1;i <= 4;++i) cin >> a[i];

    vector<vector<char>> g(4, vector<char>(n + 1));
    for(int i = 0;i < 4;++i)
        for(int j = 1;j <= n;++j)
            cin >> g[i][j];

    vector<vector<int>>f(n + 1, vector<int>(1 << 16, mod)); 
    int tot = 1 << 16;
    vector<int> w(1 << 16);
    vector<int> cor = {0, 1};
    for(auto& v : cor)
    {
        int pos = v;
        v = 1 << v;
        v += (1 << (pos + 1)); v += (1 << (pos + 2));
        v += (1 << (pos + 4)); v += (1 << (pos + 5)); v += (1 << (pos + 6));
        v += (1 << (pos + 8)); v += (1 << (pos + 9)); v += (1 << (pos + 10));
        w[tot - v - 1] = a[3];
    }
    for(int i = 0;i < 4;++i) w[tot - (1 << i) - 1] = a[1];
    vector<int> tr = {0, 1, 2};
    for(auto &i : tr)
    {
        int x = i + 1, y = i + 4, z = i + 5;
        int v = 1 << i;
        v += 1 << x, v += 1 << y, v += 1 << z;
        if(x >= 0 && x < 16 && y >= 0 && y < 16 && z >= 0 && z < 16) w[tot - v - 1] = a[2];
    }

    w[0] = a[4];
    vector<arr<2>> W;
    for(int i = 0;i < tot;++i)
        if(w[i])
            W.push_back({i, w[i]});
    f[0][0] = 0;
    int pp = (1 << 15) + (1 << 14) + (1 << 13) + (1 << 12);

    vector<int> pid;
    for(int j = tot - 1;j >= 0;--j)
    {
        if(j & pp) continue;
        pid.push_back(j);
    }
    for(int i = 1;i <= n;++i)
    {
        for(auto& j : pid)
        {
            if(f[i - 1][j] == mod) continue;
            int v = (j << 4) % tot;
            for(int k = 0;k <= 3;++k) v += (g[k][i] == '*') << k;
            f[i][v] = min(f[i][v], f[i - 1][j]);
        }
        for(int v = tot - 1;v >= 0;--v)
        {
            if(f[i][v] == mod) continue;
            for(auto& [k, w] : W)
                f[i][v & k] = min(f[i][v & k], f[i][v] + w);
        }
    }
    cout << f[n][0] << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int t = 1;  
    // cin >> t;
    init();
    while(t--)
        slove();
    return 0;
}