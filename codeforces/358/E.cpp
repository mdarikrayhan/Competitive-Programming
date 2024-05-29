#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1e3;
int di[4]={-1,0,1,0},dj[4]={0,-1,0,1};
int n,m;
int a[N+10][N+10];
bool vis[N+10][N+10][4];
int esum=0;
int ans=0;
inline int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
inline void dfs(int x,int y,int ld,int len){
	bool mv=false;
	for(int d=0;d<4;++d){
		if(!vis[x][y][d]){
			int xx=x+di[d],yy=y+dj[d];
			vis[x][y][d]=1;
			vis[xx][yy][d^2]=1;
			if(a[xx][yy]){
				mv=true;
				++esum;
				if(d!=ld){
					ans=gcd(ans,len);
					dfs(xx,yy,d,1);
				}
				else{
					dfs(xx,yy,d,len+1);
				}
			}
		}
	}
	if(!mv){
		ans=gcd(ans,len);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	int dsum=0,osum=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]){
				int du=0;
				for(int d=0;d<4;++d){
					int ii=i+di[d],jj=j+dj[d];
					if(a[ii][jj]){
						++du;
					}
				}
				if(!du){
					cout<<-1;
					return 0;
				}
				dsum+=du;
				osum+=(du&1);
			}
		}
	}
	if(osum&&osum!=2){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]){
				dfs(i,j,-1,0);
				i=n+1;
				break;
			}
		}
	}
	if(dsum>(esum<<1)||ans==1){
		cout<<-1;
		return 0;
	}
	for(int i=2;i<=ans;++i){
		if(ans%i==0){
			cout<<i<<' ';
		}
	}
	return 0;
}
		    	 		 		 	 	  	  		   		