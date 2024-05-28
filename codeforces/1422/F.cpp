// LUOGU_RID: 158541164
#include <cstdio>
#include <cstring>
#include <algorithm>
#define V 200000
#define mod 1000000007
using namespace std;

int n,q,tot;
int mn[200005];
int rt[200005];
int las[200005];
int inv[200005];
int t[40000005];
int lc[40000005];
int rc[40000005];

inline void in(int &n){
	n=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return ;
}

inline void updata(int &u,int l,int r,int k,int x){
	tot++;
	lc[tot]=lc[u],rc[tot]=rc[u],t[tot]=t[u];
	u=tot;
	if(l==r){t[u]=1ll*t[u]*x%mod;return ;}
	int mid=(l+r)>>1;
	if(k<=mid) updata(lc[u],l,mid,k,x);
	else updata(rc[u],mid+1,r,k,x);
	t[u]=1ll*t[lc[u]]*t[rc[u]]%mod;
	return ;
}

inline int query(int u,int l,int r,int L,int R){
	if(!u) return 1;
	if(L<=l&&r<=R) return t[u];
	int mid=(l+r)>>1,mul=1;
	if(L<=mid) mul=1ll*mul*query(lc[u],l,mid,L,R)%mod;
	if(R>mid) mul=1ll*mul*query(rc[u],mid+1,r,L,R)%mod;
	return mul;
}

int main(){
	in(n);
	inv[1]=1;
	for(int i=2;i<=V;i++){
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		if(!mn[i]) for(int j=i;j<=V;j+=i) mn[j]=i;
	}
	t[0]=1;
	for(int i=1;i<=n;i++){
		int x;
		in(x);
		rt[i]=rt[i-1];
		while(mn[x]){
			int k=mn[x],t=1;
			while(x%k==0){
				t*=k;
				if(las[t]) updata(rt[i],1,n,las[t],inv[k]);
				las[t]=i;
				x/=k;
			}
			updata(rt[i],1,n,i,t);
		}
	}
	in(q);
	int las=0;
	while(q--){
		int l,r;
		in(l),in(r);
		l=(l+las)%n+1;
		r=(r+las)%n+1;
		if(l>r) swap(l,r);
		printf("%d\n",las=query(rt[r],1,n,l,r));
	}

	return 0;
}