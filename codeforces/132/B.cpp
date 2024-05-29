#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=4e18;
const int N=80,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m,k;
char s[N][N];
bool ck(char c){return '1'<=c&&c<='9';}
struct D{int x,y,d,c;}nxt[N][N][4][2];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
		scanf("%s",s[i]+1),k=strlen(s[i]+1);
	for(int x=1;x<=m;++x)
		for(int y=1;y<=k;++y)
			if(ck(s[x][y])){
				for(int d=0;d<4;++d)
					for(int c=0;c<2;++c){
						int xx=x,yy=y,c2=(d+(c?1:3))%4;
						while(s[xx][yy]==s[xx+dx[d]][yy+dy[d]])
							xx+=dx[d],yy+=dy[d];
						while(s[xx][yy]==s[xx+dx[c2]][yy+dy[c2]])
							xx+=dx[c2],yy+=dy[c2];
						if(ck(s[xx+dx[d]][yy+dy[d]]))
							xx+=dx[d],yy+=dy[d],nxt[x][y][d][c]=D{xx,yy,d,c};
						else{
							int cc,dd;
							c?(cc=0,dd=(d+1)%4):(cc=1,dd=d),nxt[x][y][d][c]=D{xx,yy,dd,cc};
						}
					}
			}
	int x=1,y=1,d=0,c=0;
	for(int i=0;i<n;++i){
		D res=nxt[x][y][d][c];
		x=res.x,y=res.y,d=res.d,c=res.c;
	}
	printf("%c\n",s[x][y]);
}