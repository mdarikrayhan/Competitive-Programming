// LUOGU_RID: 160438267
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=255;
int const M=1<<16;
int const mod=1e9+7;
int n,m,t,fa[N],dp[N][M],g[M],eg[N][5];
string s;char ch[N];
vector<int>e[N];
inline void And(int a[],int len,int tp){
    for (int L=2,t=1;L<=len;L<<=1,t<<=1)
        for (int i=0;i<len;i+=L) rep(j,0,t-1)
            a[i+j]+=a[i+j+t]*tp%mod,a[i+j]%=mod;
}
inline void Or(int a[],int len,int tp){
    for (int L=2,t=1;L<=len;L<<=1,t<<=1)
        for (int i=0;i<len;i+=L) rep(j,0,t-1)
            a[i+j+t]+=a[i+j]*tp%mod,a[i+j+t]%=mod;
}
inline void AND(int x){
    And(dp[e[x][0]],(1<<m),1),And(dp[e[x][1]],(1<<m),1);
    rep(S,0,(1<<m)-1) g[S]=dp[e[x][0]][S]*dp[e[x][1]][S]%mod;
    And(g,(1<<m),mod-1),And(dp[e[x][0]],(1<<m),mod-1),And(dp[e[x][1]],(1<<m),mod-1);
    rep(S,0,(1<<m)-1) dp[x][S]+=g[S],dp[x][S]%=mod;
}
inline void OR(int x){
    Or(dp[e[x][0]],(1<<m),1),Or(dp[e[x][1]],(1<<m),1);
    rep(S,0,(1<<m)-1) g[S]=dp[e[x][0]][S]*dp[e[x][1]][S]%mod;
    Or(g,(1<<m),mod-1);
    rep(S,0,(1<<m)-1) dp[x][S]+=g[S],dp[x][S]%=mod;
}
inline void dfs(int x){
    if (!e[x].size()){
        rep(i,0,3){
            if (ch[x]!='?' && ch[x]!=(char)(i+'A')) continue;
            int S=0;
            rep(j,0,m-1) S|=eg[j][i]<<j;
            ++dp[x][S];
        }
        rep(i,0,3){
            if (ch[x]!='?' && ch[x]!=(char)(i+'a')) continue;
            int S=0;
            rep(j,0,m-1) S|=(1-eg[j][i])<<j;
            ++dp[x][S];
        }
        return;
    }
    dfs(e[x][0]),dfs(e[x][1]);
    if (ch[x]!='|') AND(x);
    if (ch[x]!='&') OR(x);
}
void solve(){
    cin>>s,n=s.size(),s=" "+s;
    int la=0;
    rep(i,1,n)
        if (s[i]=='(') ++t,e[la].push_back(t),fa[t]=la,la=t;
        else if (s[i]==')') la=fa[la];
        else ch[la]=s[i];
    cin>>m;
    int st=0;
    rep(i,0,m-1){
        rep(j,0,4) cin>>eg[i][j];
        st|=eg[i][4]<<i;
    }
    dfs(0);
    cout<<dp[0][st]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}