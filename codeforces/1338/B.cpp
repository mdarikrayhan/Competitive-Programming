// LUOGU_RID: 160110759
#include <bits/stdc++.h>
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mp_ make_pair
#define pb_ push_back
#define pob_ pop_back
#define fst first
#define snd second
#define debug cout<<"********\n";
#define reset(x,y) memset(x,y,sizeof(x))
#define fi(x) freopen(x,"r",stdin)
#define fo(x) freopen(x,"w",stdout)
#define iosf ios::sync_with_stdio(0);cin.tie(0);
#define prec(x) cout<<setprecision(x);
#define prec0(x) cout<<fixed<<setprecision(x);
#define Misaka16172 sb
#define kamisako femboy

using ll = long long;
using ld = long double;
using db = double;
using ull = unsigned long long;
using uint = unsigned int;

constexpr int inf = 0x3f3f3f3f;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ull mod1 = 1e9+7,mod9 = 998244353;

using namespace std;

template <class T>
inline void read(T &x){
	x = 0;T w = 1;
	char c = 0;
	while(c<'0' || c>'9'){
		if(c=='-')	w = -1;
		c = getchar();
	}
	while(c>='0' && c<='9'){
		x = ((x<<3)+(x<<1))+c-'0';
		c = getchar();
	}
	x = x*w;
}

template <class T>
inline string bin(T x){
	string res = "";
	if(x>>1)	res = bin(x>>1);
	res+=(x&1)+'0';
	return res;
}

constexpr int N = 1e5+5;

int n,deg[N],dep[N];
int ans1 = 1,ans2,rt;
bool leaf[N];

vector<int> tr[N];
inline void add_edge(int u,int v){tr[u].pb_(v);deg[v]++;}

void dfs1(int u,int f){
	dep[u] = dep[f]+1;
	leaf[u] = 1;
	for(int v:tr[u]){
		if(v==f)	continue;
		dfs1(v,u);
		if(u!=rt)	leaf[u] = 0;
	}
	if(leaf[u] && (dep[u]&1))	ans1 = 3;
}

void dfs2(int u,int f){
	int c = 1;
	for(int v:tr[u]){
		if(v==f)	continue;
		if(leaf[v]){
			ans2+=c;
			c = 0;
		}
		else{
			ans2++;
			dfs2(v,u);
		}
	}
}

void solve(){
	read(n);
	for(int i=1;i<n;i++){
		int u,v;read(u);read(v);
		add_edge(u,v);add_edge(v,u);
	}
	dep[0] = -1;
	for(int i=1;i<=n;i++){
		if(deg[i]==1){rt = i;dfs1(i,0);break;}
	}
	cout<<ans1<<" ";
	for(int i=1;i<=n;i++){
		if(deg[i]>1){dfs2(i,0);break;}
	}
	cout<<ans2;
}

int main(){
	int t = 1;
//	read(t);
	for(int tt=1;tt<=t;tt++){
		solve();
	}
    return 0;
}