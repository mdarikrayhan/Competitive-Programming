#include<bits/stdc++.h>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define ar array
#define vi vector
#define bit(i,x) ((x >> i) & 1ll)
#define all(x) x.begin(),x.end()
#define low(l,r,x) x.begin()+l,x.begin()+r 
#define len(l,r) (r-l+1)
#define PI acos(-1.0) 
template <class T> void setmin(T &a, T b) { if(b < a) a = b; }
template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const long long mod = 1e9 + 7, N =  2e6, INF = 1e18, Log = 19, MASK = 1 << 19;
using namespace std;
 

#define int long long

ll is_prime[N+5];
vector<ll> prime;
ll m[N+5];
ll res[N+5];
ll g[N+5];
ll ans[N+5];

ll sqr(ll x){ return (x * x) % mod; }
ll Pow(ll a,ll b) {
    if(b == 0) return 1;
    if(b & 1) return a * sqr(Pow(a, b/2)) % mod;
    else return sqr(Pow(a, b/2)) % mod;
}


void sieve(ll n) {
    m[1] = 1;
    for(int i = 2; i < n;i++) {
        if(!is_prime[i]) {
            m[i] = -1; prime.push_back(i);
        }
        for(int j = 0; j < prime.size() && i * prime[j] < n;j++) {
            is_prime[i * prime[j]] = true;
            if(i % prime[j] == 0) {
                m[i * prime[j]] = 0;
                break;
            }
            else {
                m[i * prime[j]] = m[i] * m[prime[j]];
            }
        }
    }
}




void kazuha() {
    ll n , k;
    cin >> n >> k;
    ll cur = 0;
    sieve(N+1);
    for(int i = 1; i <= k;i++) {
        g[i] = Pow(i,n);
    }
    for(int i = 1; i <= k;i++) {
        for(int j = 1; j*i <= k;j++) {
            ans[i*j] = (ans[i*j] + m[i]*(g[j] - g[j-1]) + mod) % mod;
        }
    }
    for(int i = 1; i <= k;i++) {
        ans[i] += ans[i-1];
        ans[i] %= mod;
        cur += (ans[i] ^ i);
        cur = (cur + mod) % mod;
    }
    cout << cur << '\n';
}
 
 
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("permutation.cpp", "r", stdin);
    // freopen("permutation.cpp", "w", stdout); 
    long long mitsu = 1;
    // cin >> mitsu;
    for(long long seele = 0; seele < mitsu;seele++) {
        // cout << "Case " << seele << " :"; 
        kazuha();
    }
}
    			   	 	 	  			   			 				