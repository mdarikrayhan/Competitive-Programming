// LUOGU_RID: 160011505
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
il int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y);
}
int f[21][N],lg[N];
struct node{
	int x,p;
}s[N];
int fa[N];
il int fd(int x){
	if(x==fa[x])return x;
	return fa[x]=fd(fa[x]);
}
il bool cmp(node a,node b){
	return a.x<b.x;
}
void solve(){
	n=read();k=read();
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)s[i].x=read(),f[0][i]=s[i].x,s[i].p=i;
	for(int k=1;k<=lg[n];k++)
		for(int i=1;i+(1<<k)-1<=n;i++)
			f[k][i]=gcd(f[k-1][i],f[k-1][i+(1<<(k-1))]);
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(s+1,s+1+n,cmp);
	int num=0,ans=0;
	for(int i=1;i<=n;i++){
		if(s[i].x>=k)break;
		int l=s[i].p,r=s[i].p;
		for(int k=lg[n];k>=0;k--)
			if(l-(1<<k)>=1&&(f[k][l-(1<<k)]%s[i].x==0))
				l-=(1<<k);
		for(int k=lg[n];k>=0;k--)
			if(r+(1<<k)<=n&&(f[k][r+1]%s[i].x==0))
				r+=(1<<k);
		for(int j=fd(l);j<r;j=fd(j)){
			ans+=s[i].x;num++;
			fa[j]=j+1;
		}
	}
	printf("%lld\n",ans+(n-1-num)*k);
}
signed main(){
	T=read();
	while(T--)solve();
	return 0;
}
