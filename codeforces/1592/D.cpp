#include <bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define lowbit(x) x&-x
using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int N = 2e5;
const int MOD = 998244353;
const int INF = 1e18;
const ULL base = 13331; 

void solve(){
    int n; cin>>n;
    vector<vector<int>> G(n+10);
    int dfn[n+10]={},timestamp=1;
    bool vis[n+10]={};
    vector<PII>E(n+10);
    int next=1;
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    function<void(int,int)> dfs = [&] (int u,int fa) -> void {
        vis[u]=true;
        for(int v:G[u]){
            if(v==fa){
                continue;
            }
            if(!vis[v]){
                E[next++]={u,v};
                dfs(v,u);
            }
        }
    };
    auto Ask = [&] (int L,int R) -> int {
        set<int>S;
        for(int i=L;i<=R;i++){
            auto [x,y]=E[i];
            S.insert(x); S.insert(y);
        }
        cout << "? " << S.size() << " ";
        for(auto it:S){
            cout << it << " ";
        }
        cout << endl;
        int res; cin>>res;
        return res;
    };
    dfs(1,-1);
    int maxv=Ask(1,n-1);
    int L=1,R=n-1;
    while(L<=R){
        if(L==R){
            auto [x,y]=E[L];
            cout << "! " << x << " " << y << endl;
            return ;
        }
        int mid=L+R>>1;
        int res=Ask(L,mid);
        if(res==maxv){
            R=mid;
        }else {
            L=mid+1;
        }
    }     
}   
signed main (){
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Task=1; //cin>>Task;
    for(int T=1;T<=Task;T++){
        //cout << "Test: " << T << "\n";
        solve();
    }
    return 0;
}


/*
3
3
1 2 3
1 2
2 3
5
3 2 22 1
1 2
3 1
4 1
1 5
8
699 673 592276600343 369374
7 6
8 5
4 6
7 1
7 2
1 8
4 3

*/
