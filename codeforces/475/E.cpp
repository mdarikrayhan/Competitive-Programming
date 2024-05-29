// LUOGU_RID: 157685864
#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=2e3+5,M=34005;
inline int read() {
	char ch=getchar();
	bool f=0;
	int x=0;
	for(; !isdigit(ch); ch=getchar())if(ch=='-')f=1;
	for(; isdigit(ch); ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;
	return x;
}
inline void print(int x) {
	static int a[55];
	int top=0;
	if(x<0) putchar('-'),x=-x;
	do {
		a[top++]=x%10,x/=10;
	} while(x);
	while(top) putchar(a[--top]+48);
}
int n,m,low[maxn],dfn[maxn],tot=0,st[maxn],idx,sz[maxn];
int ans=0,s[maxn],res,id[maxn],a,b,cnt,sum=0;
vector<int>e[maxn],E[maxn];
bitset<2005>f;
void tarjan(int x,int fa) {
	dfn[x]=++cnt;
	low[x]=dfn[x];
	st[++tot]=x;
	for(auto i:e[x])
		if(i!=fa) {
			if(!dfn[i]) tarjan(i,x),low[x]=min(low[x],low[i]);
			else low[x]=min(low[x],dfn[i]);
		}
	if(dfn[x]==low[x]) {
		++idx;
		while(st[tot]!=x&&tot>0)s[idx]++,id[st[tot]]=idx,tot--;
		s[idx]++,id[st[tot]]=idx,tot--;
		sum+=s[idx]*s[idx];
	}
}
void dfs(int x,int fa) {
	sz[x]=s[x];
	for(auto i:E[x])
		if(i^fa)
			dfs(i,x),sz[x]+=sz[i];
	res+=s[x]*(sz[x]-s[x]);
}
signed main() {
	n=read();
	m=read();
	for(int i=1; i<=m; i++)
		a=read(),b=read(),e[a].push_back(b),e[b].push_back(a);
	for(int i=1; i<=n; i++)
		if(!dfn[i])tarjan(i,0);
	for(int i=1; i<=n; i++)
		for(auto j:e[i])
			if(id[i]!=id[j])E[id[i]].push_back(id[j]);
	for(int i=1; i<=idx; i++) {
		memset(sz,0,sizeof sz);
		res=0;
		dfs(i,0);
		f.reset();
		f[0]=1;
		for(auto j:E[i])f=f|(f<<sz[j]);
		for(int j=(sz[i]-s[i])/2; j>=0; j--)
			if(f[j]) {
				res+=j*(n-j-s[i]);
				break;
			}
		ans=max(ans,res);
	}
	cout<<ans+sum<<endl;
	return 0;
}