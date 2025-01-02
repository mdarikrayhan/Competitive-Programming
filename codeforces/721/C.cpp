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
  int n,m,t;
  cin>>n>>m>>t;
  vector<vector<int > > parent(n+1,vector<int > (n+1));
  vector<vector<int> >  tm(n+1,vector<int>(n+1,t+2));
  queue<pair<int,int> > q;
  vector<vector<pair<int,int> > >adj(n+1);

  for(int i=0;i<m;i++){
    int x,y,w;
    cin>>x>>y>>w;
    adj[x].push_back({y,w});
  }
  tm[1][0]=0;
    q.push({1,0});

    while(!q.empty()){
        auto x=q.front();
        q.pop();
        int v=x.first;
        int j=x.second;
        for(auto y:adj[v]){
            int u=y.first;
            int w=y.second;
            if(tm[v][j]+w<=t){
                if(tm[v][j]+w<tm[u][j+1]){
                    tm[u][j+1]=tm[v][j]+w;
                    parent[u][j+1]=v;
                    q.push({u,j+1});

                }
            }
        }
       // vis[v][j]=false;
    }
    vector<int> ans;
    int cnt=0;
    for(int i=0;i<=n;i++){
        if(tm[n][i]<=t)
            cnt=i;
    }
    int v=n;
    for(int i=cnt;i>=0;i--){
        ans.push_back(v);
        v=parent[v][i];
    }
    reverse(ans.begin(),ans.end());
    cout<<(int)ans.size()<<endl;
    for(int x:ans)
        cout<<x<<" ";
    cout<<endl;
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
