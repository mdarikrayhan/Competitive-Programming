// LUOGU_RID: 160083980
#include <bits/stdc++.h>
using namespace std;
namespace Le0{
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5+5;
int T,n,m,k;
int bel[N];
bool ok;
vector<pii> g[N];
void add(int x,int y,int w){
    // cout<<x<<" "<<y<<" "<<w<<"\n";
    g[x].push_back({y,w});
    g[y].push_back({x,w});
}
void dfs(int x,int col){
    bel[x]=col;
    for(auto z:g[x]){
        int y=z.fi,op=z.se;
        if(!bel[y]){
            if(op==1) dfs(y,col);
            else dfs(y,3-col);
        }
        else{
            int tol=(op==1?col:3-col);
            if(bel[y]!=tol){ok=0;return;}
        }
        if(!ok) return;
    }
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;ok=1;
        for(int i=1;i<=n+m;i++) g[i].clear();
        for(int i=1,x1,x2,y1,y2;i<=k;i++){
            cin>>x1>>y1>>x2>>y2;
            if(y2==y1+1) add(n+y2,x2,2);
            else add(n+y1,x2,1);
        }
        for(int i=1;i<=n+m;i++) bel[i]=0;
        for(int i=2;i<=n+m;i++){
            if(!bel[i]) dfs(i,1);
            if(!ok){
                cout<<"NO\n";
                break;
            }
        }
        if(ok) cout<<"YES\n";
    }
    return 0;
}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    return Le0::main();
}