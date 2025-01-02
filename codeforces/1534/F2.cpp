// LUOGU_RID: 160031314
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=4e5+10;
int n,m,l[N],r[N],a[N];
char ch[N];
#define id(x,y) ((x-1)*m+y)
inline void dfsl(int x,int y,int k){
    if (~l[id(x,y)]) return;
    l[id(x,y)]=k;
    if (x<n) dfsl(x+1,y,k);
    if (x>1 && ch[id(x-1,y)]=='#') dfsl(x-1,y,k);
    if (y>1 && ch[id(x,y-1)]=='#') dfsl(x,y-1,k);
    if (y<m && ch[id(x,y+1)]=='#') dfsl(x,y+1,k);
}
inline void dfsr(int x,int y,int k){
    if (~r[id(x,y)]) return;
    r[id(x,y)]=k;
    if (x<n) dfsr(x+1,y,k);
    if (x>1 && ch[id(x-1,y)]=='#') dfsr(x-1,y,k);
    if (y>1 && ch[id(x,y-1)]=='#') dfsr(x,y-1,k);
    if (y<m && ch[id(x,y+1)]=='#') dfsr(x,y+1,k);
}
void solve(){
    cin>>n>>m;
    rep(i,1,n){
        string s;cin>>s,s=" "+s;
        rep(j,1,m) ch[id(i,j)]=s[j];
    }
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    rep(j,1,m) rep(i,1,n)
        if (ch[id(i,j)]=='#') dfsl(i,j,j);
    per(j,m,1) rep(i,1,n)
        if (ch[id(i,j)]=='#') dfsr(i,j,j);
    rep(i,1,m) cin>>a[i];
    set< pair<int,int> >s;
    rep(j,1,m)
        if (a[j]){
            per(i,n,1){
                if (ch[id(i,j)]!='#') continue;
                --a[j];
                if (!a[j]){
                    s.insert({r[id(i,j)],l[id(i,j)]});
                    break;
                }
            }
        }
    int ans=0,nw=0;
    while (s.size()){
        auto it=*s.begin();
        s.erase(s.begin());
        if (it.second>nw) ++ans,nw=it.first;
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