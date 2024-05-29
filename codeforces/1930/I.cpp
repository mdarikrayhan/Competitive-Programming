#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());


const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, qexp(root, mod >> s, mod)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vector<int> rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = qexp(n, mod - 2, mod);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

int n;
string s;

int c[100005];
int f[100005];

void calc(int l,int r,vector<int> v){
	while (sz(v)>(r-l)*2+1) v.pob();
	
	if (l==r){
		f[l]=v[0];
		return;
	}
	
	int m=l+r>>1;
	
	calc(l,m,vector<int>(v.begin()+(r-m),v.end()));
	vector<int> a;
	int t=m-l+1;
	rep(x,0,t+1) a.pub(nCk(t,x)),a.pub(0);
	
	v=conv(v,a);
	calc(m+1,r,vector<int>(v.begin()+(2*t),v.end()));
}

int ans[100005];

void solve(int l,int r){
	if (l==r) return;
	int m=l+r>>1;
	solve(l,m);
	auto a=conv(vector<int>(ans+l,ans+m+1),vector<int>(f,f+(r-l)));
	rep(x,m+1,r+1) if (s[x]=='0') ans[x]=fix(ans[x]-a[x-1-l]);
	solve(m+1,r);
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	rep(x,1,100005){
		c[x]++;
		
		int curr=x;
		while (curr<100005){
			if (curr+2<100005) c[curr+2]-=2;
			if (curr+4<100005) c[curr+4]++;
			if (curr+2*x+4<100005) c[curr+2*x+4]++;
			curr+=2*x+4;
		}
	}
	
	cin>>n;
	cin>>s;
	
	vector<int> v;
	rep(x,n+1,1) v.pub(fix(c[x]+(x>=2?c[x-2]:0LL)));
	calc(1,n,v);
	f[0]=1;
	
	int fin=qexp(2,n,MOD);
	rep(_,0,2){
		rep(x,0,n) ans[x]=(s[x]=='0')?nCk(x,x/2):0LL;
		solve(0,n-1);
		rep(x,0,n) if (s[x]=='0') fin=fix(fin-ans[x]*nCk((n-x-1),(n-x-1)/2));
		
		for (auto &it:s) it^=1;
	}
	
	cout<<fin<<endl;
}