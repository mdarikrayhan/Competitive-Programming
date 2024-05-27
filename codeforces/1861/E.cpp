// LUOGU_RID: 160443860
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=4005;
const int mod=998244353;
int n,k;
ll jc[N];
ll mi[N];
ll f[N];
ll ans;
int main(){
    cin>>n>>k;
    jc[0]=1;
    mi[0]=1;
    for(int i=1;i<=n;++i){
        jc[i]=jc[i-1]*i%mod;
        mi[i]=mi[i-1]*k%mod;
    }
    for(int i=k;i<=n;++i){
        f[i]=jc[k]*mi[i-k]%mod;
        for(int j=i-k+1;j<i;++j){
            f[i]=(f[i]+mod-f[j]*jc[i-j]%mod)%mod;
        }
        ans=(ans+f[i]*mi[n-i]%mod)%mod;
    }
    cout<<ans;
    return 0;
}