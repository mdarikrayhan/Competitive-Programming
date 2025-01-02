// LUOGU_RID: 160168859
#include<bits/stdc++.h>
using i64=long long;
struct SCC{
    std::vector<std::vector<int>>adj;
    std::vector<int>dfn,low,bel;
    std::vector<int>stk;
    int cur,cnt,n;
    SCC(){};
    SCC(int n){
        init(n);
    }
    void init(int n){
        this->n=n;
        adj.assign(n,{});
        dfn.assign(n,-1);
        bel.assign(n,-1);
        low.resize(n);
        cur=cnt=0;
    }
    void add(int u,int v){
        adj[u].push_back(v);
    }
    void dfs(int x){
        low[x]=dfn[x]=cur++;
        stk.push_back(x);
        for(auto y:adj[x]){
            if(dfn[y]==-1){
                dfs(y);
                low[x]=std::min(low[x],low[y]);
            }
            else if(bel[y]==-1){
                low[x]=std::min(low[x],low[y]);
            }
        }
        if(dfn[x]==low[x]){
            int y;
            do{
                y=stk.back();
                bel[y]=cnt;
                stk.pop_back();
            }while(y!=x);
            cnt++;
        }
    }
    auto work(){
        for(int i=0;i<n;i++){
            if(dfn[i]==-1){
                dfs(i);
            }
        }
        return bel;
    }
};
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin>>n;
    SCC scc(n);
    std::vector<int>c(n),a(n);
    for(int i=0;i<n;i++){
        std::cin>>c[i];
    }
    std::vector<std::vector<int>>adj(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        a[i]--;
        adj[i].push_back(a[i]);
        scc.add(i,a[i]);
    }
    auto bel=scc.work();
    int cnt=scc.cnt;
    std::vector<int>cost(cnt,1e5);
    for(int i=0;i<n;i++){
        cost[bel[i]]=std::min(cost[bel[i]],c[i]);
    }
    std::vector<int>dout(cnt,0);
    std::vector<std::vector<int>>v(cnt);
    for(int i=0;i<n;i++){
        for(auto j:adj[i]){
            if(bel[i]!=bel[j]){
                v[bel[i]].push_back(bel[j]);
                dout[bel[i]]++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<cnt;i++){
        ans+=(!dout[i]?cost[i]:0);
    }
    std::cout<<ans<<"\n";
    return 0;
}