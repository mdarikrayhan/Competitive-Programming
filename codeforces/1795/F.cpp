#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> adj[200001];
bool coloured[200001];
int req[200001];
int tobe[200001];
int n,k;

int dfs(int x,int p){
    if(coloured[x]){
        int mini = 0;
        for(int&i:adj[x])if(i!=p){
            auto curr = dfs(i,x);
            if(curr>0)return 1e9;
            mini = min(mini,curr);
        }
        mini*=-1;
        if(req[x]<=mini)return 0;
        return req[x];
    }
    int plus = -1;
    int mini = 0;
    for(int&i:adj[x])if(i!=p){
        auto curr = dfs(i,x);
        if(curr>0){
            if(plus==-1)plus=curr;
            else return 1e9;
        }
        mini = min(mini,curr);
    }
    mini--;
    mini*=-1;
    if(plus==-1){
        return -mini;
    }
    if(plus<=mini)return 0;
    return plus-1;
}

bool check(int x){
    int base = x/k;
    for(int i=1;i<=k;i++)req[tobe[i]]=base;
    for(int i=1;i<=x%k;i++)req[tobe[i]]++;
    return 0>=dfs(1,0);
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<=n;i++)coloured[i]=false;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    cin >> k;
    for(int i=1;i<=k;i++){
        cin>>tobe[i];
        coloured[tobe[i]]=true;
    }
    int ans = 0;
    for(int jump = 131072;jump;jump/=2){
        if(check(ans+jump))ans+=jump;
    }
    cout << ans << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
}