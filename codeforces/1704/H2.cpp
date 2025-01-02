#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=2147483647;
const long long sq5=200717101;
int M;
namespace poly{
    int R[N*4];
    long long qpow(long long a,long long b){
        long long ans=1;
        while(b){
            if(b&1)
                ans=ans*a%M;
            a=a*a%M;
            b>>=1;
        }
        return ans;
    }
    long long wn[N*4],iwn[N*4],inv[N*4],fac[N*4],ifac[N*4],g;
    void init(int E){
        int i;
        iwn[E/2]=wn[E/2]=1;
        long long s1=qpow(g,(M-1)/E);
        long long s2=qpow(s1,M-2);
        for(i=E/2+1;i<E;++i){
            wn[i]=wn[i-1]*s1%M;
            iwn[i]=iwn[i-1]*s2%M;
        }
        for(i=E/2-1;i;--i){
            wn[i]=wn[i<<1];
            iwn[i]=iwn[i<<1];
        }
        ifac[0]=fac[0]=inv[1]=1;
        for(i=2;i<E;++i)
            inv[i]=inv[M%i]*(M-M/i)%M;
        for(i=1;i<E;++i){
            ifac[i]=inv[i]*ifac[i-1]%M;
            fac[i]=fac[i-1]*i%M;
        }
    }
    unsigned long long ccc[N*4];
    void NTT(long long *f,int lim,int op){
        int i,j,k;
        for(i=0;i<lim;++i){
            R[i]=(R[i>>1]>>1)|(i&1?lim>>1:0);
            if(R[i]<i)
                swap(f[R[i]],f[i]);
        }
        for(i=0;i<lim;++i)
            ccc[i]=(f[i]%M+M)%M;
        for(i=1;i<lim;i<<=1)
            for(j=0;j<lim;j+=(i<<1))
                for(k=j;k<j+i;++k){
                    long long w=(op==1?wn[k-j+i]:iwn[k-j+i]);
                    unsigned long long p=ccc[k+i]*w%M;
                    ccc[k+i]=ccc[k]+M-p;
                    ccc[k]+=p;
                }
        for(i=0;i<lim;++i)
            f[i]=ccc[i]%M;
        if(op==-1){
            long long inv=qpow(lim,M-2);
            for(i=0;i<lim;++i)
                f[i]=f[i]*inv%M;
        }
    }
    long long ta[N*4],tb[N*4];
    void mult(long long *a,int n,long long *b,int m,long long *c){
        int lim=1;
        while(lim<n+m)
            lim<<=1;
        copy(a,a+n,ta);
        copy(b,b+m,tb);
        for(int i=n;i<lim;++i)
            ta[i]=0;
        for(int i=m;i<lim;++i)
            tb[i]=0;
        NTT(ta,lim,1);
        NTT(tb,lim,1);
        for(int i=0;i<lim;++i)
            ta[i]=ta[i]*tb[i]%M;
        NTT(ta,lim,-1);
        copy(ta,ta+lim,c);
    }
    long long tmp[N*4],tans[N*4];
    void Getinv(long long *a,long long *ans,int lim){
        ans[0]=qpow(a[0],M-2);
        for(int i=1;i<lim;i<<=1){
            for(int j=i;j<(i<<2);++j)
                ans[j]=tans[j]=tmp[j]=0;
            for(int j=0;j<(i<<1);++j)
                tmp[j]=a[j];
            for(int j=0;j<i;++j)
                tans[j]=ans[j];
            NTT(tmp,i<<2,1);
            NTT(tans,i<<2,1);
            for(int j=0;j<(i<<2);++j)
                tmp[j]=tmp[j]*tans[j]%M*tans[j]%M;
            NTT(tmp,i<<2,-1);
            for(int j=0;j<(i<<1);++j)
                ans[j]=(2*ans[j]-tmp[j])%M;
        }
    }
    long long tinv[N*4];
    void Getln(long long *a,long long *ans,int n){
        for(int i=0;i<n-1;++i)
            ans[i]=a[i+1]*(i+1)%M;
        Getinv(a,tinv,n);
        mult(ans,n-1,tinv,n,ans);
        for(int i=n;i>=1;--i)
            ans[i]=ans[i-1]*inv[i]%M;
        ans[0]=0;
    }
    long long tln[N*4];
    void Getexp(long long *a,long long *ans,int n){
        ans[0]=1;
        for(int i=1;i<n;i<<=1){
            for(int j=i;j<(i<<1);++j)
                ans[j]=0;
            Getln(ans,tln,i<<1);
            for(int j=0;j<(i<<1);++j)
                tln[j]=-tln[j]+a[j];
            ++tln[0];
            mult(ans,i,tln,i<<1,ans);
        }
    }
    void Getroot(long long *a,long long *ans,int n){
        ans[0]=1;
        for(int i=1;i<n;i<<=1){
            fill(ans+i,ans+(i<<1),0);
            Getinv(ans,tinv,i<<1);
            mult(tinv,i<<1,a,i<<1,tinv);
            for(int j=0;j<(i<<1);++j)
                ans[j]=(ans[j]+tinv[j])*inv[2]%M;
        }
    }
    long long ttln[N*4];
    void Getpow(long long *a,long long *ans,int n,int m){
        Getln(a,ttln,m);
        for(int i=0;i<m;++i)
            ttln[i]=ttln[i]*n%M;
        Getexp(ttln,ans,m);
    }
};
int n,m;
long long f[N*4],g[N*4],h[N*4],hd[N*4],tmp[N*4],eh[N*4],tmp2[N*4],inv[N*4];
void Newton(int lim){
    f[0]=f[1]=0;
    for(int i=2;i<lim;i<<=1){
        poly::Getexp(f,g,i<<1);
        for(int j=(i<<1)-1;j>=1;--j)
            g[j]=g[j-1];
        g[0]=0;
        for(int j=0;j<(i<<1);++j)
            h[j]=(f[j]+g[j])%M;
        poly::Getexp(h,eh,i<<1);
        poly::mult(eh,i<<1,h,i<<1,tmp);
        ++h[0];
        ++g[0];
        poly::mult(g,i<<1,h,i<<1,tmp2);
        poly::mult(tmp2,i<<1,eh,i<<1,tmp2);
        for(int j=(i<<1);j>=1;--j){
            tmp2[j]=-tmp2[j-1];
            tmp[j]=-tmp[j-1];
        }
        tmp2[0]=1;
        for(int j=0;j<(i<<1);++j)
            tmp[j]=(tmp[j]+f[j])%M;
        poly::Getinv(tmp2,inv,i<<1);
        poly::mult(inv,i<<1,tmp,i<<1,h);
        for(int j=0;j<(i<<1);++j)
            f[j]=(f[j]-h[j])%M;
    }
}
long long rt[N*4],X[N*4],Y[N*4],p1[N*4],p2[N*4],p[N*4],e1[N*4],e2[N*4];
long long fd[N*4],gd[N*4],as[N*4],ans[N*4],as2[N*4];
int lim=1;
int main(){
    cin>>n>>M;
    int tmpp=M-1;
    vector<int> dz;
    for(int i=2;i*i<=tmpp;++i)
        while(tmpp%i==0){
            tmpp/=i;
            dz.push_back(i);
        }
    if(tmpp!=1)
        dz.push_back(tmpp);
    for(int i=2;i<M;++i){
        int z=M-1;
        bool fl=true;
        for(auto it:dz)
            if(poly::qpow(i,z/it)==1){
                fl=false;
                break;
            }
        if(fl){
            poly::g=i;
            break;
        }
    }
    poly::init(262144);
    ++n;
    while(lim<=n*2)
        lim<<=1;
    Newton(n+1);
    memset(inv,0,sizeof(inv));
    poly::Getexp(f,g,n+1);
    for(int j=n;j>=1;--j)
        g[j]=g[j-1];
    g[0]=0;
    for(int j=0;j<=n;++j)
        h[j]=(f[j]+g[j])%M;
    poly::Getexp(h,eh,n+1);
    for(int j=1;j<=n;++j)
        tmp[j]=-eh[j-1];
    tmp[0]=1;
    poly::Getln(tmp,as2,n+1);
    for(int j=1;j<=n;++j)
        as2[j]=(as2[j]-f[j])%M;
    poly::mult(eh,n+1,h,n+1,X);
    for(int i=0;i<=n;++i)
        eh[i]=(X[i]+eh[i])%M;
    for(int i=n;i>=1;--i){
        eh[i]=eh[i-1];
        Y[i]=eh[i];
    }
    eh[0]=0;
    poly::mult(eh,n+1,g,n+1,eh);
    for(int i=1;i<=n;++i)
        h[i]=(-eh[i]-Y[i])%M;
    h[0]=1;
    poly::Getln(h,as,n+1);
    for(int i=0;i<=n;++i)
        as[i]=(-as[i]+as2[i])%M;
    poly::Getexp(as,ans,n+1);
    --n;
    for(int i=1;i<=n;++i)
        printf("%lld\n",(ans[i]*poly::fac[i]%M+M)%M);
}