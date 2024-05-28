#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t bigint;
#define endl '\n'
#define debug cout << "konichiwaaaaaaaaaa:3" << endl;
#define open(name) if(fopen(name".inp","r")) freopen(name".inp","r",stdin), freopen(name".out","w",stdout);
template<typename T> using pqmax = priority_queue<T>;
template<typename T> using pqmin = priority_queue<T,vector<T>,greater<T>>;
void konichiwa() {ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);}
void times() {cerr << "Time: " << fixed << setprecision(4) << (ld)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";}
ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
const int maxn = 1e7;
const ll inf = 1e9;
const ll mod = 1e9+7;

ll d[maxn+1];

void cook(){
    ll n,k; cin >> n >> k;
    int a[n+1]; for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = *max_element(a+1,a+n+1), res = -1;
    while(l <= r) {
        int mid = (l+r)/2;
        memset(d,0,sizeof(d));
        for(int i = 1; i <= n; i++) d[a[i]]++;
        for(int i = maxn; i >= 1 && i/2 >= mid; i--) {
            d[i/2] += d[i];
            d[i-i/2] += d[i];
            d[i] = 0; 
        }
        ll s = 0; for(int i = mid; i <= min(maxn,2*mid); i++) s += d[i];
        //cout << mid << ' ' << s << endl;
        if (s >= k) res = mid, l = mid+1;
        else r = mid-1;
    }
    cout << res << endl;
}

int main(){
    konichiwa(); open("file");


    int t = 1;
    //cin >> t;
    while(t--) cook();
}

