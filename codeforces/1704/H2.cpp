#include<bits/stdc++.h>
#define poly vector<int>
using namespace std;
const int maxn=1<<18;
int _g,n,len,mod;
int r[maxn],fac[maxn];
poly f,g,h,u,res;
inline int qpow(int a,int k)
{
    int ans=1;
    while(k)
    {
        if(k&1) ans=1ll*ans*a%mod;
        a=1ll*a*a%mod,k/=2;
    }
    return ans;
}
inline bool check(int g)
{
    for(int i=2;i*i<=mod;i++)
    {
        if((mod-1)%i) continue;
        if(qpow(g,i)==1) return false;
        if(qpow(g,(mod-1)/i)==1) return false;
    }
    return true;
}
inline int add(int x,int y)
{
    if((x+=y)>=mod) x-=mod;
    return x;
}
inline int dec(int x,int y)
{
    if((x-=y)<0) x+=mod;
    return x;
}
inline void ntt(poly &a,int n,int opt)
{
    static int g=_g,invg=qpow(g,mod-2);
    for(int i=0;i<n;i++) if(i<r[i]) swap(a[i],a[r[i]]);
    for(int k=2,m=1;k<=n;k*=2,m*=2)
    {
        int x=qpow(opt==1?g:invg,(mod-1)/k);
        for(int i=0;i<n;i+=k)
            for(int j=i,w=1;j<i+m;j++)
            {
                int v=1ll*a[j+m]*w%mod;
                a[j+m]=dec(a[j],v),a[j]=add(a[j],v);
                w=1ll*w*x%mod;
            }
    }
    if(opt==-1)
    {
        int inv=qpow(n,mod-2);
        for(int i=0;i<n;i++) a[i]=1ll*a[i]*inv%mod;
    }
}
inline poly operator+(poly a,int n)
{
    a[0]=add(a[0],n);
    return a;
}
inline poly operator-(poly a)
{
    for(int i=0;i<a.size();i++) a[i]=(mod-a[i])%mod;
    return a;
}
inline poly operator+(poly a,poly b)
{
    poly res(max(a.size(),b.size()));
    for(int i=0;i<res.size();i++) res[i]=add(i<a.size()?a[i]:0,i<b.size()?b[i]:0);
    return res;
}
inline poly operator-(poly a,poly b)
{
    poly res(max(a.size(),b.size()));
    for(int i=0;i<res.size();i++) res[i]=dec(i<a.size()?a[i]:0,i<b.size()?b[i]:0);
    return res;
}
inline poly operator<<(poly a,int n)
{
    for(int i=a.size()-1;i>=n;i--) a[i]=a[i-n];
    for(int i=n-1;i>=0;i--) a[i]=0;
    return a;
}
inline poly operator*(poly a,poly b)
{
    int n=a.size()-1,m=b.size()-1,len=1;
    for(;len<=n+m;len*=2) ;
    a.resize(len),b.resize(len);
    for(int i=0;i<len;i++) r[i]=(r[i>>1]>>1)|(i&1?len>>1:0);
    ntt(a,len,1),ntt(b,len,1);
    for(int i=0;i<len;i++) a[i]=1ll*a[i]*b[i]%mod;
    ntt(a,len,-1),a.resize(n+m+1);
    return a;
}
inline void operator*=(poly &a,poly b)
{
    a=a*b;
}
inline poly inv(poly a,int n)
{
    poly b(n);
    a.resize(n),b[0]=qpow(a[0],mod-2);
    for(int k=2;k<=n;k*=2)
    {
        poly c(a.begin(),a.begin()+k),d(b.begin(),b.begin()+k/2);
        c=d*d*c;
        for(int i=0;i<k;i++) b[i]=(2ll*b[i]-c[i]+mod)%mod;
    }
    return b;
}
inline poly diff(poly a,int n)
{
    poly b(n);
    for(int i=1;i<n;i++) b[i-1]=1ll*a[i]*i%mod;
    return b;
}
inline poly integ(poly a,int n)
{
    poly b(n);
    for(int i=1;i<n;i++) b[i]=1ll*a[i-1]*qpow(i,mod-2)%mod;
    return b;
}
inline poly ln(poly a,int n)
{
    a.resize(n);
    return integ(diff(a,n)*inv(a,n),n);
}
inline poly exp(poly a,int n)
{
    poly b(1);
    a.resize(n),b[0]=1;
    for(int k=2;k<=n;k*=2)
    {
        poly c=ln(b,k);
        for(int i=0;i<k;i++) c[i]=dec(a[i],c[i]);
        b*=c+1,b.resize(k);
    }
    return b;
}
inline void newton(poly &f,poly &g,int n)
{
    f={0};
    for(int k=2;k<=n;k*=2)
    {
        poly a=exp(f,k)<<1,b=a*f;
        b.resize(k);
        poly c=exp(b,k)<<1;
        poly d=b+c-f;
        poly e=a*(f+1);
        e.resize(k),e*=(c+1);
        e.resize(k),e[0]=mod-1;
        d*=inv(e,k),d.resize(k);
        f=f-d;
    }
    g=exp((f*exp(f,n))<<1,n)<<1;
}
int main()
{
    scanf("%d%d",&n,&mod),fac[0]=1;
    for(len=1;len<=n;len*=2) ;
    for(int i=1;i<len;i++) fac[i]=1ll*fac[i-1]*i%mod;
    for(_g=2;!check(_g);_g++) ;
    newton(f,g,len);
    u=exp(f,len)<<1;
    h=(u+f-g)*(g+1),h.resize(len);
    res=exp((-ln(poly{1}-h,len)-(f-g))-(-ln(poly{1}-u,len)),len);
    for(int i=1;i<=n;i++) printf("%lld\n",1ll*res[i]*fac[i]%mod);
    return 0;
}