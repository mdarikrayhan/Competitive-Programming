#include<bits/stdc++.h>
using namespace std;

const int N=2010,dx[8]={1,2,2,1,-1,-2,-2,-1},dy[8]={2,1,-1,-2,-2,-1,1,2};
int n,m,xa,xb,ya,yb,dis1[N][N],dis2[N][N];

void bfs(int x,int y,auto&d){
	queue<pair<int,int> >Q;Q.emplace(x,y);d[x][y]=0;
	while(!Q.empty()){
		auto t=Q.front();Q.pop();
		for(int k=0;k<8;++k){
			int nx=t.first+dx[k],ny=t.second+dy[k];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&d[nx][ny]>d[t.first][t.second]+1){
				d[nx][ny]=d[t.first][t.second]+1;
				Q.emplace(nx,ny);
			}
		}
	}
}

void dfs(int x,int y,auto&d){
	for(int k=0;k<8;++k){
		int nx=x+dx[k],ny=y+dy[k];
		if(d[nx][ny]<d[x][y]){
			cout<<nx<<' '<<ny<<endl;
			dfs(nx,ny,d);
			return;
		}
	}
}

int main(){
	memset(dis1,0x3f,sizeof dis1);
	memset(dis2,0x3f,sizeof dis2);
	cin>>n>>m>>xa>>ya>>xb>>yb;
	bfs(n/2,m/2,dis1);bfs(n/2+1,m/2,dis2);
	int u=dis1[xa][ya],v=dis1[xb][yb],p=dis2[xa][ya],q=dis2[xb][yb];
	if((xa+ya+xb+yb)%2==0){
		if(q<u){
			cout<<"BLACK"<<endl;
			dfs(xb,yb,dis2);
		}else
		if(v<u+1){
			cout<<"BLACK"<<endl;
			dfs(xb,yb,dis1);dfs(n/2,m/2,dis2);
		}else{
			cout<<"WHITE"<<endl;
			dfs(xa,ya,dis1);
		}
		return 0;
	}
	if(u<=q){
		cout<<"WHITE"<<endl;
		dfs(xa,ya,dis1);
	}else if(p<=q+1){
		cout<<"WHITE"<<endl;
		dfs(xa,ya,dis2);dfs(n/2+1,m/2,dis1);
	}else{
		cout<<"BLACK"<<endl;
		dfs(xb,yb,dis2);
	}
	
	return 0;
}