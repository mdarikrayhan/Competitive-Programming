#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
using ll = long long;
using LL = long long;
using i64 = long long;
#define double long double
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define lowbit(x) (x & (-(x)))
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1e17 + 7;
constexpr int M = 1e5 + 3;

int qpow(int a, int b, int c = mod)
{
    int ans = 1,base = a; base %= c;
    if(!b) return 1 % c;
    while(b)
    {
        if(b & 1) ans = ans * base % c;
        b >>= 1;
        base = base * base % c;
    }
    return ans;
}

void slove()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    
    for(int i = 1;i <= n;++i)
        cin >> a[i];

    sort(all(a));

    vector<int> fac(n + 1);
    fac[0] = 1;

    for(int i = 1; i <= n; ++i)
        fac[i] = fac[i - 1] * i % mod;

    int ans = 0;

    for(int i = 1;i < n && a[i] != a[n];)
    {
        int v = i - 1, val = a[i];
        while(a[i] == val && i < n && a[i] != a[n])
            ans += (fac[n] * qpow(n - v, mod - 2) % mod) * val % mod, ans = (ans % mod + mod) % mod, ++i;
    }
    cout << ans << endl;
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
