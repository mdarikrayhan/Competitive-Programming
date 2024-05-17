#include <bits/stdc++.h>
using namespace std;

// Ordered set requirements
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<long long>;
using vpll = vector<pair<long long, long long>>;
using pll = pair<long long, long long>;

// Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;

// Macros
#define F first
#define S second
#define PB push_back 
#define POB pop_back 
#define MP make_pair 
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define int long long
#define for0(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define forc(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define forr(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)

// cin >> pair<T1, T2>
template<typename T1, typename T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) {
	return (istream >> p.first >> p.second); 
}

// cin >> vector<T>
template<typename T> 
istream& operator>>(istream &istream, vector<T> &v){
	for (auto &it : v) cin >> it;
	return istream;
}

// cout << pair<T1, T2>
template<typename T1, typename T2> 
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p){
	return (ostream << p.first << " " << p.second); 
}

// cout << vector<T>
template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &c) {
	for (auto &it : c) cout << it << " "; 
	return ostream; 
}

// Utility functions
template <typename T>
void print(T &&t){ 
	cout << t << "\n"; 
}

template <typename T, typename... Args>
void print(T &&t, Args &&... args){
    cout << t << " ";
    print(forward<Args>(args)...);
}

// Mathematical functions
int GCD(int a, int b) 
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int GCD_extended(int a, int b, int &x, int &y) 
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int LCM(int a, int b)
{
    return ((ll)a * b) / GCD(a, b);
}

ll modpow(ll x, ll n, int m = MOD)
{
    if (x == 0 && n == 0) return 0; // undefined case
    ll res = 1;
    while (n > 0) 
    {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int modinv(int x, int m = MOD)
{   
    return modpow(x, m - 2, m);
}

mt19937 rng;
int getRandomNumber(int l, int r)
{
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

/********************************************************
                 Main code starts here!
   |               ___           ___         .      .  
   |.===.         /\#/\         .|||.      .  .:::.    
   {}o o{}       /(o o)\        (o o)        :(o o):  .
ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-
********************************************************/

void pre() {
    
}

void solve(int tc) {
	ll n; cin >> n;
	vll a(n); cin >> a;

	vll diff;
	for0(i,n-1) {
		diff.PB(abs(a[i] - a[i+1]));
	}

	reverse(all(diff));
	ll len = diff.size();

	// print(diff);

	ll ans = diff[0];
	ll mx = ans;
	ll mn = ans;

	for(ll i=1; i<len; i++) {
		ans = max({ans, diff[i] - mn, diff[i] - mx, diff[i]});

		ll tmx = mx;
		ll tmn = mn;

		mx = max({diff[i], diff[i] - tmn});
		mn = min({diff[i], diff[i] - tmx});

		// print("i, mn, mx:", i, mn, mx);
	}

	print(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    cout << setprecision(12) << fixed;
    pre();

    int tests = 1;
    // cin >> tests;
    for (int tt = 1; tt <= tests; tt++)
        solve(tt);

    return 0;
}