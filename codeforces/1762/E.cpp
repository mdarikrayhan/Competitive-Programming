// LUOGU_RID: 160413238
#include <bits/stdc++.h>
using namespace std;
namespace Le0{
const int N=5e5+5,mod=998244353;
int n,as;
int fac[N],ifac[N];
int qp(int a,int b){
    int as=1;
    while(b){
        if(b&1) as=1ll*as*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }return as;
}
int cal(int x){
    if(x==1) return 1;
    return qp(x,x-2);
}
void init(int up){
    fac[0]=ifac[0]=1;
    for(int i=1;i<=up;i++) fac[i]=1ll*fac[i-1]*i%mod;
    ifac[up]=qp(fac[up],mod-2);
    for(int i=up-1;i>=1;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
int C(int x,int y){
    if(x<0||y<0||x<y) return 0;
    return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
    cin>>n;
    if(n&1) {cout<<"0\n";return 0;}
    init(n+2);
    for(int i=1;i<=n-1;i++){
        int res=1ll*C(n-2,i-1)*cal(i)%mod*cal(n-i)%mod*i%mod*(n-i)%mod;
        if(i&1) as+=mod-res;
        else as+=res;
        as%=mod;
    }
    cout<<as<<"\n";
    return 0;
}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    return Le0::main();
}