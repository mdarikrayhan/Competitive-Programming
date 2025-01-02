#include <bits/stdc++.h>
#define int long long
using namespace std;
//erase(find(x))!!! for multiset
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    multiset<int> ms;//capped paths
    vector<int> dp(n+1);
    dp.back()=INT_MAX;
    vector<int> m(n,n), m2(n,n);
    auto dfs = [&](auto dfs, int i, int p)->void {
        dp[i]=1;
        vector<int> cs;
        for(auto& c:adj[i]){
            if(c==p)continue;
            dfs(dfs,c,i);
            cs.push_back(c);
        }
        sort(cs.begin(),cs.end(),[&](int i, int j){return dp[i]<dp[j];});
        if(cs.size()>=1)dp[i] = dp[cs[0]]+1, m[i] = cs[0];
        if(cs.size()>=2)m2[i]=cs[1];
        for(int j=1; j<cs.size(); j++){
            ms.insert(dp[cs[j]]);
        }
    };
    dfs(dfs,0,-1);
    //the last path is capped at the root
    ms.insert(dp[0]);
    int ans = 0;
    auto dfs2 = [&] (auto dfs2,int i, int p)->void { 
        //cout<<i<<": ";for(auto& j:ms)cout<<j<<" ";cout<<"\n";
        //cout<<m[i]<<" "<<m2[i]<<" "<<dp[i]<<"\n";
        ans = max(ans,*ms.begin());
        for(auto& c:adj[i]){
            if(c==p)continue;
            vector<int> og{dp[i],dp[c],m[i],m[c],m2[i],m2[c]};
            vector<int> add, ea;
            //the one we took originally
            ms.erase(ms.find(dp[i]));
            add.push_back(dp[i]);
            if(c==m[i]){
                if(m2[i]!=n){
                    dp[i] = dp[m2[i]]+1; //root without mi
                    ms.erase(ms.find(dp[m2[i]]));
                    add.push_back(dp[m2[i]]);
                }
                else dp[i] = 1;
            }
            else{
                //capped child
                if(ms.find(dp[c])!=ms.end()){
                    ms.erase(ms.find(dp[c]));
                    add.push_back(dp[c]);
                }
            }
            if(dp[i]<dp[m[c]]){ //new child ans //watch for infinite<infinite
                ms.insert(dp[m[c]]);//og min is now capped
                ea.push_back(dp[m[c]]);
                dp[c] = dp[i]+1;
                m2[c]=m[c];
                m[c] = i;
            }
            else{ //else we are capped child
                //we might displace second min
                if(dp[i]<dp[m2[c]])m2[c] = i;
                ms.insert(dp[i]);
                ea.push_back(dp[i]);
            }
            ms.insert(dp[c]);
            ea.push_back(dp[c]);
            dfs2(dfs2,c,i);
            //rollback
            dp[i] = og[0],dp[c] = og[1],m[i]=og[2],m[c] = og[3],m2[i] = og[4],m2[c] = og[5];
            for(auto& j:add)ms.insert(j);
            for(auto& j:ea)ms.erase(ms.find(j));
        }
    };
    dfs2(dfs2,0,-1);
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
 	    	      	   				  	 		 		