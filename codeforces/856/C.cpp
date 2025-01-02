// LUOGU_RID: 158667177
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pii pair<ll,ll>
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)
using namespace std;
bool Mbe;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const ll N=3009,Mod=998244353;
ll T,n,a[N],cnt[2],bin[2][11],dp[2][N][11],ans;
ll fac[N],ifac[N];
ll pw(ll x,ll p){
    ll res=1;
    while(p){
        if(p&1)res=res*x%Mod;
        x=x*x%Mod;
        p>>=1;
    }
    return res;
}
ll calc(ll x,ll y){
    if(x==0)return (y==0);
    return fac[x+y-1]*ifac[y]%Mod*ifac[x-1]%Mod;
}
void solve(){
    n=read();
    rep(i,1,n)a[i]=read();
    memset(cnt,0,sizeof(cnt));
    memset(bin,0,sizeof(bin));
    rep(i,0,n){
        rep(j,0,10)dp[0][i][j]=dp[1][i][j]=(i+j==0);
    }
    ans=0;
    ll pd=0;
    rep(i,1,n){
        ll md=a[i]%11,len=0;
        while(a[i])len^=1,a[i]/=10;
        bin[len][md]++;
        pd+=md;
        cnt[len]++;
        per(j,cnt[len],0){
            rep(k,0,10)dp[len][j+1][(k+md)%11]=(dp[len][j+1][(k+md)%11]+dp[len][j][k])%Mod;
        }
    }
    pd=pd*6%11;
    rep(c1,0,cnt[0]){
        rep(i,0,10){
            ll md=(pd-i+11)%11;
            // cout<<dp[0][c1][md]<<" "<<dp[1][(cnt[1]+1)/2][i]<<endl;
            ans=(ans+dp[0][c1][md]*fac[c1]%Mod*fac[cnt[0]-c1]%Mod*dp[1][(cnt[1]+1)/2][i]%Mod*fac[cnt[1]/2]%Mod*fac[(cnt[1]+1)/2]%Mod*calc(cnt[1]/2+1,c1)%Mod*calc((cnt[1]+1)/2,cnt[0]-c1))%Mod;
        }
    }
    write(ans),putchar('\n');
}
bool Med;
int main(){
    cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
    T=read();
    n=2000;
    fac[0]=1;
    rep(i,1,n)fac[i]=fac[i-1]*i%Mod;
    ifac[n]=pw(fac[n],Mod-2);
    per(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%Mod;
    while(T--)solve();
    return 0;
}