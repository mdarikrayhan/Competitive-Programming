#include<iostream>
#include <iomanip>
#include<math.h>
#include <bits/stdc++.h>
#include<set>
#include<map>
#include<queue>
#include <fstream>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// lower_bound,upperbound swapped for multiset
// change less_equal to equal for set
#define float long double
#define PYes cout<<"Yes\n"
#define PNo cout<<"No\n"
#define PYES cout<<"YES\n"
#define PNO cout<<"NO\n"
#define pq priority_queue
#define int long long
#define endl '\n'
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
#define ff(i,a,b) for(int i=b-1;i>=a;i--)

// pbds
// s.find_by_order()
// s.order_of_key()

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef vector<pair<int,int>> vp;
#define sz(a) int((a).size())
#define pb push_back

#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
const int inf = 1LL<<60;
const int N=1e9;

void dfs(vvi &adj,int s,int par,vi &parent){
    for(int i:adj[s]){
        if(i!=par){
            dfs(adj,i,s,parent);
            parent[i]=s;
        }
    }
    return;
}

void check(int a,int b,int c,vi &v,int &comp,vvi &cost,vi &abcd){
    int fincomp=0;
    int n=v.size();
    vi ans(n);
    f(i,0,n){
        if(i%3==0){ans[v[i]]=a;fincomp+=cost[a][v[i]];}
        if(i%3==1){ans[v[i]]=b;fincomp+=cost[b][v[i]];}
        if(i%3==2){ans[v[i]]=c;fincomp+=cost[c][v[i]];}
    }
    if(fincomp<comp){abcd=ans;comp=fincomp;}
    return;
}

void solve() {
    int n;
    cin>>n;
    vvi c(3,vi(n,0));
    f(i,0,n)cin>>c[0][i];
    f(i,0,n)cin>>c[1][i];
    f(i,0,n)cin>>c[2][i];  
    vvi adj(n);
    f(i,0,n-1){
        int a,b;
        cin>>a>>b;a--,b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }  
    int mx=0;
    f(i,0,n){
        if(mx<=adj[i].size())mx=adj[i].size();
    }
    if(mx>2){cout<<-1<<endl;return;}
    int s=0,t=0;
    int flag=0;
    f(i,0,n){
        if(adj[i].size()==1){if(flag)s=i;else {t=i;flag=1;}}
    }
    // cout<<s<<endl;
    vi v;
    int x=t;
    vi parent(n,0);
    dfs(adj,s,-1,parent); 
    // f(i,0,n)cout<<parent[i]<<" ";cout<<endl;
    while(x!=s){
        v.pb(x);
        x=parent[x];
    }
    v.pb(s);
    // for(int i :v)cout<<i<<" ";
    // cout<<endl;
    vi ans(n);
    int comp=inf;
    check(0,1,2,v,comp,c,ans);
    check(0,2,1,v,comp,c,ans);
    check(1,0,2,v,comp,c,ans);
    check(1,2,0,v,comp,c,ans);
    check(2,0,1,v,comp,c,ans);
    check(2,1,0,v,comp,c,ans);
    cout<<comp<<endl;
    for(int i:ans)cout<<i+1<<" ";
    cout<<endl;
    return;
}








int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
// 	cin >> t;
t=1;
    while (t--) {
        solve();
    }
    return 0;
}