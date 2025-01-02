#include <bits/stdc++.h>
using namespace std;
 
#define FILENAME ""
  
#ifdef TXT
struct FileOpener {
	FileOpener() {
		freopen(FILENAME".in", "r", stdin);
		freopen(FILENAME".out", "w", stdout);
	}
} fileopener;
#endif

#define ll int64_t
#define ull uint64_t
#define vi vector<int64_t>
#define vvi vector<vector<ll>>
#define pi pair<ll,ll>
#define vpi vector<pair<ll,ll>>
#define vvpi vector<vector<pi>>
#define fore(i,b,e)  for (int64_t i = (b); i < (e); ++i)
#define foree(i,b,e) for (int64_t i = (b); i <= (e); ++i)
#define ford(i,b,e)  for (int64_t i = (e)-1; i >= (b); --i)
#define fordd(i,b,e) for (int64_t i = (e); i >= b; --i)
#define ff first
#define ss second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fastIO ios::sync_with_stdio(false)
#define ceilll(n,d) (((n)+(d)-1)/(d))
#define print_arr(arr,b,e) {fore(i,(b),(e)) cout << arr[i] << ' '; cout << '\n';}
#define id(x) #x
 
const double PI = 3.1415926535897932;
const double EPS = 1e-9;
constexpr ll INF = 1e18;
 
inline ull gcd(ull a, ull b) {
	while (a&&b)
		a>b?a%=b:b%=a;
	return a?a:b;
}

inline ull lcm(ull a, ull b) {
    return a/gcd(a,b)*b;
}
 
inline ull power(ull a, ll b) {
	ull ans = 1;
	while (b) {
		if (b&1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

inline ull powmod(ull a, ll b, ull _mod) {
	ull ans = 1;
	a %= _mod;
	while (b) {
		if (b&1) ans = (ans * a) % _mod;
		a = (a * a) % _mod;
		b >>= 1;
	}
	return ans;
}
 
ll phi(ll n) {
    ll m;
	
	m = n;
	for(ll i = 2; i*i <= m; ++i) {
	    if (m % i == 0) {
	        n = n/i*(i-1);
	        while (m % i == 0)
	            m /= i;
	    }
	}
	if (m != 1)
	    n = n/m*(m-1);
	    
	return n;
}
 
ull phi(ull n) {
    ull m;
	
	m = n;
	for(ull i = 2; i*i <= m; ++i) {
	    if (m % i == 0) {
	        n = n/i*(i-1);
	        while (m % i == 0)
	            m /= i;
	    }
	}
	if (m != 1)
	    n = n/m*(m-1);
	    
	return n;
}
 
inline ull num_of_digits(ull n) {
	ll ans = 0;
	while (n) {
		n /= 10;
		++ans;
	}
	return ans;
}
 
inline ull num_of_digits_b(ull n) {
	ll ans = 0;
	while (n) {
		n >>= 1;
		++ans;
	}
	return ans;
}

ll dist(ll beg, ll dirt, ll mx) {
    return beg <= dirt ? dirt-beg : 2*(mx-beg) + beg-dirt;
}

void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n,m,rb,cb,rd,cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        ll dr = 1, dc = 1;
        cout << min(dist(rb,rd,n),dist(cb,cd,m)) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(12);
    solve();
    return 0;
}