#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define p 998244353
#define ll long long
int n,len;ll m;
ll s[N],h[N],a[N*3],b[N*3],fac[N],inv[N],pinv[N];
inline ll qpow(ll a,ll b){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
void ntt(ll a[],int n,int opt){
    static int rev[300000];
    for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1),(i&1)&&(rev[i]|=n>>1);
    for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int l=2,m=1;l<=n;l<<=1,m<<=1){
        ll wn=qpow(opt==1?3:qpow(3,p-2),(p-1)/l);
        for(int i=0;i<n;i+=l){
            for(int j=0,w=1;j<m;j++,w=w*wn%p){
                ll t=w*a[i|j|m]%p;
                a[i|j|m]=(a[i|j]-t+p)%p;
                a[i|j]=(a[i|j]+t)%p;
            }
        }
    }
    if(opt==-1){ll inv=qpow(n,p-2);for(int i=0;i<n;i++)a[i]=a[i]*inv%p;}
}
void translate(ll f[],ll c,ll g[]){//f(x+c)-> g(x)
    for(int i=0;i<len;i++)a[i]=b[i]=0;
    for(int i=0;i<=n;i++)a[i]=f[n-i]*fac[n-i]%p,b[i]=qpow((c%p+p)%p,i)%p*pinv[i]%p;
    ntt(a,len,1);ntt(b,len,1);
    for(int i=0;i<len;i++)a[i]=a[i]*b[i]%p;
    ntt(a,len,-1);
    for(int i=0;i<=n;i++)g[i]=a[n-i]*pinv[i]%p;
}
int main(){
    scanf("%d%lld",&n,&m);len=1<<__lg(n)+2;
    fac[0]=inv[0]=pinv[0]=fac[1]=inv[1]=pinv[1]=1;
    for(int i=2;i<=n+1;i++)fac[i]=fac[i-1]*i%p,inv[i]=inv[p%i]*(p-p/i)%p,pinv[i]=pinv[i-1]*inv[i]%p;
    for(int i=0;i<=n;i++)scanf("%lld",&s[i]);
    for(int i=n;i>=0;i--)s[i]=(s[i]*inv[i+1]%p+s[i+1])%p;
    translate(s,1,h);
    for(int i=0;i<=n;i++)h[i]=h[i]*qpow(qpow(i+1,m),p-2)%p;
    translate(h,-1,s);
    for(int i=0;i<=n;i++)printf("%lld ",(s[i]-s[i+1]+p)%p*(i+1)%p);

}
 				 		 			  					 						 			