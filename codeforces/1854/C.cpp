// LUOGU_RID: 160486467
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505;
const int mod=1e9+7;
int n,m;
int a[N];
ll f[N][N];
ll ans,ny;
ll ksm(ll x,int y){
    ll an=1;
    while(y){
        if(y&1)an=an*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return an;
}
int main(){
    cin>>n>>m;
    ny=ksm(2,mod-2);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        ans+=m-a[i]+1;
    }
    for(int i=1;i<n;++i){
        f[a[i]][a[i+1]]=1;
    }
    for(int i=1;i<=m;++i){
        ans=(ans+mod-(m-i+1)*f[i][i]%mod)%mod;
        for(int j=i+1;j<=m;++j){
            f[i][j+1]=(f[i][j+1]+ny*f[i][j]%mod)%mod;
            f[i+1][j]=(f[i+1][j]+ny*f[i][j]%mod)%mod;
        }
    }
    cout<<ans;
    return 0;
}