// LUOGU_RID: 158509858
#include<bits/stdc++.h>
using namespace std;

#define cor(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
const int INF=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
const int N=54;
int n, m;
char f[N][N];
int d[N][N];
int calc(int stx, int sty){
	queue<pair<int,int> > q;    
	q.push(make_pair(stx, sty));
	memset(d,63,sizeof(d));
	d[stx][sty]=0;
	while (!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if(!cor(tx,ty,n,m)||d[tx][ty]<=d[x][y]+(f[x][y]!=f[tx][ty]))	continue;
			d[tx][ty]=d[x][y]+(f[x][y]!=f[tx][ty]);
			q.push(make_pair(tx, ty));
        }
    }
    int res=-1;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(f[i][j]=='B')	res=max(res,d[i][j]);
		}
	}
    return res;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%s",f[i]);
	}
	int ans=1e9+7;
	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
			ans=min(ans,calc(i,j)+1); 
		}
	}
    cout<<ans<<endl;
    return 0;
}