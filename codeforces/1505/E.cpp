#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
using namespace __gnu_pbds; 

int h,w,a[10][10];

int dfs(int x,int y){
	if(x==h && y==w){
		return a[x][y];
	}
	if(x<h && y<w && a[x+1][y]==a[x][y+1]){
		return dfs(x,y+1)+a[x][y];
	}
	if(x<h && (a[x+1][y] || y==w)){
		return dfs(x+1,y)+a[x][y];
	}
	return dfs(x,y+1)+a[x][y];
}

main() {
	ios_base::sync_with_stdio(0);
	cin>>h>>w;
	for(int i=1;i<=h;++i){
		for(int j=1;j<=w;++j){
			char c;
			cin>>c;
			a[i][j]=(c=='*');
		}
	}
	cout<<dfs(1,1);
}