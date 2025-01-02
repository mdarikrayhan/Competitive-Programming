#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll M=1e9+7;
void dfs(int i,int j,vector<vector<char>>& mat,vector<vector<bool>>& visited){
	if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || visited[i][j] || mat[i][j]=='#') return;
	int zero=0;
	pair<int,int> pr;
	if(i-1>=0 && mat[i-1][j]=='.'){
		zero++;
		pr.first=i-1;
		pr.second=j;
	}
	if(j-1>=0 && mat[i][j-1]=='.'){
		zero++;
		pr.first=i;
		pr.second=j-1;
	}
	if(i+1<mat.size() && mat[i+1][j]=='.'){
		zero++;
		pr.first=i+1;
		pr.second=j;
	}
	if(j+1<mat[0].size() && mat[i][j+1]=='.'){
		zero++;
		pr.first=i;
		pr.second=j+1;
	}
	if(zero<=1){
		mat[i][j]='+';
	}
	if(zero==1){
		dfs(pr.first,pr.second,mat,visited);
	}
	return;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<char>> mat(n,vector<char> (m));
	int x,y;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
			if(mat[i][j]=='L'){
				x=i;
				y=j;
			}
		}
	}
	vector<vector<bool>> visited(n,vector<bool> (m,false));
	mat[x][y]='+';
	dfs(x-1,y,mat,visited);
	dfs(x,y-1,mat,visited);
	dfs(x+1,y,mat,visited);
	dfs(x,y+1,mat,visited);
	mat[x][y]='L';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cout<<mat[i][j];
		cout<<endl;
	}
	return;
}
int main() {
	#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
	cin>>t;
	while(t--)solve();
	return 0;	
}