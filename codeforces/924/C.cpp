// LUOGU_RID: 159973770
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+50,M=2e6+30;
ll n,a[N],b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        b[i]=max(b[i-1],a[i]+1);
    }
    for(int i=n-1;i;--i){
        if(b[i+1]-b[i]>1){
            for(int j=i,k=1;b[i+1]-k!=b[j] and j>0;--j,++k){
                b[j]=b[i+1]-k;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        ans+=b[i]-(a[i]+1);
    }
    cout<<ans<<"\n";
    return 0;
}