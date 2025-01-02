// 194.67
// #pragma optimize ("g",on)
// #pragma GCC optimize("inline")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC optimize ("03")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout);
#define adiyer(); ios_base::sync_with_stdio(0); cin.tie(0);
#define bitcount(n) __builtin_popcountll(n)
#define puts(x) cout << (x ? "YES\n" : "NO\n");
#define ent (i == n ? '\n' : ' ')
#define all(x) x.begin(), x.end()
#define md ((l + r) >> 1)
#define rv(v) ((v << 1) | 1)
#define lv(v) (v << 1)
#define rs(v) rv(v), md + 1, r
#define ls(v) lv(v), l, md
#define len(s) (int) s.size()
 
#define yes {cout << "YES\n"; return; }
#define no {cout << "no\n"; return; }
#define skip continue
#define pb push_back
#define S second
#define F first
 
// #define int long long
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector < ll > vll;
typedef pair < ll, ll > pll;
typedef vector < pair < ll, ll > > vpll;
typedef tree < ll, null_type, less < ll >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int N = 5e3 + 123;
const int K = 4e3 + 123;
const int MAX = 1e6;
const int mod = 999899933;
const ll inf = 2e18 + 10;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll n, ans;
ll a[N];

void output(){
	cin >> n, ans = 0;
	for(ll i = 1; i <= n; i++) cin >> a[i], ans += (i - 1) * (n - i + 1);
	for(ll x = 1, i, j, k; x <= n; x++){
		i = k = 0, j = n + 1;
		for(ll y = x; y <= n; y++){
			if(a[y] < a[x]){
				j = y; break;
			}
		}
		for(ll y = x; y >= 1; y--){
			if(a[y] < a[x]){
				k = y; break;
			}
		}
		for(ll y = k; y >= 1; y--){
			if(a[y] > a[x]){
				i = y; break;
			}
		}
		if(j >= x && k >= i){
			ans -= (j - x) * (k - i);
		}
	}
	cout << ans << '\n';
}
       
const bool cases = 1;

signed main(){
//  file("disrupt");
    adiyer();
    int tt = 1;
    if(cases) cin >> tt;
    for(int i = 1; i <= tt; i++){
//      cout << "Case " << i << ":\n";
        output();
    }
}