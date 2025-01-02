// LUOGU_RID: 159736046
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using ld=__float128;
using uint=unsigned int;
using ull=unsigned long long;

//#define int long long
#define mk make_pair
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x.size())

template<class T>inline void gmin(T&a,T b) { if(a>b) a=b; }
template<class T>inline void gmax(T& a,T b) { if(a<b) a=b; }
template <class T>int lwb(vector<T> &a,const T &b) { return (int)(lower_bound(all(a),b)-a.begin()); }
template <class T>int upb(vector<T> &a,const T &b) { return (int)(upper_bound(all(a),b)-a.begin()); }

template<class T1,class T2> istream &operator>>(istream &cin,pair<T1,T2> &a) { return cin>>a.first>>a.second; }
template<class T>istream &operator>>(istream &cin,vector<T>&a) { for(auto &x:a) cin>>x; return cin; }
template<class T1,class T2> ostream &operator<<(ostream &cout,const pair<T1,T2> &a) { return cout<<a.first<<' '<<a.second; }
template<class T1> ostream &operator<<(ostream &cout,const vector<T1> &a) { if(sz(a)==0) return cout; int f=0; for(auto&x:a) cout<<(f++?" ":"")<<x; return cout; }

#ifdef DEBUG
#include <algo/debug.h>
#else
#define debug(...) (void)114
#define debug_s() (void)114
#define assert(...) (void)114
#endif

const int maxn=3e5+10;

// const int mod=998244353;
// const int mod=1e9+7;

const int big=1e9;
const ll BIG=1e18;

signed main() {
	int n; cin>>n;
	srand(11451419);
	vector<int>v(n);
	cin>>v;
	vector<int>id(n); iota(all(id),0);
	int tim=min((int(5e6))/n,4000);
	while(tim--) {
		random_shuffle(all(id));
		vector<int>g(2);
		vector<int>t(n);
		auto get=[&]() ->bool {
			t[id[0]]=1,g[0]=v[id[0]],t[id[1]]=2,g[1]=v[id[1]];
			for(int i=2; i<n; i++) {
				if(v[id[i]]%g[0]==0) t[id[i]]=2,g[1]=__gcd(g[1],v[id[i]]);
				else t[id[i]]=1,g[0]=__gcd(g[0],v[id[i]]);
			}
			return (g[0]==1&&g[1]==1);
		};
		if(get()==1) {
			cout<<"YES\n";
			cout<<t<<'\n';
			return 0;
		}
	}
	cout<<"NO\n";
    return 0;
}