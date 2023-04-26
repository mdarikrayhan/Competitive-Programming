#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int> >d={{0,1},{0,-1},{1,0},{-1,0}},shit;
int i,j,k,n,m,t;
vector<vector<int> >a;
set<pair<int,int> >sb;

bool chk0(int x,int y){
	if(a[x][y]==1)return 1;
	if(a[x][y]>n*m)return 1;
	for(auto [dx,dy]:d){
		dx+=x;dy+=y;
		if(a[dx][dy]<a[x][y])return 1;
	}
	return 0;
}

void chk(int x1,int y1,int x2,int y2){
	swap(a[x1][y1],a[x2][y2]);
	int i,j,k,res=1,r1,r2;
	for(auto [x,y]:shit)if(!chk0(x,y)){res=0;goto aaa;}
	if(!chk0(x1,y1)||!chk0(x2,y2)){res=0;goto aaa;}
	for(auto [dx,dy]:d)if(!chk0(dx+x1,dy+y1)||!chk0(dx+x2,dy+y2)){res=0;goto aaa;}
	r1=x1*m+y1,r2=x2*m+y2;
	sb.insert({min(r1,r2),max(r1,r2)});
	aaa:swap(a[x1][y1],a[x2][y2]);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	a=vector<vector<int> >(n+2,vector<int>(m+2,1e9) );
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		if(a[i][j]==1)continue;
		if(!chk0(i,j))shit.push_back({i,j});
	}
	if(shit.empty()){cout<<"0";return 0;}
	if(shit.size()>5){cout<<"2";return 0;}
	auto [x,y]=shit[0];
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		chk(i,j,x,y);
		for(auto [dx,dy]:d){
			dx+=x;dy+=y;
			if(a[dx][dy]>n*m)continue;
			chk(i,j,dx,dy);
		}
	}
	int res=sb.size();
	if(res)cout<<1<<' '<<res;
	else cout<<2;
}