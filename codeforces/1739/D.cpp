#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
const int N=2e5+10;
vector<ll> g[N];
ll c=0;
vector<ll> dep(N,0);
void dfs(ll vertex,ll par,ll h){
    dep[vertex]=1;
    ll f=0;
    for(auto it:g[vertex]){
        if(it==par) continue;
        dfs(it,vertex,h);
        dep[vertex] = max(dep[it]+1,dep[vertex]);
    }
    if(dep[vertex]==h){
        f=1;
    }
    if(f && par>1){
        c++;
        dep[vertex]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ll tess;
    // tess=1;
    cin >> tess;
    while(tess--){
        ll n,k;
        cin >> n >> k;
        for(int i=0;i<=n;i++){
            g[i].clear();
            dep[i]=0;
        }
        for(int i=2;i<=n;i++){
            ll x;
            cin >> x;
            g[x].push_back(i);
            g[i].push_back(x);
        }
        ll l=1,r=n,ans=n;
        while(l<=r){
            ll mid = (l+r)/2;
            c=0;
            dfs(1,0,mid);
            // cout << c << " ";
            if(c<=k){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout << ans << "\n";
    }
}