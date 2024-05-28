// LUOGU_RID: 158247303
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=j;i<=k;++i)
int const N=1e6+10;
int B,num,a[N];
inline void clear(){cout<<"R"<<endl;}
inline char query(int id){cout<<"? "<<id<<endl;char rk;cin>>rk;return rk;}
inline void Query(int id){int L=(id-1)*B+1,R=id*B;rep(i,L,R){if (!a[i]) continue;if (query(i)=='Y') a[i]=0;}}
void solve(){
    int n,k;cin>>n>>k,B=(k+1)/2,num=n/B;
    rep(i,1,n) a[i]=1;
    if (num==1) Query(1);
    rep(d,1,num-1) for (int i=1;i<=d && i+d<=num;++i){
        clear();
        for (int j=i;j<=num;j+=d) Query(j);
    }
    int ans=0;
    rep(i,1,n) ans+=a[i];
    cout<<"! "<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}