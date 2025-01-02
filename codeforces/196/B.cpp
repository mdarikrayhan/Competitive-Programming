// LUOGU_RID: 160080928
#include<bits/stdc++.h>
using namespace std;
const int N = 1510;
int n,m;
char nv[N][N];
int s[N][N][3];
int sx,sy;
bool success=false;

bool dfs(int x,int y){
	if(success)	return true;
	
	int xx=(x%n+n*m)%n,yy=(y%m+m*n)%m;
	
	if(s[xx][yy][0] && (s[xx][yy][1]!=x || s[xx][yy][2]!=y))
		return success=true;
	
	s[xx][yy][0]=true,s[xx][yy][1]=x,s[xx][yy][2]=y;
	int ax[4]={1,0,-1,0},ay[4]={0,1,0,-1};
	for(int i=0;i<4;i++){
		int a=x+ax[i],b=y+ay[i];
		int aa=(a%n+n*m)%n,bb=(b%m+m*n)%m;
		if(nv[aa][bb]=='#')	continue;
		if(s[aa][bb][0] && s[aa][bb][1]==a && s[aa][bb][2]==b)
			continue;
		if(dfs(a,b))	return true;
	}
	
	return false;
}


int main(){
	scanf("%d%d",&n,&m); 
		
	memset(s,0,sizeof s);
	success=false;
	
	for(int i=0;i<n;i++){
		scanf("%s",nv[i]);
		for(int j=0;j<m;j++)
			if(nv[i][j]=='S')
				sx=i+2*n,sy=j+2*m,nv[i][j]='.';
	}
		
	bool flag=false;
	for(int i=0;i<m;i++)
		if(nv[0][i]!='#' && nv[n-1][i]!='#'){
			flag=true;
			break;
		}
	for(int i=0;i<n;i++)
		if(nv[i][0]!='#' && nv[i][m-1]!='#'){
			flag=true;
			break;
		}
	
	if(!flag){
		printf("No\n");
		return 0;
	}else{
		dfs(sx,sy);
		if(success)	printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}