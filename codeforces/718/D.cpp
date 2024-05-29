// LUOGU_RID: 159944389
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define pb push_back
#define ull unsigned long long
void in(int &x){
    int f=1;x=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-')c=getchar();
    if(c=='-')f=-1,c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    x*=f;
}
mt19937_64 rnd(time(0));
int t,n,m,k,x,y,d[1000005],ans;
ull base,f[1000005],h[1000005];
vector<int>g[1000005];
ull F(ull x){
    return x*x*x*1504509+19260817;
}
ull H(ull x){
    return F(x&((1ll<<32)-1))+F(x>>32);
}
void dfs(int k,int fa){
    f[k]=base;
    for(int v:g[k]){
        if(v==fa)continue;
        dfs(v,k);f[k]+=H(f[v]);
    }
}
void solve(int k,int fa,ull hsh){
    if(fa)h[k]=f[k]+H(hsh);
    else h[k]=f[k];
    for(int v:g[k]){
        if(v==fa)continue;
        solve(v,k,h[k]-H(f[v]));
    }
}
map<ull,int>p;
signed main(){
    in(n);base=rnd()*2+1;
    for(int i=1;i<n;i++){
        in(x);in(y);
        d[x]++;d[y]++;
        g[x].pb(y);g[y].pb(x);
    }
    dfs(1,0);solve(1,0,0);
    for(int i=1;i<=n;i++)if(d[i]!=4){if(!p[h[i]])p[h[i]]=1,ans++;}
    printf("%d\n",ans);
}