#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/*template <class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//- insert(x),erase(x)
//- find_by_order(k): return iterator to the k-th smallest element
//- order_of_key(x): the number of elements that are strictly smaller*/

#define int long long
#define ll long long
#define ld long double
#define ar array
#define vt vector
#define pb push_back
#define bit(i, x) ((x>>i)&1ULL)
#define pf push_front
#define all(v) v.begin(), v.end()
#define lla(v) v.rbegin(), v.rend()

const ll MOD=1e9+7;
const ll M=(1ll<<61)-1;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll base=uniform_int_distribution<ll>(0, M-1)(rng);

ll bpow(ll a, ll b, ll DOMDOM) {
	a%=DOMDOM;
	ll res=1;
	while(b>0) {
		if(b&1)
			res=res*a%DOMDOM;
		a=a*a%DOMDOM;
		b>>=1;
	}
	return res;
}

ll floor_div(ll x, ll y) {
	assert(y!=0);
	if (y<0) {
		y=-y;
		x=-x;
	}
	if (x>=0) return x/y;
	return (x+1)/y-1;
}

ll ceil_div(ll x, ll y) {
	assert(y!=0);
	if (y<0) {
		y=-y;
		x=-x;
	}
	if (x<=0) {
		return x/y;
	}
	return (x-1)/y+1;
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

const int mxN=1e6+5;
int n, r, c;
int up[mxN][21];

void bld() {
	for(int i=0; i<21; ++i) {
		up[n+1][i]=n+1;
	}
	for(int j=1; j<21; ++j) { 
		for(int i=1; i<=n; ++i) {
			up[i][j]=up[up[i][j-1]][j-1];
		}
	}
}

void solve() {
	//solve here
	cin >> n >> r >> c;
	vt<string> v(n+1);
	for(int i=1; i<=n; ++i) {
		cin >> v[i];
	}
	vt<int> ps(n+1);
	for(int i=1; i<=n; ++i) {
		ps[i]=ps[i-1]+v[i].size();
	}
	for(int i=1; i<=n; ++i) {
		ps[i]+=i-1;
	}
	for(int i=1; i<=n; ++i) {
		int id=upper_bound(all(ps), ps[i-1]+c+(i!=1))-ps.begin();
		up[i][0]=id;
	}
	bld();
	int start=-1, mx=0;
	for(int i=1; i<=n; ++i) {
		int left=i;
		for(int j=0; j<21; ++j) {
			if(bit(j, r)) {
				left=up[left][j];
			}
		}
		--left;
		if(left-i+1>mx) {
			mx=left-i+1;
			start=i;
		}
	}
	int cnt=up[start][0]-1;
	int tmp=start;
	for(int i=tmp; i<=mx+tmp-1; ++i) {
		cout << v[i];
		if(i==cnt) {
			cout << "\n";
			start=cnt+1;
			cnt=up[start][0]-1;
		}
		else {
			cout << " ";
		}
	}
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("template.inp", "r", stdin);
	//freopen("template.out", "w", stdout);	

	int TC=1;
	//cin >> TC;
	while(TC--) {
		solve();
	}
}
