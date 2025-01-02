#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ordered_set; 
#define sz(a) a.size()
using namespace std;
#define mod 998244353
#define int long long 
#define endl "\n"
#define ll long long 
#define ff  first
#define ss second
#define f(i,a,b) for(int i(a);i<b;i++)
#define rep(i,n) for(int i(0);i<n;i++)
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define pres(x) cout<<fixed; cout<<setprecision(x);
#define watch(x) cout<<(#x)<<" is "<<x<<"\n";
#define out(x) cout<<x<<"\n";
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define inf 1e18
#define pdd pair<double, double>
#define ld long double
#define ar array
int gcd(int a,int b){return (b==0) ? a:gcd(b,a%b);} 
int power(int a,int b){
    int ans=1;
    while(b!=0){
        if(b&1){ans=(ans*a)%mod;b--;}
        a=(a*a)%mod;b/=2;
    }
    return ans%mod;
}
  
int invmod(int n){
    int ans=1;
    ans=power(n,mod-2);
    return ans;
    
}
 
int min(int a,int b){return (a<b) ? a:b;}
int max(int a,int b){return (a>b) ? a:b;}
 
// int fact[200005];
// int infact[200005];
void DFS(int v, bool visited[], int &root, vector<int> edges[])
{
    visited[v] = true;
    for (auto it : edges[v])
        if (!visited[it])
            DFS(it, visited, root, edges);
    root = v;
}
 
int cnt(int v, bool visited[], vector<int> edges[])
{
    int ans = 1;
    visited[v] = true;
    for (auto it : edges[v])
        if (!visited[it])
            ans += cnt(it, visited, edges);
    return ans;
}
 
void solve(){
    int i, j, n, m, u, v, w;
        cin >> n >> m;
        vector<pair<int, int>> og_edges[n];
        for (i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            u--, v--;
 
            og_edges[u].push_back({v, w});
        }
 
        int l = -1, r = 1e9 + 1, mid;
        while (r - l > 1)
        {
            mid = l + (r - l) / 2;
 
            vector<int> edges[n];
            for (i = 0; i < n; i++)
            {
                for (auto it : og_edges[i])
                {
                    edges[i].push_back(it.first);
                    if (it.second <= mid)
                        edges[it.first].push_back(i);
                }
            }
 
            bool visited[n] = {0};
            int root;
            for (i = 0; i < n; i++)
            {
                if (!visited[i])
                    DFS(i, visited, root, edges);
            }
 
            memset(visited, false, sizeof(visited));
 
            if (cnt(root, visited, edges) == n)
                r = mid;
            else
                l = mid;
        }
 
        if (r == 1e9 + 1)
            r = -1;
        cout << r << '\n';

}


signed main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ; 
    freopen("output.txt","w",stdout);
    #endif
 
    // fact[0]=1;
    // infact[0]=invmod(fact[0]);
    // f(i,1,200005){
    //  fact[i]=fact[i-1]*i;fact[i]%=mod;
    //  infact[i]=invmod(fact[i]);
    // }
 
    int t=1;
    cin>>t;
    while(t--){
 
    solve();
    }
  
}