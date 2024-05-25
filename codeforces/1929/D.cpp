#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const double er = 1e-9;
const int INF = INT64_MAX;
const int INFm = INT64_MIN;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pi;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int32_t i = a; i < b; i++)
#define FORd(i,init,finl) for(int32_t i = init ; i>=finl ; i--)
#define trav(elem,DS) for (auto elem : DS)


void traverse(int node, int par, vector<int>& dp, int& ans, vvi& adjlist){
    trav(x,adjlist[node]){
        if(x!=par){
            traverse(x,node,dp,ans,adjlist);
        }
    }
    int temp=1;
    trav(x,adjlist[node]){
        if(x!=par){
            temp = (temp * (dp[x]+1))%MOD;
            ans = (ans + dp[x])%MOD;
        }
    }
    dp[node]=temp;
}



void solve(int ind1){
    int n;
    cin>>n;
    vvi adjlist(n+1);
    for(int i = 0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    vector<int> dp(n+1,0);
    int ans = 0;
    traverse(1,0,dp,ans,adjlist);
    cout<<(ans+1+dp[1])%MOD<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t; // comment if there's only one test case
    for (int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}