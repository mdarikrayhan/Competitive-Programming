#include<bits/stdc++.h>
using namespace std;
const int N=1007;
int n,f[N][2*N],g[N][2*N][3];
int main() {
	scanf("%d",&n);
	queue<pair<int,int> > q;
	q.push({0,N});
	while(!q.empty()) {
		int x=q.front().first,y=q.front().second; q.pop();
		int s=0;
		if(x==0&&y==N) s++;
		for(int i=s;i<10;i++) {
			int xx=(x+n*i)/10,xxx=(x+n*i)%10,yy=y+xxx*n-i;
			if(yy>=0&&yy<2*N&&!f[xx][yy]) {
				f[xx][yy]=1;
				g[xx][yy][0]=x;
				g[xx][yy][1]=y;
				g[xx][yy][2]=i;
				q.push({xx,yy});
			}
		}
	}
	if(!f[0][N]) {puts("-1"); return 0;}
	string ans;
	int x=0,y=N;
	do {
		int xx=g[x][y][0],yy=g[x][y][1];
		ans+=char('0'+g[x][y][2]);
		x=xx; y=yy;
	} while(x!=0||y!=N);
	while(ans[0]=='0') ans.erase(ans.begin());
	cout<<ans;
	return 0;
}