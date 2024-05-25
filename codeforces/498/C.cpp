#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
vector<vector<int>> adj;
vector<vector<bool>> cap;
bool dfs(int u, vector<int> &path){
    if(visited[u]) return false;
    if(u == cap.size()-1){
        path.push_back(u);
        return true;
    }
    visited[u] = true;
    for(int v: adj[u]){
        if(!cap[u][v]) continue;
        if(!dfs(v, path)) continue;
        path.push_back(u);
        return true;
    }
    return false;
}
int MaxFlow(){
    vector<int> path;
    visited = vector<bool>(cap.size(), false);
    while(dfs(0, path)){
        int u = path.back();
        for(int i = path.size()-2; i >= 0; --i){
            int v = path[i];
            cap[u][v] = 0;
            cap[v][u] = 1;
            u = v;
        }
        path = vector<int>();
        visited = vector<bool>(cap.size(), false);
    }
    int ans = 0;
    for(bool val: cap.back()) ans += val;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    
    vector<int> vertexVal, from(n);

    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;

        from[i] = vertexVal.size();
        for(int i = 2; i*i <= a; ++i){
            while(a%i == 0){
                a/=i;
                vertexVal.push_back(i);
            }
        }
        if(a!=1) vertexVal.push_back(a);
    }

    cap = vector<vector<bool>>(vertexVal.size()+2, vector<bool>(vertexVal.size()+2, 0));
    adj = vector<vector<int>>(vertexVal.size()+2);

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(u%2) swap(u,v);

        int r = (u+1<from.size()? from[u+1]:vertexVal.size());
        for(int i = from[u]; i < r; ++i){
            cap[0][i+1] = 1;
            adj[0].push_back(i+1);
            adj[i+1].push_back(0);

            int r = (v+1<from.size()?from[v+1]:vertexVal.size());
            for(int j = from[v]; j < r; ++j){
                cap[j+1].back() = 1;
                adj[j+1].push_back(adj.size()-1);
                adj.back().push_back(j+1);

                if(vertexVal[i] != vertexVal[j]) continue;
                cap[i+1][j+1] = 1;
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
    }
    cout << MaxFlow();
}
	        				     		 		 		  	