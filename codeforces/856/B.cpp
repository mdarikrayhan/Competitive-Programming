// LUOGU_RID: 158605062
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+5,B=13331;
const ll mod=100000000000031ll;
int T,n,m,tot,d[30],f[N][2],ans;
bool fl[N];
char s[N];
struct node{ll x,y;};
vector<int> ve[N];
vector<node> q;
unordered_map<ll,int> mp;
inline void ins(ll x){if(!mp[x])mp[x]=++tot;}
mt19937 rnd(time(0));
void dfs(int u){f[u][1]=1,f[u][0]=0;for(int v:ve[u])dfs(v),f[u][0]+=max(f[v][0],f[v][1]),f[u][1]+=f[v][0];}
signed main(){
	//freopen(".in","r",stdin);
	scanf("%d",&T);
	for(int i=1;i<=26;i++){do d[i]=rnd()&8191;while(fl[d[i]]);fl[d[i]]=true;}
	for(int i=1;i<=26;i++)fl[d[i]]=false;
	while(T--){
		scanf("%d",&n);mp.clear(),q.clear();ans=tot=0;
		for(int i=1;i<=n;i++){
			scanf("%s",s);int sz=strlen(s);ll u=d[s[0]^96],v=0;ins(u);
			for(int j=1;j<sz;j++)u=(u*B+d[s[j]^96])%mod,v=(v*B+d[s[j]^96])%mod,ins(u),q.pb({u,v});
		}
		for(node p:q)if(!fl[mp[p.x]]&&mp.count(p.y))fl[mp[p.x]]=true,ve[mp[p.y]].pb(mp[p.x]);
		for(int i=1;i<=tot;i++)if(!fl[i])dfs(i),ans+=max(f[i][0],f[i][1]);
		printf("%d\n",ans);
		for(int i=1;i<=tot;i++)fl[i]=false,ve[i].clear();
	}
	return 0;
}