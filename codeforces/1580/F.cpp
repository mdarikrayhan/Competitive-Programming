#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
const int N=524293,mod=998244353,G=3,iG=(mod+1)/3;
inline int qpow(int a,int b){
	int R=1;
	for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)R=1ll*R*a%mod;
	return R;
}
inline int inv(int x){return qpow(x,mod-2);}
inline void chg(int& x){if(x>=mod)x-=mod;}
int SZ,iSZ,R[N];
void init(int S){
    for(SZ=1;SZ<S;SZ<<=1);
    iSZ=qpow(SZ,mod-2);
    FOR(i,1,SZ-1)R[i]=(R[i>>1]>>1)|((i&1)*SZ>>1);
}
struct poly{
	int n;vector<int>a;
	int& operator[](int x){return a[x];}
	void siz(int x){a.resize(x,0);}
	poly fit(int x){return siz(n=x),*this;}
	poly(int x=1,int A=0){n=x,siz(x),a[0]=A;}
	void ntt(int f){
		siz(SZ);
		FOR(i,0,SZ-1)if(i>R[i])swap(a[i],a[R[i]]);
		for(int i=1;i<SZ;i<<=1){
			const int w=qpow(~f?G:iG,(mod-1)/i/2);
			for(int j=0;j<SZ;j+=i*2){
				for(int e=1,k=0;k<i;e=1ll*e*w%mod,++k){
					int &x=a[j|k],y=1ll*a[i|j|k]*e%mod;
					chg(a[i|j|k]=x-y+mod),chg(x+=y);
				}
			}
		}
		if(f==-1)FOR(i,0,SZ-1)a[i]=1ll*a[i]*iSZ%mod;
	}
};
void Inv(poly f,poly& g,int D){
	if(D==1)return void(g[0]=inv(f[0]));
	Inv(f,g,(D+1)>>1);
	f.fit(D),init(D*2);
	f.ntt(1),g.ntt(1);
	FOR(i,0,SZ-1)g[i]=(mod+2-1ll*f[i]*g[i]%mod)*g[i]%mod;
	g.ntt(-1),g.siz(D);
}
poly Inv(poly f){
	poly rs(f.n);
	return Inv(f,rs,f.n),rs;
}
poly operator+(poly x,poly y){
	if(x.n<y.n)swap(x,y);
	FOR(i,0,y.n-1)chg(x[i]+=y[i]);
	return x;
}
poly operator-(poly f){
	FOR(i,0,f.n-1)f[i]=mod-f[i];
	return f;
}
poly operator*(poly x,poly y){
	init(x.n+=y.n-1),x.ntt(1),y.ntt(1);
	FOR(i,0,SZ-1)x[i]=1ll*x[i]*y[i]%mod;
	return x.ntt(-1),x;
}
poly operator-(poly x,poly y){return x+(-y);}
int n,m,rs;
poly solve(int m){
	if(!m)return poly(n+1,1);
	poly F=solve(m/2),A(n+1),B(n+1,1);
	FOR(i,1,n)(i&1?A[i]:B[i])=F[i];
	A[1]=(m+1)/2;
	poly I=Inv(poly(1,1)-A);
	F=A+B*B*I,rs=n&1?I[n]:(2ll*rs+I[n])%mod;
	FOR(i,3,n)rs=(rs+(i-1ll)*I[n-i]%mod*A[i])%mod;
	return F.fit(n+1);
}
signed main(){
	scanf("%d%d",&n,&m);
	solve(m),printf("%d",rs);
	return 0;
}