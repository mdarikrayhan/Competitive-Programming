// LUOGU_RID: 158748438
#include<bits/stdc++.h>
using namespace std;
// 11:23
const int D=505,S=5005;
int d,s;

queue<pair<int,int>>q;bool vis[D][S];
int px[D][S],py[D][S];
inline void bfs(){
	q.emplace(0,0);vis[0][0]=true;
	while(!q.empty()){
		int i=q.front().first,j=q.front().second;q.pop();
		for(int k=0;k<10;k++){
			int x=(i*10+k)%d,y=j+k;
			if(y<=s&&!vis[x][y]){px[x][y]=i;py[x][y]=j;vis[x][y]=true;q.emplace(x,y);}
		}
	}
}
void print(int i,int j){
	if(!i&&!j)return;
	print(px[i][j],py[i][j]);
	putchar(0x30|j-py[i][j]);
}
int main(){
	scanf("%d%d",&d,&s);
	bfs();
	if(!vis[0][s])puts("-1");
	else print(0,s);
	return 0;
}
