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


void dfs(int s,int p ,vvi &adj,vi &c ){
    for(int i:adj[s]){
        if(i!=p){
            // int s=0;
            dfs(i,s,adj,c);
            c[s]+=c[i];            
        }
    }
    return;
}


void solve() {
    int n;
    cin>>n;
    vvi adj(n);
    vi w(n-1);
    vp v;
    f(i,0,n-1){
        int a,b;
        cin>>a>>b>>w[i];a--,b--;
        v.pb(make_pair(a,b));
        adj[a].pb(b);
        adj[b].pb(a);    
    }    
    vi c(n,1);
    dfs(0,-1,adj,c);
    // f(i,0,n)cout<<c[i]<<" ";
    // cout<<endl;
    vi ans(n-1);
    f(i,0,n-1){
        int p=min(c[(v[i].first)],c[(v[i].second)]);
        ans[i]=p*(n-p);
    }
    int finalans=0;
    f(i,0,n-1)finalans+=ans[i]*w[i];
    int q;
    cin>>q;
    f(i,0,q){
        int a,b;
        cin>>a>>b;
        finalans-=(ans[a-1])*(w[a-1]-b);
        w[a-1]=b;
        cout<<fixed<<setprecision(7)<<(finalans*6.0)/(n*(n-1))<<endl;

    }
    
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