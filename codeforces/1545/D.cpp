// LUOGU_RID: 160596901
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for (int i=j;i<=k;++i)
int const N=1e3+10;
int a[N][N],sm[N],pf[N],n,k,ans;
void solve(){
    cin>>n>>k;
    rep(i,1,k) rep(j,1,n) cin>>a[i][j],sm[i]+=a[i][j],pf[i]+=a[i][j]*a[i][j];
    map<int,int>mp;
    rep(i,1,k-1) ++mp[sm[i+1]-sm[i]];
    rep(i,1,k-1) if (mp[sm[i+1]-sm[i]]==1){ans=i+1;break;}
    int del=0;
    rep(i,1,k-1) if (mp[sm[i+1]-sm[i]]>1){del=sm[i+1]-sm[i];break;}
    int bz=0;
    rep(i,1,k-2)
        if (i!=ans && i+1!=ans && i+2!=ans){bz=pf[i]+pf[i+2]-2*pf[i+1];break;}
    cout<<ans-1<<' ';
    rep(i,1,n){
        int go=del-(sm[ans]-sm[ans-1])+a[ans][i];
        if (pf[ans-1]+pf[ans+1]-2*pf[ans]+2*a[ans][i]*a[ans][i]-2*go*go==bz) return cout<<go<<'\n',void();
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}