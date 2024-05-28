// LUOGU_RID: 159993008
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010;
const int P=1e9+7;
int n,k,fac[N],inv[N];
int f[N][N][4],F[N];
int qpow(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=ans*x%P;
        x=x*x%P; y>>=1;
    }
    return ans;
}
void init(){
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n;i>=1;i--) inv[i-1]=inv[i]*i%P;
}
inline int C(int x,int y){
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
signed main(){
    scanf("%lld%lld",&n,&k);
    init();
    f[1][0][0]=f[1][1][1]=1;
    for(int i=2;i<=n;i++){
        f[i][0][0]=1;
        if(i==n){
            for(int j=1;j<=n;j++){
                f[i][j][0]=(f[i-1][j-1][0]+f[i-1][j][0]+f[i-1][j][2])%P;
                f[i][j][2]=(f[i-1][j-1][1]+f[i-1][j][1]+f[i-1][j][3])%P;
            }
            break;
        }
        for(int j=1;j<=i;j++){      
            f[i][j][0]=(f[i-1][j-1][0]+f[i-1][j][0]+f[i-1][j][2])%P;
            f[i][j][2]=(f[i-1][j-1][1]+f[i-1][j][1]+f[i-1][j][3])%P;
            f[i][j][1]=(f[i-1][j-1][0]+f[i-1][j-1][2])%P;
            f[i][j][3]=(f[i-1][j-1][1]+f[i-1][j-1][3])%P;
        }
    }
    for(int i=0;i<=n;i++) F[i]=(f[n][i][0]+f[n][i][2])%P*fac[n-i]%P;
    int ans=0;
    for(int i=k,fl=1;i<=n;i++,fl=-fl)
        ans=(ans+fl*C(i,k)*F[i]%P+P)%P;
    printf("%lld\n",ans);
    return 0;
}