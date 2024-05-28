// LUOGU_RID: 158586223
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,w,k,tot,ans;
int a[500005];
int b[500005];
int rt[500005];
int s[500005];
int s1[500005];
struct node{int l,r,s,x;}t[10000005];

inline void in(int &n){
	n=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return ;
}

inline void update(int &u,int l,int r,int x){
	tot++;
	t[tot]=t[u];t[tot].s++;t[tot].x+=x/2;
	u=tot;
	int mid=(l+r)>>1;
	if(l<r){
		if(x<=mid) update(t[u].l,l,mid,x);
		else update(t[u].r,mid+1,r,x);
	}
}

inline int query(int u,int v,int l,int r,int k){
	if(l>=r) return l/2*(t[u].s-t[v].s-k+1);
	int x=t[t[u].l].s-t[t[v].l].s;
	int y=t[u].x-t[v].x-(t[t[u].l].x-t[t[v].l].x);
	int mid=(l+r)>>1;
	if(x>=k) return query(t[u].l,t[v].l,l,mid,k)+y;
	else return query(t[u].r,t[v].r,mid+1,r,k-x);
}

signed main(){
	in(n),in(w),in(k);
	for(int i=1;i<=n;++i) in(a[i]);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;++i){
		in(b[i]);
		rt[i]=rt[i-1];
		update(rt[i],1,10000,b[i]);
	}
	for(int i=1;i<=n;++i) s1[i]=s1[i-1]+b[i];
	int r=0;
	for(int l=1;l<=n;++l){
		while(r<n&&s1[r+1]-s1[l-1]-query(rt[r+1],rt[l-1],1,10000,r+3-l-min(w,r+2-l))<=k) r++;
		ans=max(ans,s[r]-s[l-1]);
	}
	printf("%d\n",ans);

	return 0;
}