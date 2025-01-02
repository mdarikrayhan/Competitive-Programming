// Problem: H. Triple
// Contest: Codeforces - Codeforces Global Round 2
// URL: https://codeforces.com/problemset/problem/1119/H
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define fi first
#define se second
#define inf 1e9
#define infll 1e18
#define pii pair<int,int>
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define dF(i,a,b) for(int i=a;i>=(b);i--)
#define wh(lzm) while(lzm--)
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
#define HH printf("\n")
#define eb emplace_back
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int mod=998244353,maxn=500005;
int qpow(int x,ll y){
	int rt=1;
	for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) rt=1ll*rt*x%mod;
	return rt;
}
void inc(int &x,int y){ x=(x+y>=mod)?(x+y-mod):(x+y); }
void dec(int &x,int y){ x=(x>=y)?(x-y):(x+mod-y); }
void mul(int &x,int y){ x=1ll*x*y%mod; }
int add(int x,int y){ return (x+y>=mod)?(x+y-mod):(x+y); }
int sub(int x,int y){ return (x>=y)?(x-y):(x+mod-y); }
int prod(int x,int y){ return 1ll*x*y%mod; }
void chkmax(int &x,int y){ x=max(x,y); }
void chkmin(int &x,int y){ x=min(x,y); }
int k,mx,xA,xB,xC,S,f[maxn],p1[maxn],p2[maxn],p3[maxn],n;
const int inv2=(mod+1)>>1;
void FWT_XOR(int *A,int typ=1){
	for(int i=1;i<(1<<k);i<<=1) for(int j=0;j<(1<<k);j+=(i<<1)) F(k,0,i-1){
		int x=A[i+j+k],y=A[j+k];
		A[j+k]=add(x,y),A[i+j+k]=sub(x,y);
		if(typ<0) mul(A[j+k],inv2),mul(A[i+j+k],inv2);
	}
}
void FMT_XOR_1(int *A){
	for(int i=1;i<(1<<k);i<<=1) for(int j=0;j<(1<<k);j+=(i<<1)) F(k,0,i-1){
		int x=A[j+k],y=A[i+j+k];
		A[j+k]=x-y,A[i+j+k]=x+y;
	}
}
signed main(){
	n=read(),k=read(),mx=(1<<k)-1,xA=read(),xB=read(),xC=read();
	F(i,1,n){
		int a=read(),b=read(),c=read();
		S^=a,b^=a,c^=a,p1[b]++,p2[c]++,p3[b^c]++;
	}
	FMT_XOR_1(p1),FMT_XOR_1(p2),FMT_XOR_1(p3);
	int A=add(xA,add(xB,xC)),B=add(xA,sub(xB,xC)),C=add(xA,sub(xC,xB)),D=sub(sub(xA,xB),xC);
	F(i,0,mx){
	    int c1=(n+p1[i]+p2[i]+p3[i])/4;
	    f[i]=1ll*qpow(A,c1)*qpow(B,(n+p1[i]-c1-c1)/2)%mod*qpow(C,(n+p2[i]-c1-c1)/2)%mod*qpow(D,(n+p3[i]-c1-c1)/2)%mod;
	}
	FWT_XOR(f,-1);
	F(i,0,mx) cout<<f[i^S]<<' ';
}