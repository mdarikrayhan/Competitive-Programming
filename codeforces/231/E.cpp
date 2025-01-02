#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=1e5+1,mod=1e9+7,M=20;
vector<int> gr[N],congr[N];
bool visited[N];
stack<int> st;
int cycles;
int cycleno[N],val[N];
int dep[N],dep1[N],Par[N][M];

void dfs1(int node,int par = -1){
    visited[node]=true;
    st.push(node);

    for(auto child:gr[node]){
        if(child == par) continue;

        if(visited[child]){
            if(!st.empty() && st.top() == node){
                cycles++;
                while(st.top() != child){
                    cycleno[st.top()]=cycles;
                    st.pop();
                }
                cycleno[st.top()]=cycles;
                st.pop();
                val[cycles]=1;
            }
        }
        else{
            dfs1(child,node);
        }
    }
    if(!st.empty() && st.top() == node){
        cycles++;
        val[cycles]=0;
        cycleno[st.top()]=cycles;
        st.pop();
    }
}

void dfs2(int u,int par){
	dep[u]=1+dep[par];
    dep1[u]=val[u]+dep1[par];

	Par[u][0]=par;
	for(int j=1;j<M;j++){
		Par[u][j]=Par[Par[u][j-1]][j-1];
	}

	for(auto x:congr[u]){
		if(x != par){
			dfs2(x,u);
		}
	}
}

int LCA(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	int diff=dep[u]-dep[v];

	for(int j=M-1;j>=0;j--){
		if((diff>>j) & 1) u=Par[u][j];
	}
	if(u == v)  return u;

	for(int j=M-1;j>=0;j--){
		if(Par[u][j] != Par[v][j]){
			u=Par[u][j];
			v=Par[v][j];
		}
	}
	return Par[u][0];
}

int que(int u,int v){
    int lca=LCA(u,v);
    return dep1[u]+dep1[v]-2*dep1[lca]+val[lca];
}

int pow(int a,int b){
    int res=1;
    while(b > 0){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

void solve(){
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    gr[a].pb(b);gr[b].pb(a);
   }
   cycles=0;
   dfs1(1);
   for(int i=1;i<=n;i++){
    for(auto x:gr[i]){
        if(cycleno[i] != cycleno[x])
        congr[cycleno[i]].pb(cycleno[x]);
    }
   }
   dfs2(1,0);
   int q;
   cin>>q;
   while(q--){
    int u,v;
    cin>>u>>v;
    int no=que(cycleno[u],cycleno[v]);
    cout<<pow(2LL,no)<<'\n';
   }

}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t=1;
    // cin>>t;
    while(t--) solve();
}