#include <bits/stdc++.h>

#define suiii ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define co cout<<
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("avx2,sse3,sse4,avx")
using namespace std;
//stuff
ll n;
ll arr[1000001];
ll vis[1000001];
ll ans[1000001];
void solve(){
    set<pair<ll,ll>>s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse(arr,arr+n);
    for(int i=0;i<n;i++){
        s.insert({arr[i],i});
    }
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        s.erase({arr[i],i});
        ans[i]=-1;
        auto it=s.lower_bound({arr[i]+1,0});
        vector<pair<ll,ll>>del;
        while(it!=s.end()){
            ans[it->second]=it->second-i-1;
            vis[it->second]=1;
            del.push_back(*it);
            it++;
        }
        for(auto i:del){
            s.erase(i);
        }
    }
    reverse(ans,ans+n);
    for(int i=0;i<n;i++){
        co ans[i]<<' ';
    }
}

int main()
{
    suiii
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}