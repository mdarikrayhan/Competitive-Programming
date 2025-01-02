#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define order tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define F first
#define S second
#define EB emplace_back
#define int long long
#define sz(v) (int)v.size()
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<n;++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define per(i,a,b) for(lli i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define pb push_back
#define endl '\n'
typedef long long lli;        typedef long double ld;
typedef pair<lli,lli> ii;     typedef vector<lli> vi;
typedef vector<ii> vii;       typedef vector<vi> graph;
long double EPS=1e-9;
long long M = 998244353;
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr <<"["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
lli binpow(lli b,lli p){lli ans=1;;for(;p;p>>=1){if(p&1)ans=ans*b;b=b*b;}return ans;}
 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res *  a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

const int mod = 1e9+7;
const int inf = 1e18;
void pre(){
	
}
const int N = 1e6 + 9, LG = 18;

int n;
int a[N];
int pge[N],nge[N],nse[N],pse[N];

void solve(){
	
	cin>>n;
	
	fr(i,n) cin>>a[i+1];
	
	stack<int> c;
	
	rep(i,1,n){
		while(!c.empty() && a[c.top()]<a[i]){
			c.pop();
		} 
		if(c.empty()) pge[i] = 0;
		else pge[i] = c.top();
		c.push(i);
	}
	
	c = stack<int>();

	rep(i,1,n){
		while(!c.empty() && a[c.top()]>a[i]){
			c.pop();
		} 
		if(c.empty()) pse[i] = 0;
		else pse[i] = c.top();
		c.push(i);
	}
	
	c = stack<int>();
	
	per(i,n,1){
		while(!c.empty() && a[c.top()]>=a[i]){
			c.pop();
		} 
		if(c.empty()) nse[i] = n+1;
		else nse[i] = c.top();
		c.push(i);
	}
	
	c = stack<int>();
	
	per(i,n,1){
		while(!c.empty() && a[c.top()]<=a[i]){
			c.pop();
		} 
		if(c.empty()) nge[i] = n+1;
		else nge[i] = c.top();
		c.push(i);
	}
	
	int ans = 0;
	
	rep(i,1,n){
		int x = pse[i],y = nse[i];
		int l = i - x - 1;
		int r = y - i - 1;
		//cout<<x<<" "<<y<<endl;
		ans-=(l*r*a[i]+l*a[i]+r*a[i]);
		x = pge[i];y = nge[i];
		//cout<<x<<" "<<y<<endl;
		l = i - x -1;
		r  = y - i -1;
		ans+=(l*r*a[i]+l*a[i]+r*a[i]);
		//cout<<ans<<endl;
	}
	
	cout<<ans<<endl;
	
    return;    
}
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);//freopen("out.txt","w",stdout);
    lli t = 1;//cin>>t;
    //sieve();
    pre();
 
	for(lli i=1;i<=t;i++){
        //cout<<i<<endl;
        //cout<<"Case #"<<i<<": ";
        solve();
        
    }
}
