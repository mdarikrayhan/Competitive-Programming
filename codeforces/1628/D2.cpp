// LUOGU_RID: 160176167
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+5,mod=1e9+7;
int qpow(int a,int t)
{
    int res=1;
    while (t)
    {
        if (t&1)  res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        t>>=1;
    }
    return res;
}
int fac[N],inv[N];
void init(int n)
{
    fac[0]=1;
    for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=qpow(fac[n],mod-2);
    for (int i=n;i>=1;i--) inv[i-1]=1ll*inv[i]*i%mod;
}
int C(int n,int m)
{
    if (n<m) return 0;
    return 1ll*fac[n]*inv[n-m]%mod*inv[m]%mod;
}
void solve()
{
    int n,m,ans=0,inv2=qpow(2,mod-2);
    LL k;
    cin>>n>>m>>k;
    if (n==m) ans=n;
    else if (m==0) ans=0;
    else 
        for (int i=1;i<=m;i++) ans=(ans+1ll*i*C(n-i-1,m-i)%mod*qpow(inv2,n-i)%mod)%mod;
    cout<<1ll*ans*k%mod<<'\n';
}

int main()
{
    init(1e6);
    int T=1;
    cin>>T;
    while (T--) solve();
    return 0;
}