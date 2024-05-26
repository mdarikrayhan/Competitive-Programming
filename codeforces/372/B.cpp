// LUOGU_RID: 160006122
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=40+2;
const int mod=1e9+7;
int dp[N][N][N][N];
int d[N][N][N][N];//预处理每个点左上角的答案
int a[N][N];
bool check(int t,int b,int c,int d){
	for(int i=t;i<=c;i+=1){
		for(int j=b;j<=d;j+=1){
			if(a[i][j]) return 0;
		}
	}
	return 1;
}
void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i+=1){
		for(int j=1;j<=m;j+=1){
			char c;
			cin>>c;
			a[i][j]=c-'0';
		}
	}
	for(int i=1;i<=n;i+=1){
		for(int j=1;j<=m;j+=1){
			for(int k=i;k>=1;k-=1){
				for(int t=j;t>=1;t-=1){
					d[i][j][k][t]=check(k,t,i,j);
					d[i][j][k][t]+=d[i][j][k+1][t]+d[i][j][k][t+1]-d[i][j][k+1][t+1];
				}
			}
		}
	}
//	cout<<d[3][4][2][1]<<endl;
	for(int i=1;i<=n;i+=1){ //长
		for(int j=1;j<=m;j+=1){//宽
			for(int k=1;i+k-1<=n;k+=1){
				for(int t=1;j+t-1<=m;t+=1){
					int x,y;
					x=i+k-1;
					y=j+t-1;
					dp[i][j][k][t]=dp[i][j][k-1][t]+dp[i][j][k][t-1]-dp[i][j][k-1][t-1]+d[x][y][i][j];
				}
			}
		}
	}
	while(q--){
		int i,j,x,y;
		cin>>i>>j>>x>>y;
		x=x-i+1;
		y=y-j+1;
		cout<<dp[i][j][x][y]<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}