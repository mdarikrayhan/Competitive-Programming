#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e9;
const int maxn=1e5+5;
int dp[maxn],freq[maxn];
bool vis[maxn];
bool check[maxn];
vector<int> adj[maxn];
int comp_size=0;
void dfs(int u){
    vis[u]=1;
    comp_size++;
    for(auto x:adj[u]){
        if(vis[x])  continue;
        dfs(x);
    }
}
void solve(){
    int n,m;    cin>>n>>m;
    for(int i=1;i<=n;i++){
        dp[i]=inf;
        int curr=i,flag=1;
        while(curr>0){
            if((curr%10)!=4 && (curr%10)!=7)    flag=0;
            curr=curr/10;
        }
        check[i]=flag;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;    v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            comp_size=0;
            dfs(i);
            freq[comp_size]++;
        }
    }
    // vector<pair<int,int>> vv;
    for(int i=1;i<=n;i++){
        for(int x=1;x<=freq[i];x<<=1){
            for(int j=n-x*i;j>=0;j--){
                dp[j+x*i]=min(dp[j+x*i],dp[j]+x);
            }
            freq[i]-=x;
        }
        if(freq[i]>0){
            for(int j=n-freq[i]*i;j>=0;j--){
                dp[j+freq[i]*i]=min(dp[j+freq[i]*i],dp[j]+freq[i]);
            }
        }
    }
    // sort(vv.begin(),vv.end());
    // for(auto [ele,times]:vv){
    //     for(int i=n-ele;i>=0;i--){
    //         dp[i+ele]=min(dp[i+ele],dp[i]+times);
    //     }
    // }
    int res=inf;
    for(int i=1;i<=n;i++){
        if(check[i]){
            res=min(res,dp[i]);
        }
    }
    cout<<(res==inf ? -1 : res-1)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}