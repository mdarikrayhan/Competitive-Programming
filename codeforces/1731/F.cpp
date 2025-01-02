#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define fi first
#define se second
#define pp push_back
#define all(x) (x).begin(), (x).end()
#define Ones(n) __builtin_popcount(n)
#define endl '\n'
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
//#define int long long
#define debug(x) cout << (#x) << " = " << x << endl

void Gamal() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

const double EPS = 1e-9;
const ll OO = 0X3F3F3F3F3F3F3F3F;
const int N = 2e5 + 5, INF = INT_MAX, MOD = 998244353, LOG = 20;

ll fac[N],inv[N];

ll mul(const ll &a,const ll&b){
    return (a % MOD + MOD) * (b % MOD + MOD) % MOD;
}

ll add(const ll &a,const ll&b){
    return (a + b + 2 * MOD)%MOD;
}

ll pw(ll b, ll p) {
    if(p < 0)return 0;
    if (!p) return 1LL;
    ll ret = pw(b, p >> 1LL);
    ret = mul(ret,ret);
    if (p & 1LL)
        ret = mul(ret,b);
    return ret;
}

void build(){
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = mul(fac[i - 1],i);
    }
    inv[N - 1] = pw(fac[N - 1],MOD - 2);
    for (int i = N - 2; ~i ; --i) {
        inv[i] = mul(inv[i + 1],i + 1);
    }
}

ll nCr(int n,int r){
    if(r > n)return 0;
    return mul(mul(fac[n],inv[n - r]),inv[r]);
}


struct LagrangePoly {
    vector<long long> y, den;
    void build(vector<long long> _a){
        //f(i) = _a[i]
        //f(x) has degree of y.size() - 1
        y = _a;
        den.resize(y.size());
        int n = (int) y.size();
        for (int i = 0; i < n; i++) {
            y[i] = (y[i] % MOD + MOD) % MOD;
            den[i] = inv[n - i - 1] * inv[i] % MOD;
            if ((n - i - 1) % 2 == 1) {
                den[i] = (MOD - den[i]) % MOD;
            }
        }
    }

    ll getVal(ll x) {
        int n = (int) y.size();
        x %= MOD;
        if (x < n) {
            return y[(int) x];
        }
        //O(N^2)
        /*long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long cur = den[i];
            for(int j = 0; j < n; j++) {
                if(i == j) { continue; }
                cur = cur * (x - y[i] + MOD) % MOD;
            }
            ans = (ans + cur) % MOD;
        }
        return ans;*/
        // O(N)
        std::vector<long long> l, r;
        l.resize(n);
        l[0] = 1;
        for (int i = 1; i < n; i++) {
            l[i] = l[i - 1] * (x - (i - 1) + MOD) % MOD;
        }
        r.resize(n);
        r[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            r[i] = r[i + 1] * (x - (i + 1) + MOD) % MOD;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long coef = l[i] * r[i] % MOD;
            ans = (ans + coef * y[i] % MOD * den[i]) % MOD;
        }
        return ans;
    }

};

void solve() {
    int n,k;cin >> n >> k;
    vector<ll>p = {0};
    int pre = 0;
    for(int t = 1;t <= n + 5;++t){
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int l = 0; l <= i; ++l) {
                for (int m = l + 1; m <= n - i - 1; ++m) {
                    int leftWays = mul(mul(nCr(i,l), pw(t - 1,l)), pw(k - t + 1,i - l));
                    int rightWays = mul(mul(nCr(n - i - 1,m), pw(k - t,m)), pw(t,n - i - 1 - m));
                    sum = add(sum, mul(leftWays,rightWays));
                }
            }
        }
        pre = add(pre, mul(sum,t));
        p.push_back(pre);
    }
    LagrangePoly poly;
    poly.build(p);
    cout << poly.getVal(k) << endl;
}


signed main() {
    Gamal();
    build();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
			   					  			 		     	 	 		