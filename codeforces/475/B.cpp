#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj, int node, vector<int>&vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(vis[it] == -1){
            dfs(adj, it, vis);
        }
    }
}
void reverseEdges(vector<vector<int>>&adj, vector<vector<int>>&revAdj, int len){
    for(int i=1; i<=len; i++){
        for(auto it: adj[i]){
            revAdj[it].push_back(i);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    string hdir, vdir;
    cin>>hdir>>vdir;
    int curr=1;
    vector<vector<int>>adj(n*m+1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m-1; j++){
            if(hdir[i] == '>'){
                adj[curr].push_back(curr+1);
            }
            else{
                adj[curr+1].push_back(curr);
            }
            curr++;
        }
        curr++;
    }
    for(int i=0; i<m; i++){
        int curr=i+1;
        for(int j=0; j<n-1; j++){
            if(vdir[i] == 'v'){
                adj[curr].push_back(curr+m);
            }
            else{
                adj[curr+m].push_back(curr);
            }
            curr+=m;
        }
    }
    // for(int i=1; i<=m*n; i++){
    //     cout<<i<<": "<<flush;
    //     for(auto it: adj[i]){
    //         cout<<it<<" "<<flush;
    //     }
    //     cout<<endl;
    // }
    vector<int>vis(n*m + 1, -1);
    for(int i=1; i<=n*m; i++){
        
        if(vis[i] == -1 && i!= 1){
            cout<<"NO"<<endl;
            return 0;
        }
        else{
            dfs(adj, 1, vis);
        }
        
    }
    vector<vector<int>>revAdj(n*m+1);
    reverseEdges(adj, revAdj, m*n);
    for(int i=1; i<=m*n; i++){
        vis[i] = -1;
    }
    for(int i=1; i<=n*m; i++){
        if(vis[i] == -1 && i!= 1){
            cout<<"NO"<<endl;
            return 0;
        }
        else{
            dfs(revAdj, 1, vis);
        }
    }
    cout<<"YES"<<endl;
    
}