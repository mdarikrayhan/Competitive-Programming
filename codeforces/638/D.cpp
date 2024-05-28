// LUOGU_RID: 160536333
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,K,ans=0;
char x[110][110][110];
signed main(){
	cin>>n>>m>>K;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=K;k++) cin>>x[i][j][k],x[i][j][k]-='0';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=K;k++){
				if(x[i][j][k]){
					if(x[i][j][k-1]&&x[i][j][k+1]) ans++;
					else if(x[i][j-1][k]&&x[i][j+1][k]) ans++;
					else if(x[i-1][j][k]&&x[i+1][j][k]) ans++;
					else if(x[i][j-1][k]&&x[i+1][j][k]&&!x[i+1][j-1][k]) ans++;
					else if(x[i-1][j][k]&&x[i][j+1][k]&&!x[i-1][j+1][k]) ans++;						
					else if(x[i+1][j][k]&&x[i][j][k-1]&&!x[i+1][j][k-1]) ans++;				
					else if(x[i-1][j][k]&&x[i][j][k+1]&&!x[i-1][j][k+1]) ans++;				
					else if(x[i][j-1][k]&&x[i][j][k+1]&&!x[i][j-1][k+1]) ans++;	
					else if(x[i][j+1][k]&&x[i][j][k-1]&&!x[i][j+1][k-1]) ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}