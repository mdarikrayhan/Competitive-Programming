#include<bits/stdc++.h>
using namespace std;
int n,m,k,s;
int a[2005][2005];
int b[100005];
int c[10][10];
int x[10][4];
int y[10][4];
int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};
int ans;
int main(){
	cin >> n >> m >> s >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			for(int id=0;id<4;id++){
				if(!x[a[i][j]][id]||dx[id]*x[a[i][j]][id]+dy[id]*y[a[i][j]][id]<dx[id]*i+dy[id]*j){
					x[a[i][j]][id]=i;
					y[a[i][j]][id]=j;
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		cin >> b[i];
	}
	for(int i=2;i<=k;i++){
		for(int id=0;id<4;id++){
			ans=max(ans,abs(x[b[i]][id]-x[b[i-1]][3-id])+abs(y[b[i]][id]-y[b[i-1]][3-id]));
		}
	}
	cout << ans << endl;
	return 0;
} 
 		  	  	    		 	 		 			 	  	 	