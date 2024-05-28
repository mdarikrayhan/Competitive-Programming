// LUOGU_RID: 159836383
#include<bits/stdc++.h>
using namespace std;
#define N 110
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
int s[N];
il bool ask1(int x,int y){
	printf("1 %lld %lld\n",x-1,y-1);
	fflush(stdout);
	return read();
}
il bool ask2(int x,int p){
	printf("2 %lld %lld ",x-1,p);
	for(int i=1;i<=p;i++)
		printf("%lld ",s[i]-1);
	puts("");
	fflush(stdout);
	return read();
}
il void ins(int x,int p){
	m++;
	for(int i=m;i>p;i--)
		s[i]=s[i-1];
	s[p]=x;
}
vector<int> v[N];
int vis[N];
int f[N][N];
il void print(){
	puts("3");
	fflush(stdout);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%lld",f[i][j]);
		puts("");
		fflush(stdout);
	}
}
void solve(){
	n=read();m=0;
	s[++m]=1;
	for(int i=2;i<=n;i++){
		int l=1,r=m,p=m+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(ask1(i,s[mid]))p=mid,r=mid-1;
			else l=mid+1;
		}
		ins(i,p);
	}
	for(int i=1;i<=n;i++)
		v[i].clear(),v[i].pb(s[i]),vis[i]=0;
	for(int i=m;i>1;i--){
		for(auto x:v[i]){
			if(vis[x])continue;
			if(ask2(x,i-1)){
				for(auto y:v[i])v[i-1].pb(y);
				v[i].clear();
				break;
			}
			vis[x]=1;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		f[i][j]=0;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)
		for(auto x:v[i])for(auto y:v[j])
			f[x][y]=1;
	print();
	int tmp=read();
}
signed main(){
	T=read();
	while(T--)solve();
	return 0;
}
