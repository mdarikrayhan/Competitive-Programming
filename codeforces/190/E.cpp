// LUOGU_RID: 159948820
#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
#define db long double
#define pii pair<int,int>
#define pb push_back
#define st first
#define ed second
#define mod 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define il inline
#define umap unordered_map
#define eps 1e-9
il int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int T=1,n,m,q,k,S;
int d[N],vis[N],vs[N];
vector<int> v[N];
int f[N],sz[N];
il int fd(int x){
	if(x==f[x])return x;
	return f[x]=fd(f[x]);
}
il void link(int x,int y){
	int a=fd(x),b=fd(y);
	if(a!=b)f[a]=b,sz[b]+=sz[a];
}
vector<int> ans[N];
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		d[i]=n-1,f[i]=i,sz[i]=1;
	for(int i=1,x,y;i<=m;i++){
		x=read(),y=read();
		d[x]--,d[y]--;
		v[x].pb(y),v[y].pb(x);
	}
	int p=1;
	for(int i=2;i<=n;i++)
		if(d[i]>d[p])p=i;
	vis[p]=1;
	for(int i=1;i<=n;i++)
		vs[i]=0;
	for(auto y:v[p])vs[y]=1;
	for(int i=1;i<=n;i++)
		if(!vs[i])link(i,p),vis[i]=1;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		for(int j=1;j<=n;j++)
			vs[j]=0;
		for(auto j:v[i])vs[j]=1;
		for(int j=1;j<=n;j++)
			if(!vs[j])link(i,j);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		ans[fd(i)].pb(i);
		if(f[i]==i)cnt++;
	}
	printf("%lld\n",cnt);
	for(int i=1;i<=n;i++)
		if(f[i]==i){
			printf("%lld ",sz[i]);
			for(auto x:ans[i])printf("%lld ",x);
			puts("");
		}
	return 0;
}
