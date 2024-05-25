// jai shree ram
#include<bits/stdc++.h> 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define all(a) a.begin(),a.end()
#define int long long
#define el "\n"
#define ll long long
using namespace __gnu_pbds;
 
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define len(s) s.length()
bool isprime(int n){ if(n==1) return false;if(n==2) return true;for(int i=2;i*i<=n;i++){if(n%i==0) return false;}return true;}
//-----------------------------------------------------------------------------------------------------
int mod=998244353;
 ll modexpo(ll number,ll exponent){if(exponent==0) {return 1;}ll x=modexpo(number,exponent/2);if(exponent%2==1){return (((x*x)%mod)*number)%mod;}return (x*x)%mod;}
  ll invfac(ll number){return (modexpo(number,mod-2))%mod;}
int m[1000002];

vector<vector<int>>adj;
vector<int>vis;
int self_loop=0;int vertex=0; int edge=0;
void dfs(int  node){
    if(vis[node]) return ;
    vis[node]=1;
    vertex++;
    for(auto i:adj[node]){
        edge++;
        if(!vis[i]) dfs(i);
        if(i==node) self_loop=1;
    }
}
void chori_ka_laptop(){
   int n; cin>>n;
   vector<int>a(n);
   for(auto &i:a) cin>>i;
    vector<int>b(n);
for(auto &i:b) cin>>i;
    adj.assign(n+1,{});
for(int i=0;i<n;i++){
    adj[a[i]].pb(b[i]);
    adj[b[i]].pb(a[i]);
}

vis.assign(n+1,0);
int ans=1;
for(int i=1;i<=n;i++){
    if(vis[i]) continue;
    vertex=0; self_loop=0;edge=0;
    dfs(i);
    if(2*vertex!=edge) ans=0;
   else if(self_loop==1) ans=(ans*n)%mod;
   else ans=(ans*2)%mod;
}
cout<<ans<<el;
}



signed main(){ 
       ios_base::sync_with_stdio(false);cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input1.txt", "r", stdin);
freopen("D://sublime text//output6.txt", "w", stdout);
freopen("error1.txt","w",stderr);
#endif 
   #ifndef ONLINE_JUDGE
   #endif

int t=1; 
// factorial till 1e6;

cin>>t;
while(t--){ 
    chori_ka_laptop();
cout.flush();}
 
  return 0;       }