// LUOGU_RID: 159797946
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int n;
char s[(1<<20)+5];
ll a[1<<20];
ll power(ll a,ll p){
    ll res=1;
    while(p){
        if(p&1)res=res*a%mod;
        p>>=1;
        a=a*a%mod;
    }
    return res;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<1<<n;i++)a[i]=s[i]^'0';
    for(int j=0;j<n;j++)for(int i=0;i<1<<n;i++)if(i>>j&1){
        ll x=a[i^1<<j],y=a[i];
        a[i^1<<j]=(x+y)%mod,a[i]=(x-y+mod)%mod;
    }
    for(int i=0;i<1<<n;i++)a[i]=a[i]*a[i]%mod;
    for(int j=0;j<n;j++)for(int i=0;i<1<<n;i++)if(i>>j&1){
        ll x=a[i^1<<j],y=a[i];
        a[i^1<<j]=(x+y)%mod,a[i]=(x-y+mod)%mod;
    }
    ll ans=0;
    for(int i=0;i<1<<n;i++)ans=(ans+(1<<n-__builtin_popcount(i))*a[i]%mod)%mod;
    printf("%lld\n",ans*3%mod*power(1<<n,mod-2)%mod);
    return 0;
}