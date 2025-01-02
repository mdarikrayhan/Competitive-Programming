// LUOGU_RID: 160085170
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+100;
#define rd read()
inline int read(){
	int x=0,f=1; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return f*x;
}

int n,m,a[N],mex[N],grp[N];

int head[N],ne[N],v[N],tot=0;
void add(int x,int y){ ne[++tot]=head[x]; head[x]=tot; v[tot]=y; }

int vis[N],oc[N];
void dfs(int u){
	if(vis[u]) return; vis[u]=1;
	for(int i=head[u];i;i=ne[i]) dfs(v[i]);
	for(int i=head[u];i;i=ne[i]) oc[mex[v[i]]]=1;
	for(mex[u]=0;oc[mex[u]];mex[u]++);
	for(int i=head[u];i;i=ne[i]) oc[mex[v[i]]]=0;
}

signed main(){
	
	n=rd;m=rd;
	for(int i=1;i<=n;i++) a[i]=rd;
	for(int i=1,x,y;i<=m;i++) x=rd,y=rd,add(x,y);
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	
	int cnt=0; for(int i=1;i<=n;i++) grp[mex[i]]^=a[i],cnt=max(cnt,mex[i]);
	int f=0; for(int i=0;i<=cnt;i++) if(grp[i]!=0) f=1;
	
	if(!f) printf("LOSE\n");
	else{
		printf("WIN\n");
		int ma=0; for(int i=0;i<=cnt;i++) if(grp[i]) ma=i;
		int u=0; for(int i=1;i<=n;i++) if(mex[i]==ma&&(a[i]^grp[ma])<a[i]) u=i;
		a[u]^=grp[mex[u]]; grp[mex[u]]=0;
		for(int i=head[u];i;i=ne[i]) if(grp[mex[v[i]]]) a[v[i]]^=grp[mex[v[i]]],grp[mex[v[i]]]=0;
		for(int i=1;i<=n;i++) printf("%lld ", a[i]);
	}
	
	return 0;
}