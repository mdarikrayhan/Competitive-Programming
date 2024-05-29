// LUOGU_RID: 158547899
#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e3+5,maxn=4e5+5;
int ch[N][14],fa[N],tot,rt;
long long cnt[N],dp[2][N][1<<14],num[N];
string s;inline void insert(){
    cin>>s;int p=rt;
    for(auto x:s){
        auto&w=ch[p][x-'a'];
        if(!w) w=++tot;
        p=w;
    }int w;cin>>w;
    cnt[p]+=w;
}
int to[N];
inline void chkmax(long long&x,long long y){(x<y)&&(x=y);}
int main(){
    tot=rt=1;int k;cin>>k;while(k--)insert();
    for(int i=0;i<14;i++) ch[0][i]=1;
    queue<int> q;q.push(1);
    while(!q.empty()){
        int p=q.front();q.pop();
        int F=fa[p];cnt[p]+=cnt[F];
        for(int i=0;i<14;i++){
            auto&w=ch[p][i];
            if(!w) w=ch[F][i];
            else fa[w]=ch[F][i],q.push(w);
        }
    }
    memset(dp,-0x3f,sizeof dp);
    dp[0][1][0]=0;cin>>s;
    int n=s.length(),p=0,qq=1;
    for(int i=1;i<=tot;i++) to[i]=i;
    int cntt=0;
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='?'){
            memset(dp[qq],-0x3f,sizeof dp[qq]);
            for(int j=1;j<=tot;j++)
            for(int i=0;i<1<<14;i++)if(__builtin_popcount(i)==cntt)
            for(int k=0;k<14;k++)if(!(i>>k&1))chkmax(dp[qq][ch[to[j]][k]][i|1<<k],dp[p][j][i]+num[j]+cnt[ch[to[j]][k]]);
            for(int i=1;i<=tot;i++) to[i]=i,num[i]=0;
            swap(p,qq);cntt++;
        }
        else for(int i=1;i<=tot;i++) to[i]=ch[to[i]][c-'a'],num[i]+=cnt[to[i]];
    }
    long long ans=-1e18;
    for(int j=1;j<=tot;j++)
    for(int i=0;i<1<<14;i++) chkmax(ans,dp[p][j][i]+num[j]);
    cout<<ans<<'\n';
    return 0;
}