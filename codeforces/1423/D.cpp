#include<bits/stdc++.h>
using namespace std;
const int N=205,M=1e6+5;
inline int read(){
    int x=0,f=1; char s;
    while((s=getchar())<'0'||s>'9') if(s=='-') f=-1;
    while(s>='0'&&s<='9') x=(x*10)+(s^'0'),s=getchar();
    return x*f;
}
struct node{ int x,y,w; };
int k,n,m,w,t,dx[M],dy[M],sx,sy;
char s[2],ma[N][N];
bool ok[205][205][21*200+5];
int f[205][205],g[205][205];
int xx[6]={0,0,0,1,-1};
int yy[6]={0,1,-1,0,0};
queue<node>q;
int main(){
	n=read(),m=read(),k=read(),t=read(),w=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%s",s),ma[i][j]=s[0];
			if(s[0]=='M') sx=i,sy=j;
	}}
	for(int i=0;i<=n;++i) ma[i][m+1]=ma[i][0]='L';
	for(int i=0;i<=m;++i) ma[n+1][i]=ma[0][i]='L';
	for(int i=1;i<=w;++i){ 
		scanf("%s",s); 
		if(s[0]=='N') dx[i]=-1;
		else if(s[0]=='S') dx[i]=1;
		else if(s[0]=='E') dy[i]=1; 
		else if(s[0]=='W') dy[i]=-1;
	}
	int lim=k*(t+1);
	for(int i=1,x,y,w;i<=t;++i){
		x=read()+1,y=read()+1,w=read();
		if(w<=lim) ok[x][y][w]=1;
	}
	f[sx][sy]=k;
	q.push((node){sx,sy,k});
	for(int i=1,x,y,nx,ny;i<=lim;++i){
		memset(f,0,sizeof(f));
		while(!q.empty()){
			node tmp=q.front();q.pop();
			x=tmp.x+dx[i],y=tmp.y+dy[i];
			
			if(ma[x][y]!='L'){f[x][y]=max(f[x][y],tmp.w-1);
			if(ok[x][y][i]) f[x][y]=k;
			if(ma[x][y]=='P') {cout<<i; return 0;}}
			for(int j=1;j<=4;++j){
				nx=x+xx[j],ny=y+yy[j];
				if(nx<1||nx>n||ny<1||ny>m) continue;
				if(ma[nx][ny]=='L') continue;
				if(ma[nx-dx[i]][ny-dy[i]]=='L'&&ma[x][y]=='L') continue;
				if(ma[nx][ny]=='P') { cout<<i; return 0;}
				f[nx][ny]=max(tmp.w-1,f[nx][ny]);
				if(ok[nx][ny][i]) f[nx][ny]=k;
			}
		}
		for(int a=1;a<=n;++a){
			for(int j=1;j<=m;++j){
				if(f[a][j]) q.push((node){a,j,f[a][j]});
			} 
		}
	}
	cout<<-1;
	return 0;
}