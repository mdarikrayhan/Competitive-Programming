// LUOGU_RID: 160085441
#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<string>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+10;
const int N=1e5;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
long long n;
int m;
bool bit[64];
int f[64][4],g[64][4];
unsigned int ans;
inline void solve(){
    scanf("%lld%d",&n,&m);
    if(m==1){
        printf("%lld\n",n%mod);
        return ;
    }
    if(m>2){
        if(n&1){
            printf("%lld\n",(((n+1ll)>>1)%mod)*(((n+1ll)>>1)%mod)%mod);
        }
        else{
            printf("%lld\n",(((n+2)>>1)%mod)*((n>>1)%mod)%mod);
        }
        return ;
    }
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    for(int i=60;i;i--)
    {
        bit[i]=n&1;
        n>>=1;
    }
    g[0][0]=1;
    for(int i=1;i<=60;i++)
    {
        g[i][bit[i]]=g[i-1][0]+g[i-1][1];
        (g[i][bit[i]]>=mod)&&(g[i][bit[i]]-=mod);
        g[i][bit[i]]+=g[i-1][2];
        (g[i][bit[i]]>=mod)&&(g[i][bit[i]]-=mod);
        g[i][bit[i]+2]=g[i-1][1]+g[i-1][2];
        (g[i][bit[i]+2]>=mod)&&(g[i][bit[i]+2]-=mod);
        g[i][bit[i]+2]+=g[i-1][3];
        (g[i][bit[i]+2]>=mod)&&(g[i][bit[i]+2]-=mod);
    }
    for(int i=1;i<=60;i++)
    {
        f[i][bit[i]]=((((long long)f[i-1][0]+f[i-1][1]+f[i-1][2])<<1)+1ll*g[i][bit[i]]*bit[i])%mod;
        (f[i][bit[i]]<0)&&(f[i][bit[i]]+=mod);
        f[i][bit[i]+2]=((((long long)f[i-1][1]-g[i-1][1]+f[i-1][2]+g[i-1][2]+f[i-1][3]-g[i-1][3])<<1)+1ll*g[i][bit[i]+2]*bit[i])%mod;
        (f[i][bit[i]+2]<0)&&(f[i][bit[i]+2]+=mod);
    }
    ans=f[60][0]+f[60][1]+f[60][2];
    (ans>=mod)&&(ans-=mod);
    (ans>=mod)&&(ans-=mod);
    printf("%u\n",ans);
}
signed main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}