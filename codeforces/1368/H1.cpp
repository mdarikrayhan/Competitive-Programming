// LUOGU_RID: 158404084
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=j;i<=k;++i)
int const N=1e5+10;
int n,m,q,dp[N][2];string s1,s2,s3,s4;
inline int work(int n,int m,string a,string b,string c,string d){
    a=" "+a,b=" "+b,c=" "+c,d=" "+d;
    int up=0,dw=0;
    rep(i,1,n) up+=a[i]=='R',dw+=b[i]=='R';
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=up,dp[0][1]=n-up;
    rep(i,1,m){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1]+n)+(c[i]=='R')+(d[i]=='R');
        dp[i][1]=min(dp[i-1][1],dp[i-1][0]+n)+(c[i]=='B')+(d[i]=='B');
    }
    dp[m][0]+=dw,dp[m][1]+=n-dw;
    return min(dp[m][0],dp[m][1]);
}
void solve(){
    cin>>n>>m>>q>>s1>>s2>>s3>>s4;
    cout<<min(work(n,m,s1,s2,s3,s4),work(m,n,s3,s4,s1,s2))<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}