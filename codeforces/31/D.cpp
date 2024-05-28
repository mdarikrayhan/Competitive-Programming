#include<bits/stdc++.h>
using namespace std ;
#define int long long 
int W, H, n ;
vector<vector<int>> vis1 ;
map<pair<pair<int,int>,pair<int,int>>,int> vis2;
int dx[4] = {1,0,-1,0} ;
int dy[4] = {0,-1,0,1} ;
bool is(int xi, int yi) {
    if(xi>W||xi<1) return false ;
    if(yi>H||yi<1) return false ;
    return true ;
}
void dfs(int xi, int yi,int &area) {
    vis1[xi][yi] = 1 ;
    area++;
    for(int k=0;k<4;k++) {
        int tx = xi + dx[k] ;
        int ty = yi + dy[k] ;
        if(!is(tx,ty)||vis1[tx][ty]) continue ;
        if(k==0) {
            if(!vis2[{{xi,yi-1},{xi,yi}}]) {
                dfs(tx,ty,area) ;
            }
        }  
        
        else if (k==1) {
            if(!vis2[{{xi-1,yi-1},{xi,yi-1}}]) {
                dfs(tx,ty,area) ;
            }
        }  
        else if (k==2) {
            if(!vis2[{{xi-1,yi-1},{xi-1,yi}}]) {
                dfs(tx,ty,area) ;
            }
        }   
        else if (k==3) {
            if(!vis2[{{xi-1,yi},{xi,yi}}]) {
                dfs(tx,ty,area) ;
            } 
        } 
    }
}
int32_t main() {
    cin>>W>>H>>n ; 
    vis1.assign(W+2,vector<int> (H+2,0)) ;
    !vis2[{{0,0},{0,0}}] ;
    for(int i=0;i<n;i++) {
        int x1, y1, x2, y2 ;
        cin>>x1>>y1>>x2>>y2 ;
        if(x1==x2) {
            for(int j=y1;j<y2;j++) {
                vis2[{{x1,j},{x1,j+1}}] = 1 ;
            }
        } 
        else if (y1==y2) {
            for(int j=x1;j<x2;j++) {
                vis2[{{j,y1},{j+1,y1}}] = 1 ;
            }
        }
    }
    vector<int> areas ;
    for(int i=1;i<=W;i++) {
        for(int j=1;j<=H;j++) {
            if(vis1[i][j]) continue; 
            int area = 0;
            dfs(i,j,area) ;
            areas.push_back(area) ;
        }
    }
    std::sort(areas.begin(),areas.end()) ;
    for(auto x:areas) cout<<x<<" ";
    
}