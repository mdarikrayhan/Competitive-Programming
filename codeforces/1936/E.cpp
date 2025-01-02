// LUOGU_RID: 160595554
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,P=998244353;
int qpow(int a,int b=P-2){
    int c=1;
    for(;b;b>>=1,a=1ll*a*a%P)
        if(b&1)c=1ll*c*a%P;
    return c;
}
typedef vector<int> poly;
int rev[N<<2],_G=3,invG=(P+1)/3;
void NTT(poly&f,int op){
    int n=f.size();for(int i=0;i<n;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
    for(int p=2;p<=n;p<<=1){
        int len=p>>1,tG=qpow(op==1?_G:invG,(P-1)/p);
        for(int k=0;k<n;k+=p){
            int buf=1;
            for(int l=k;l<k+len;l++){
                int tmp=1ll*buf*f[l+len]%P;
                f[l+len]=(f[l]-tmp+P)%P;f[l]=(f[l]+tmp)%P;
                buf=1ll*buf*tG%P;
            }
        }
    }
    if(op==-1){
        int inv=qpow(n);
        for(int i=0;i<n;i++)f[i]=1ll*f[i]*inv%P;
    }
}
poly times(poly f,poly g){
    int n=f.size(),m=g.size();
    for(m+=n,n=1;n<=m;n<<=1);f.resize(n);g.resize(n);
    for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);
    NTT(f,1);NTT(g,1);for(int i=0;i<n;i++)f[i]=1ll*f[i]*g[i]%P;
    NTT(f,-1);return f;
}
poly f,g;
int fac[N],inv[N],ifac[N];
int T,n,a[N],dp[N],lst[N],s[N];
void init(int n){
    inv[1]=fac[0]=ifac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%P;
    for(int i=2;i<=n;i++)inv[i]=1ll*(P-P/i)*inv[P%i]%P;
    for(int i=1;i<=n;i++)ifac[i]=1ll*ifac[i-1]*inv[i]%P;
}
void solve(int l,int r){
    if(l==r){
        dp[l]=(dp[l]-1ll*(s[l-1]-s[lst[l]-1]+P)*ifac[a[l]-l-1]%P+P)%P;
        s[l]=(s[l-1]+1ll*dp[l]*fac[a[l]-l-1]%P)%P;return;
    }
    int mid=(l+r)>>1;solve(l,mid);
    int mf=a[mid+1]-mid-1,mg=l,lenf=(a[r]-l)-(a[mid+1]-mid-1)+1,leng=mid-l+1;
    f.resize(lenf);for(int i=0;i<lenf;i++)f[i]=fac[i+mf];
    g.resize(leng);for(int i=0;i<leng;i++)g[i]=dp[i+mg];f=times(f,g);
    for(int i=mid+1;i<=r;i++)
        dp[i]=(dp[i]-1ll*f[a[i]-mf-mg]*ifac[a[i]-i]%P+P)%P,
        dp[i]=(dp[i]+1ll*f[a[i]-1-mf-mg]*ifac[a[i]-1-i]%P)%P;
    solve(mid+1,r);
}
int main(){
    init(N-1);scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]=max(a[i],a[i-1]);
        for(int i=1;i<=n;i++)lst[i]=(a[i]!=a[i-1]?i:lst[i-1]);
        for(int i=1;i<=n;i++)dp[i]=1ll*i*fac[a[i]-1]%P*ifac[a[i]-i]%P;
        solve(1,n);printf("%d\n",dp[n]);
    }
    return 0;
}