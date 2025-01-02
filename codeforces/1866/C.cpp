#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;
const int MAXN = 1e5+100;

vector<pair<int,int>> G[MAXN];
vector<ll> inv(MAXN), ceros(MAXN), unos(MAXN), vis(MAXN);

void dfs(int v){
    vis[v]=1;
    for(auto u:G[v]) if(!vis[u.first]) dfs(u.first);
    for(auto u:G[v]) unos[v]+=unos[u.first]+(u.second==1), unos[v]%=mod;
    for(auto u:G[v]) ceros[v]+=ceros[u.first]+(u.second==0), ceros[v]%=mod;
    ll act1=0;
    for(auto u:G[v]){
        if(u.second==0) inv[v]=(inv[v]+act1)%mod;
        else act1=(act1+1)%mod;
        inv[v]+=inv[u.first]; inv[v]%=mod;
        inv[v]+=(act1*ceros[u.first])%mod; inv[v]%=mod;
        act1+=unos[u.first]; act1%=mod;
    }
    //cout<<"en "<<v<<" tengo "<<unos[v]<<" "<<ceros[v]<<" "<<inv[v]<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int s; cin>>s;
        while(s--){
            int a,b; cin>>a>>b;
            G[i].push_back({a,b});
        }
    }
    
    dfs(1);
    cout<<inv[1];

    return 0;
}

