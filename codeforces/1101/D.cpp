#include<bits/stdc++.h>
#include <cmath>
#include <complex>
#include<string>
//#include "testlib.h"
//freopen("orxor.in", "r", stdin);
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define dcm(a) setprecision(a)<<fixed
ll const md=1e9+7;
double const EPS=1e-9;
int const LOG=22;
using uint = unsigned int;
using ull = unsigned long long;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define clr(memo, a) memset(memo,a,sizeof(memo))
#define PI acos(-1)
#define endl '\n'
void solve(int testCase)
{
  int n;
  cin>>n;
  vector<int> a(n+1);
  int ans=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]>1)
        ans=1;
    }
  vector<vector<int> > adj(n+1);
  vector<vector<pair<int,int> >  >edges(2e5+5);
  vector<bool> visprm(2e5+5);
    vector<int> vis(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edges[__gcd(a[x],a[y])].push_back({x,y});
    }
    auto bfs=[&](int st,int ch)->pair<int,int>{
        queue<pair<int,int> > q;
        q.push({st,0});
        vis[st]=ch;
        int mx=0;
        int idx=st;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int v=x.first;
            int t=x.second;
            if(t>mx){
                mx=t;
                idx=v;
            }
            for(int u:adj[v]){
                if(vis[u]==ch)
                    continue;
                q.push({u,t+1});
                vis[u]=ch;
            }
        }
        return {idx,mx};
    };
    auto diamiter=[&](int st)->int{
        auto p=bfs(st,2);
        auto p2=bfs(p.first,3);
        return p2.second;
    };
    for(int i=2;i<2e5+5;i++){
        if(visprm[i])
            continue;
        vector<int> vertx;
        for(int j=i;j<2e5;j+=i){
            visprm[j]=1;
            for(auto p:edges[j]){
                int x=p.first;
                int y=p.second;
                if(!vis[x]){
                    vertx.push_back(x);
                    vis[x]=1;
                }
                if(!vis[y]){
                    vertx.push_back(y);
                    vis[y]=1;
                }
                adj[x].push_back(y);
                adj[y].push_back(x);
                //cout<<j<<" "<<x<<" "<<y<<endl;
            }
        }

        for(int v:vertx){
            if(vis[v]==3)
                continue;
            ans=max(ans,diamiter(v)+1);
        }
        for(int v:vertx)
            adj[v].clear();
        for(int v:vertx)
            vis[v]=0;
    }
    cout<<ans<<endl;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testCase=1;
   // cin>>testCase;
    for(int i=1; i<=testCase; i++)
        solve(i);


    return 0;
}
