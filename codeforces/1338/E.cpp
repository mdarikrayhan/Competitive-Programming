// LUOGU_RID: 158441481
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<ctime>
#include<map>
#include<set>
#include<bitset>
#include<list>

using namespace std;

bool d[8005][8005];
long long pt[8005],ans,INF,k,n,dfn[8005],low[8005],In[8005],st[8005],Top=0,T=0,cnt=0,vis[8005];
long long turn(char a) {
	if('0'<=a&&a<='9') return a-'0';
	else return 10+a-'A';
}
string s;
void tarjan(long long u) {
	dfn[u]=low[u]=++T;
	st[++Top]=u,vis[u]=1;
	for(long long v=1;v<=n;v++) {
		if(!d[u][v]) continue;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]) {
		cnt++;
		while(1) {
			long long x=st[Top--];
			vis[x]=0;
			if(cnt==1) pt[++k]=x;
			if(x==u) break;
		}
	}
}
long long p[8005],n1,q[8005],n2,inq[8005],inp[8005];
bool cmp(long long x,long long y) {
	return d[x][y];
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n,INF=614*n;
	for(long long i=1;i<=n;i++) {
		cin>>s;
		for(long long j=1;j<=n/4;j++) {
			long long t=turn(s[j-1]);
			for(long long k=0;k<=3;k++) d[i][4*j-k]=(t>>k)&1;
		}
	}
	for(long long i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	ans=(n-k)*(n-k-1)/2*(INF+1),ans+=(n-k)*k*(INF+1);
	long long Max=-1,x=-1;
	for(long long i=1;i<=k;i++) {
		for(long long j=1;j<=k;j++) if(d[pt[j]][pt[i]]) In[pt[i]]++;
		if(In[pt[i]]>Max) Max=In[pt[i]],x=pt[i];
	}
	p[++n1]=x;
	for(long long i=1;i<=k;i++) {
		if(pt[i]==x) continue;
		if(d[pt[i]][x]) p[++n1]=pt[i];
		else q[++n2]=pt[i];
	}
	sort(p+1,p+n1+1,cmp),sort(q+1,q+n2+1,cmp),ans+=n1*n2*3;
	long long now=n2;
	for(long long i=n1;i>=1;i--) {
		while(now&&d[q[now]][p[i]]) now--;
		inq[i]=now+1;
	}
	now=n1;
	for(long long i=n2;i>=1;i--) {
		while(now&&d[p[now]][q[i]]) now--;
		inp[i]=now+1;
	}
	for(long long i=1;i<=n1;i++) for(long long j=i+1;j<=n1;j++) {
		if(inq[i]==inq[j]) ans+=4;
		else ans+=3;
	}
	for(long long i=1;i<=n2;i++) for(long long j=i+1;j<=n2;j++) {
		if(inp[i]==inp[j]) ans+=4;
		else ans+=3;
	}
	cout<<ans;
	return 0;
}