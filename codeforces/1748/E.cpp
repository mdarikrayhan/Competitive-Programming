// LUOGU_RID: 160179781
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f; 
}
const int md=1e9+7,mxn=2e5+10;
int a[mxn],n,m,tree[mxn*40];
map<int,int>dp[mxn];
void pushup(int o){
	if(a[tree[o*2]]>=a[tree[o*2+1]])tree[o]=tree[o*2];
	else tree[o]=tree[o*2+1];
}
void build(int o,int l,int r){
	if(l==r){
		tree[o]=l;
		return;
	}		
	int mid=(l+r)>>1;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
	pushup(o);
}
int query(int o,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tree[o];
	int mid=(l+r)>>1,res=0;
	if(L>mid)return query(o*2+1,mid+1,r,L,R);
	if(R<=mid)return query(o*2,l,mid,L,R);
	res=query(o*2,l,mid,L,R);
	int res2=query(o*2+1,mid+1,r,L,R);
	if(a[res]>=a[res2])return res;
	else return res2;
}
int dfs(int l,int r){
	if(l>r)return -1;
	if(l==r){
		for(int i=1;i<=m;i++)
			dp[l][i]=i;
		return l;
	}
	int id=query(1,1,n,l,r);
	int L=dfs(l,id-1);
	int R=dfs(id+1,r);
	if(L==-1){
		for(int i=1;i<=m;i++)
			dp[id][i]=(dp[R][i]+dp[id][i-1])%md;
	}
	else if(R==-1){
		for(int i=1;i<=m;i++)
			dp[id][i]=(dp[L][i-1]+dp[id][i-1])%md;		
	}
	else{
		for(int i=1;i<=m;i++)
			dp[id][i]=(dp[L][i-1]*dp[R][i]%md+dp[id][i-1])%md;
	}
	return id;
}
signed main(){
// 	freopen("in.txt","r",stdin);
// 	freopen("out.txt","w",stdout);
	int T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++)
			a[i]=read(),dp[i].clear();
		build(1,1,n);
		printf("%lld\n",dp[dfs(1,n)][m]);
	}
    return 0;
}