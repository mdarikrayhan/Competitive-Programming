// LUOGU_RID: 159445370
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 255;
int n,m;
int xx[8] = {-1,1,0,0,-1,-1,1,1};
int yy[8] = {0,0,-1,1,-1,1,-1,1};
char s[N][N];
int dfs_1(int x,int y)
{
	int a = 1,b = 1,c = 1,d = 1;
	while(x+1<=n&&s[x+1][y]=='1') x++,a++;
	while(y+1<=m&&s[x][y+1]=='1') y++,b++;
	while(x-1>0&&s[x-1][y]=='1') x--,c++;
	while(y-1>0&&s[x][y-1]=='1') y--,d++;
	if(a==b&&c==d&&a==c) return a;
	return 0;
}
int dfs_2(int x,int y)
{
	int a = 1,b = 1,c = 1,d = 1;
	while(x+1<=n&&y-1>0&&s[x+1][y-1]=='1') x++,y--,a++;
	while(x+1<=n&&y+1<=m&&s[x+1][y+1]=='1') x++,y++,b++;
	while(x-1>0&&y+1<=m&&s[x-1][y+1]=='1') x--,y++,c++;
	while(x-1>0&&y-1>0&&s[x-1][y-1]=='1') x--,y--,d++;
	if(a==b&&b==c&&c==d) return a;
	return 0;
}
int dfs_3(int x,int y)
{
	s[x][y] = '0';
	int w = 1;
	for(int i=0; i<8; i++){
		int dx = x+xx[i],dy = y+yy[i];
		if(dx>0&&dx<=n&&dy>0&&dy<=m&&s[dx][dy]=='1')
			w+=dfs_3(dx,dy);
	}
	return w;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int ans = 0;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++) scanf("%s",s[i]+1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				if(s[i][j]=='1'){
					int a = dfs_1(i,j);
					int b = dfs_2(i,j);
					int w = dfs_3(i,j);
					if(w==4*(a-1)||w==4*(b-1)) ans++;
				}
		printf("%d\n",ans);
	}
	return 0;
}