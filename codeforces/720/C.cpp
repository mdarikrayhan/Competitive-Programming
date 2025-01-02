#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 4e4 + 1;
const int M = 501;
int n,m,k,p,G[N][M];
bool ed,flag;
void dfs(int x,int y,int s){
	if(ed) return;
	if((x > 1 || y > 1) && s == k){
		ed = 1;
		int i,j;
		if(!flag){
			for(i = 1;i <= n;i++){
				for(j = 1;j <= m;j++){
					if(G[i][j]) putchar('*');
					else putchar('.');
				}
				puts("");
			}
		}
		else{
			for(j = 1;j <= m;j++){
				for(i = 1;i <= n;i++){
					if(G[i][j]) putchar('*');
					else putchar('.');
				}
				puts("");
			}
		}
		puts("");
		return;
	}
	if(x == n + 1) return;
	else if(y == m + 1){
		dfs(x + 1,1,s);
	}
	else if(++p > 8 * n * m) return;
	else{
		int temp = 0;
		if(G[x - 1][y]) temp += G[x][y + 1] + G[x - 1][y - 1] + G[x - 1][y + 1];
		if(G[x + 1][y]) temp += G[x][y - 1] + G[x + 1][y - 1] + G[x + 1][y + 1];
		if(G[x][y - 1]) temp += G[x - 1][y] + G[x - 1][y - 1] + G[x + 1][y - 1];
		if(G[x][y + 1]) temp += G[x - 1][y + 1] + G[x + 1][y] + G[x + 1][y + 1];
		if(s + temp <= k && (x == 1 || y == 1 || G[x - 1][y] || G[x][y - 1])){
			G[x][y] = 1;
			//printf("%d %d\n",x,y);
			dfs(x,y + 1,s + temp);
			G[x][y] = 0;
		}
		dfs(x,y + 1,s);
	}
}
int main(){
	int i,j,t;
	scanf("%d",&t);
	while(t--){
		p = 0;
		flag = 0,ed = 0;
		memset(G,0,sizeof(G));
		scanf("%d %d %d",&n,&m,&k);
		if(n < m) swap(n,m),flag = 1;
		dfs(1,1,0);
		if(!ed) puts("-1\n");
	}
	return 0;
}