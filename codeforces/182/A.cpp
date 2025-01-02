// LUOGU_RID: 159289276
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e3+10;
const int mod=1e9+7;
int dp[N];
int d[N][N];
int dis[N];
i64 x[N][2],y[N][2];
i64 get(int x1,int y1,int x2,int y2){
	return (i64)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void solve(){
	int a,b;
	cin>>a>>b;
	i64 sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	int n;
	cin>>n;
	for(int i=1;i<=n;i+=1){
		for(int j=0;j<=1;j+=1){
			cin>>x[i][j]>>y[i][j];
		}
	}
	for(int i=1;i<=n;i+=1){
		for(int j=1;j<=n;j+=1){
			i64 di=1e17;
			i64 ff=1e16;
			for(int k=0;k<=1;k+=1){
				for(int p=0;p<=1;p+=1){
					di=min(di,get(x[i][k],y[i][k],x[j][p],y[j][p]));
					if(min(x[i][0],x[i][1])<=x[j][0]&&max(x[i][0],x[i][1])>=x[j][0]){
						ff=min(ff,abs(y[i][0]-y[j][k]));
					}
					if(i==3&&j==2){
					//	cout<<min(y[i][0],y[i][1])<<" "<<max(y[i][0],y[i][1])<<" "<<y[j][0]<<endl;
					//	cout<<abs(x[i][0]-x[j][1])<<endl;
					//	return;
					}
					if(min(y[i][0],y[i][1])<=y[j][0]&&max(y[i][0],y[i][1])>=y[j][0]){
						ff=min(ff,abs(x[i][0]-x[j][k]));
					}
				}
			}
			if(di<=a*a) d[i][j]=d[j][i]=1;
			if(ff<=a) d[i][j]=d[j][i]=1;
			
		}
	}

	queue<int> q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i+=1){
		for(int j=0;j<=1;j++){
			i64 d=get(sx,sy,x[i][j],y[i][j]);
			if(a*a>=d) dis[i]=1;
			q.push(i);
		}
	}
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int j=1;j<=n;j+=1){
			if(d[x][j]==0) continue;
			if(dis[j]>dis[x]+1){
				dis[j]=dis[x]+1;
				q.push(j);
			}
		}
	}
	//for(int i=1;i<=n;i++) cout<<i<<" "<<dis[i]<<endl;
	double ans=sqrt(get(sx,sy,ex,ey));
	if(ans>a) ans=1e16;
	for(int i=1;i<=n;i+=1){
		i64 d=1e17;
		if(dis[i]>n+n+n) continue;
		i64 ff=1e16;
		for(int j=0;j<=1;j++){
			d=min(d,get(ex,ey,x[i][j],y[i][j]));
			if(min(x[i][0],x[i][1])<=ex&&max(x[i][0],x[i][1])>=ex){
				ff=min(ff,abs(ey-y[i][0]));
				ff=min(ff,abs(ey-y[i][1]));
			}
			if(min(y[i][0],y[i][1])<=ey&&max(y[i][0],y[i][1])>=ey){
				ff=min(ff,abs(ex-x[i][0]));
				ff=min(ff,abs(ex-x[i][1]));
			}
		}
	//	cout<<i<<" "<<dis[i]<<endl;
		if(ff>a) ff=1e16;
		if(d>a*a) d=1e18;
		ans=min(ans,1.0*ff+(a+b)*dis[i]);
		ans=min(ans,sqrt(d)+(a+b)*dis[i]);
	}
	if(ans>1e8){
		cout<<-1<<endl;
		return;
	}
	printf("%.9lf",ans);

	
}
int main(){


	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}