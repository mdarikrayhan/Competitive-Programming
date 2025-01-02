// LUOGU_RID: 157490476
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue> 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int N=1<<8,INF=1e7;
const int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int n,m,cnt,ans=-1e9;
int stx,sty;
char a[22][22];
int tx[10],ty[10],tc[N],dp[22][22][N],lg[N],sum[N];

struct node {
	int x,y,state;
};
queue<node> q;

int work(int x,int y,int nx,int ny,int i) {
	if(x==nx) return 0;
	if(nx<x && tx[i]==x && ty[i]<y) return 1;
	if(nx>x && tx[i]==nx && ty[i]<y) return 1;
	return 0;	
}

void bfs() {
	memset(dp,0x3f,sizeof dp);
	dp[stx][sty][0]=0;
	q.push({stx,sty,0});
	while(!q.empty()) {
		int x=q.front().x,y=q.front().y,S=q.front().state;
		q.pop();
		
		rep(i,0,3) {
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]!='B' && a[nx][ny]!='#' && !(a[nx][ny]>='0' && a[nx][ny]<='9')) {
				int ns=S;
				rep(j,1,cnt) ns^=work(x,y,nx,ny,j)<<(j-1);
				if(dp[nx][ny][ns]==dp[0][0][0]) {
					dp[nx][ny][ns]=dp[x][y][S]+1;
					q.push({nx,ny,ns});
				}
			}
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",a[i]+1);
	
	rep(i,1,n) rep(j,1,m) {
		if(a[i][j]=='S') stx=i,sty=j;
		if(a[i][j]>='0' && a[i][j]<='9') {
			cnt++;
			tx[a[i][j]-'0']=i,ty[a[i][j]-'0']=j;	
		}
	}
	rep(i,1,cnt) scanf("%d",&tc[i]);
	
	rep(i,1,n) rep(j,1,m) {
		if(a[i][j]=='B') {
			tx[++cnt]=i,ty[cnt]=j;
			tc[cnt]=-INF;
		}
	}
	
	bfs(); 
	#define lowbit(x) (x&(-x))
	rep(i,0,cnt-1) lg[1<<i]=i;
	rep(i,1,(1<<cnt)-1) sum[i]=sum[i-lowbit(i)]+tc[1+lg[lowbit(i)]];
	rep(i,0,(1<<cnt)-1) ans=max(ans,sum[i]-dp[stx][sty][i]);
	printf("%d\n",ans);	
	return 0;
}
/*
7 7
.......
.1###2.
.#...#.
.#.B.#.
.3...4.
..##...
......S
100
100
100
100
*/
