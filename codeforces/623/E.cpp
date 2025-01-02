#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using li=__int128;
const int N=1<<16,mod=1e9+7,P[]={998244353,469762049,1004535809};
int n,k,rev[N];
ll fc[N],inv[N];
inline ll md(ll x,int k){return x<P[k]?x:x-P[k];}
ll qp(ll a,int P,int b){ll ans=1;for(;b;b>>=1,a=a*a%P)if(b&1)ans=ans*a%P;return ans;}
struct Int{
	ll x[3];
	Int(){x[0]=x[1]=x[2]=0;}
	Int(ll a){x[0]=md(a,0),x[1]=md(a,1),x[2]=md(a,2);}
	Int(ll a,ll b,ll c){x[0]=md(a,0),x[1]=md(b,1),x[2]=md(c,2);}
	Int operator+(const Int&t){return {md(x[0]+t.x[0],0),md(x[1]+t.x[1],1),md(x[2]+t.x[2],2)};}
	Int operator-(const Int&t){return {md(x[0]-t.x[0]+P[0],0),md(x[1]-t.x[1]+P[1],1),md(x[2]-t.x[2]+P[2],2)};}
	Int operator*(const Int&t){return {x[0]*t.x[0]%P[0],x[1]*t.x[1]%P[1],x[2]*t.x[2]%P[2]};}
	friend ostream&operator<<(ostream&o,const Int&t){return o<<'('<<t.x[0]<<','<<t.x[1]<<','<<t.x[2]<<')';}
}i3; 
void exgcd(li a,li b,li&x,li&y) {
	if(!b)return x=1,y=0,void();
	exgcd(b,a%b,x,y);ll tx=x;
	x=y,y=tx-a/b*y;
}
ll get(Int v) {
	li Mod=1,A=0;
	for(int i=0;i<3;i++) {
		li x,y;exgcd(Mod,P[i],x,y);
		x=(x*(v.x[i]-A)%P[i]+P[i])%P[i],A+=x*Mod,Mod*=P[i];
	}return A%mod;
}
Int Inv(ll x){return Int(qp(x,P[0],P[0]-2),qp(x,P[1],P[1]-2),qp(x,P[2],P[2]-2));}
using Poly=vector<Int>;
void NTT(Poly&a,int l,int op) {
	for(int i=0;i<l;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<l;i<<=1) {
		Int wn(qp(op?3:i3.x[0],P[0],(P[0]-1)/(i<<1)),qp(op?3:i3.x[1],P[1],(P[1]-1)/(i<<1)),qp(op?3:i3.x[2],P[2],(P[2]-1)/(i<<1)));
		for(int j=0;j<l;j+=i<<1) {
			Int w(1),x,y;
			for(int k=0;k<i;k++,w=w*wn)x=a[j+k],y=a[i+j+k]*w,a[j+k]=x+y,a[i+j+k]=x-y; 
		}
	}
}
Poly operator*(Poly x,Poly y) {
	int n=x.size()+y.size()-2;Poly z(k+1);
	int l=1,r=0;while(l<=n)l<<=1,r++;
	for(int i=0;i<l;i++)rev[i]=rev[i>>1]>>1|(i&1)<<r-1;
	x.resize(l),y.resize(l),NTT(x,l,1),NTT(y,l,1);
	for(int i=0;i<l;i++)x[i]=x[i]*y[i];
	NTT(x,l,0);Int iv=Inv(l);
	for(int i=0;i<=k;i++)z[i]=Int(get(x[i]*iv));
	return z;
}
ll qp(ll a,ll b){ll ans=1;for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;return ans;}
void init(int n) {
	fc[0]=1;for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
	inv[n]=qp(fc[n],mod-2);
	for(int i=n-1;~i;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
Poly mk(int x) {
	Poly c(k+1);ll t=qp(2,x),v=1;
	for(int i=1;i<=k;i++)v=v*t%mod,c[i]=Int(inv[i]*v%mod);
	return c;
} 
Poly slv(int n) {
	if(n==1)return mk(0);
	Poly A=slv(n/2),B=A;ll t=qp(2,n/2),v=1;
	for(int i=1;i<=k;i++)v=v*t%mod,B[i]=Int(B[i].x[2]*v%mod);
	A=A*B;if(n&1)A=A*mk(n-1);
	return A;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll _;cin>>_>>k,n=_,init(k),i3=Inv(3);
	if(_>k)cout<<"0\n",exit(0);
	Poly r=slv(n);ll ans=0;
	for(int i=1;i<=k;i++)ans=(ans+r[i].x[2]*inv[k-i])%mod;
	cout<<ans*fc[k]%mod<<'\n';
	return 0;
}