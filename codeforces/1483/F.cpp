// LUOGU_RID: 160629909
#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#define pb push_back
using namespace std;
const int N=1e6+5,C=26;
int len[N],ch[N][C],fa[N],tot,fail[N],mx[N];
int Q[N],L=1,R,st[N],ed[N],idx;
int c[N],pos[N],n,ans;
vector<int>G[N],S[N];
map<int,int>mp;
char str[N];
inline void add(int x,int v){
	for(;x<=idx;x+=x&-x) c[x]+=v;
}
inline int ask(int x){
	int ans=0;
	for(;x;x-=x&-x) ans+=c[x];
	return ans;
}
inline int ask(int l,int r){return ask(r)-ask(l-1);}
inline void ins(char *st,int id){
	len[id]=strlen(st);
	int p=0;
	for(int i=0;i<len[id];++i){
		int c=st[i]-'a';
		if(!ch[p][c]) fa[ch[p][c]=++tot]=p;
		p=ch[p][c],S[id].pb(p);
	}
	pos[id]=p,mx[p]=id;
}
inline void dfs(int x){
	st[x]=++idx;
	for(auto v:G[x]) dfs(v);
	ed[x]=idx;
}
inline void build(){
	for(int i=0;i<C;++i)
		if(ch[0][i]) Q[++R]=ch[0][i];
	while(L<=R){
		int x=Q[L++];
		for(int i=0;i<C;++i)
			if(!ch[x][i]) ch[x][i]=ch[fail[x]][i];
			else fail[ch[x][i]]=ch[fail[x]][i],Q[++R]=ch[x][i];
		mx[x]=mx[x]?mx[x]:mx[fail[x]],G[fail[x]].pb(x);
	}
	dfs(0);
}
int Id[N],Pos[N],cnt;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>str,ins(str,i);
	build();
	for(int id=1;id<=n;++id){
		for(int j=pos[id];j;j=fa[j]) add(st[j],1);
		mp.clear(),cnt=0;
		for(int i=0,p;i<len[id];++i){
			p=S[id][i];
			if(i==len[id]-1) p=fail[p];
			if(mx[p]) Id[++cnt]=i-len[mx[p]]+1,Pos[cnt]=mx[p];
		}
		for(int i=cnt,lim=N;i;--i)
			if(Id[i]<lim) lim=Id[i],++mp[Pos[i]];
		#define fi first
		#define se second
		for(auto v:mp) ans+=ask(st[pos[v.fi]],ed[pos[v.fi]])==v.se;
		for(int j=pos[id];j;j=fa[j]) add(st[j],-1);		
	}
	cout<<ans<<"\n";
}