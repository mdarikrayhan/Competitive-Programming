#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
vector<int> fa;
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void solve() {
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    vector<map<int,int>> ve(n+1); 
    map<pair<int,int>,int> mp;
    fa.resize(n+1);
    for(int i=1;i<=n;i++)   fa[i]=i;
    auto op=[&](int u,int v,int w){
        if(mp.find({v,w})!=mp.end()){
            int u1=get(u),v1=get(mp[{v,w}]);
            if(u1==v1);
            else{
                if(ve[u1].size()>ve[v1].size()) swap(u1,v1);
                for(auto [x,y]:ve[u1]){
                    ve[v1][x]=1;
                }
                fa[u1]=v1;
                //cout<<u1<<' '<<v1<<'\n';
            }
        }
        else mp[{v,w}]=u;
    };
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        op(u,v,w);
        swap(u,v);
        op(u,v,w);
        ve[get(u)][v]=1;
        ve[get(v)][u]=1;
    }
    for(int i=1;i<=q;i++){
        char c;
        cin>>c;
        if(c=='+'){
            int u,v,w;
            cin>>u>>v>>w;
            op(u,v,w);
            swap(u,v);
            op(u,v,w);
            ve[get(u)][v]=1;
            ve[get(v)][u]=1;
        }
        else{
            int u,v;
            cin>>u>>v;
            if(get(u)==get(v))  cout<<"Yes\n";
            else if(ve[get(u)].find(v)!=ve[get(u)].end())   cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}
 	 	  	  	 		     	  	  		  	