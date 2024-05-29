#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;

#define deb(x)          cout << x
#define X               first
#define Y               second
#define SZ(x)           int(x.size())
#define all(x)          x.begin(), x.end()
#define mins(a,b)       (a = min(a,b))
#define maxs(a,b)       (a = max(a,b))
#define pb              push_back
#define Mp              make_pair
#define kill(x)         {cout << (x) << '\n'; exit(0);}
#define killt(x)        {cout << (x) << '\n'; return;}
#define md(x)           ((((x)%MOD)+MOD)%MOD)
#define lc              id<<1
#define rc              lc|1
#define mid             ((l+r)/2)
mt19937_64              rng(chrono::steady_clock::now().time_since_epoch().count());

const ll  INF = 1e9 + 23;
const ll  MOD = 1e9 + 7;
const int MXN = 2e5 + 23;
const int LOG = 23;

using big_black_int = __int128_t;

big_black_int F(big_black_int n, big_black_int r) { // n! / r!
    big_black_int ans=1;
    for(int i=r+1; i<=n; i++) ans *= i;
    return ans;
}

big_black_int C(big_black_int n, big_black_int r) {
    if(r < n/2) return F(n, n-r) / F(r, 1);
    return F(n, r) / F(n-r, 1);
}

ll mx(big_black_int x, big_black_int m) {
    big_black_int rem = x*m, N=1;
    for(big_black_int d=1; d<=x && d<=rem && N<INF; d++) {
        big_black_int t = min(rem/d, C(x, d));
        N += t;
        rem -= t*d;
    }
    return N>INF ? INF : N;
}

void Main() {
    ll n, m;
    cin >> n >> m;
    ll l=-1, r=n;
    while(r-l>1)
        if(mx(mid, m)>=n) r=mid;
        else l=mid;
    cout << r << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while(T--) Main();
    return 0;
}