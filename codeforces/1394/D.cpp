#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int t[200001],in[200001];
int h[200001],out[200001];
int dp[200001][2];
vector<int> adj[200001];
int st = 0;
int solve(int i,int pr,int taked){
    if(dp[i][taked]!=-1)return dp[i][taked];
    int IN = in[i]+(taked==0&&i!=st) , OUT = out[i]+(taked==1&&i!=st);
    priority_queue<int>q;
    long long cur = 0;
    for(auto j:adj[i]){
        if(j==pr)continue;
        cur+=solve(j,i,0);
        OUT++;
        q.push(solve(j,i,1)-solve(j,i,0));
    }
    long long ans = min(IN,OUT)*t[i]+cur;
    while(!q.empty()){
        int x = q.top();q.pop();
        cur+=x;
        OUT--;IN++;
        ans = max(ans,min(IN,OUT)*t[i]+cur);
    }
    return dp[i][taked] = ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>t[i];
    for(int i = 1;i<=n;i++)cin>>h[i];
    long long all = 0;
    for(int i = 1;i<n;i++){
        int a,b;cin>>a>>b;
        all+=t[a]+t[b];
        if(h[a]>h[b]){
            in[a]++;
            out[b]++;
        }else if(h[a]<h[b]){
            in[b]++;
            out[a]++;
        }else{
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    memset(dp,-1,sizeof dp);
    for(int i = 1;i<=n;i++){
        if(dp[i][0]==-1){
            st = i;
            all-=solve(i,-1,0);
        }
    }
    cout<<all<<endl;
}