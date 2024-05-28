// LUOGU_RID: 159661981
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=3e3+10;
int r,c,n,k,all,ins[N][N],tong[N],nxt[N],pre[N],x[N],y[N];
vector< pair<int,int> >p[N];
//ins[x][y] -> 当枚举的 i 为 x 时，y 应该添加到哪个数后面
inline void color(int ix,int id,int idy){
    ++tong[id];
    if (tong[id]==1){
        int kg=ins[idy][ix];
        nxt[id]=nxt[kg],nxt[kg]=id,pre[id]=kg;
        if (nxt[id]) pre[nxt[id]]=id;
    }
    int lf=id,rg=id,sm=tong[id];
    while (pre[lf] && sm+tong[pre[lf]]<=k) lf=pre[lf],sm+=tong[lf];
    while (1){
        while (nxt[rg] && sm+tong[nxt[rg]]<=k) rg=nxt[rg],sm+=tong[rg];
        if (sm==k) all+=(lf-pre[lf])*((nxt[rg]?nxt[rg]:(r+1))-rg);
        if (lf==id) break;
        sm-=tong[lf],lf=nxt[lf];
    }
}
void solve(){
    cin>>r>>c>>n>>k;
    rep(i,1,n) cin>>x[i]>>y[i],p[y[i]].push_back({x[i],i});
    rep(i,1,n){
        rep(j,1,n){
            if (i==j) continue;
            if (y[j]>y[i]) continue;
            if (x[j]>x[i]) continue;
            if (x[j]==x[i] && y[j]==y[i] && j>i) continue;
            ins[i][y[j]]=max(ins[i][y[j]],x[j]);
        }
        per(j,c,1) ins[i][j]=max(ins[i][j],ins[i][j+1]);
    }
    rep(i,1,c) sort(all(p[i]));
    int ans=0;
    rep(i,1,c){
        all=0;
        memset(tong,0,sizeof(tong));
        memset(pre,0,sizeof(pre));
        memset(nxt,0,sizeof(nxt));
        rep(j,i,c){
            for (auto it:p[j]) color(i,it.first,it.second);
            ans+=all;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}