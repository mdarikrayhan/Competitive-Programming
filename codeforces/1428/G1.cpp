// LUOGU_RID: 158950010
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
int T=1,n,m,q,k,S,M=999999;
int w[N],f[N];
il void add(int w,int v){
	for(int i=M;i>=w;i--)
		f[i]=max(f[i],f[i-w]+v);
}
il void upd(int w,int v){
	int c=min(k,M/w);
	for(int i=1;i<=c;i<<=1)add(i*w,i*v),c-=i;
	add(c*w,c*v);
}
signed main(){
	k=read()*3-3;n=6;
	for(int i=0;i<n;i++)
		w[i]=read();
	for(int i=0;i<=M;i++){
		int tmp=i,h=0;
		while(tmp){
			int c=tmp%10;
			if(c%3==0)f[i]+=w[h]*(c/3);
			h++;tmp/=10;
		}
	}
	int pw=3;
	for(int i=0;i<n;i++)
		upd(pw,w[i]),pw*=10;
	q=read();
	while(q--)
		printf("%lld\n",f[read()]);
	return 0;
}
