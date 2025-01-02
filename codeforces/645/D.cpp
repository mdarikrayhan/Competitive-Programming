#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// ordered_set.find_by_order(k) returns the iterator to kth element
// ordered_set.order_of_key(k) returns the number of elements strictly less than k 

(FOR ORDERED MULTISET "UPPER_BOUND" AND "LOWER_BOUND" ARE REVERSED)
template<class T> using ordered_multiset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// ordered_set.find_by_order(k) returns the iterator to kth element
// ordered_set.order_of_key(k) returns the number of elements strictly less than k 
*/
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define fastio ios_base::sync_with_stdio(0)
#define flush_off cin.tie(0)
#define mod 1000000007
#define ganja 998244353



void solve()
{
    int n,m; cin>>n>>m;

    vector<int>adj[n+1];
    int in[n+1]; memset(in,0,sizeof(in));
    map<pair<int,int>,int>mp;
    for(int i=0; i<m; ++i)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        in[v]++;
        mp[{u,v}] = i+1;
    }


    if(count(in+1,in+n+1,0)!=1)
    {
        cout<<-1<<endl;
        return;
    }

    queue<int>q;
    q.push(find(in+1,in+n+1,0)-in);
    vector<int>top;
    while(!q.empty())
    {
        int s = q.front();
        top.push_back(s);
        q.pop();
        for(auto u:adj[s])
        {
            in[u]--;
            if(in[u]==0) q.push(u);
        }
    }

    int dist[n+1];
    for(int i=1; i<=n; ++i) dist[i] = -1e9;
    dist[top[0]] = 0;
    
    for(int i=0; i<top.size(); ++i)
    {
        for(auto u:adj[top[i]])
        {
            dist[u] = max(dist[u],dist[top[i]]+1);
        }
    }

    if(count(dist+1,dist+n+1,n-1) == 0)
    {
        cout<<-1<<endl;
        return;
    }
    int ans = 0;
    for(int i=1; i<top.size(); ++i)
    {
        int u = top[i-1]; int v = top[i];
        // ans = max(ans,mp[make_pair(u,v)]);
        ans = max(ans,mp[{u,v}]);
    }

    cout<<ans<<endl;


}

int main() {
    fastio;
    flush_off; //turn this off if cout needs to be flushed
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t=1; 
    // cin>>t;
    while(t--)
    {
        solve();
    }
}