#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
int mod=1e9+7;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
         
int solve(int i,vector<int> adj[],vector<int> &v){
    int x=0,maxi=0,a=0,d=0;
    for(auto j:adj[i]){
        int k=solve(j,adj,v);
        x+=k;
        a+=(v[j]-k);
        if(maxi<k){
            d=(v[j]-k);
        }
        else if(maxi==k){
            d=max(d,v[j]-k);
        }
        maxi=max(maxi,k);
    }
    if(!x) return 1;
    a-=d;
    x-=maxi;
    if(maxi-a<=x){
        x+=maxi;
        if(x&1){
            return 2;
        }
        return 1;
    }
    else{
        maxi-=(x+a);
        return maxi+1;
    }
    return 0;

}

void dfs(int i,vector<int> adj[],vector<int> &v){
    for(auto j:adj[i]){
        dfs(j,adj,v);
        v[i]+=v[j];
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
           
int t;
cin>>t;
while(t--){
int n;
cin>>n;
vector<int> adj[n+1],v(n+1,1);
for(int i=2;i<=n;i++){
    int x;
    cin>>x;
    adj[x].push_back(i);
}
dfs(1,adj,v);
int k=solve(1,adj,v);
n-=k;
cout<<n/2<<endl;

 
}
return 0;
}