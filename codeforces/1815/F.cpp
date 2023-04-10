#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
vector<pair<int,int> >adj[N];
array<int,3>e[N];
array<int,3>f[N];
ll a[N],b[N];
pair<int,int>vis[10000005];
void solve(){
    cin >> n >> m;
    for(int i=1; i<=n ;i++){
        adj[i].clear();
    }
    for(int i=1; i<=n ;i++){
        cin >> a[i];
    }
    for(int i=1; i<=m ;i++){
        for(int j=0; j<3 ;j++){
        cin >> e[i][j];
        adj[e[i][j]].push_back({i,j});
    }
        f[i][0]=3;
        f[i][1]=1;
        f[i][2]=1;
        a[e[i][0]]+=f[i][0]+f[i][2];
        a[e[i][1]]+=f[i][1]+f[i][0];
        a[e[i][2]]+=f[i][2]+f[i][1];
    }
    for(int i=1; i<=n ;i++){
        for(auto c:adj[i]){
        for(int d=0; d<c.se ;d++){
        vis[a[e[c.fi][d]]]={c.fi,d};
    }
    }
        while(vis[a[i]].fi!=0){
            int ed=vis[a[i]].fi;
            if(i==e[ed][1]){
                a[i]++;
                a[e[ed][2]]++;
                f[ed][1]++;
            }
            else{
                a[i]+=2;

                f[ed][0]--;
                f[ed][1]++;
                f[ed][2]++;
            }
        }

        for(auto c:adj[i]){
        for(int d=0; d<c.se ;d++){
        vis[a[e[c.fi][d]]]={0,0};
    }
    }
    }
    for(int i=1; i<=m ;i++){
        cout << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin >> t;while(t--) solve();
}