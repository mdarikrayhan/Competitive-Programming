#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
const int N=2145;
char a[N][N];
int n,m;
int main(){scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",a[i]+1);
	rep(i,1,n)rep(j,1,m)if(a[i][j]=='.'&&a[i][j+1]=='.')a[i][j]=a[i][j+1]=i%3*3+(j+((i+j)&1))%3+'0';
	rep(i,1,n)rep(j,1,m)if(a[i][j]=='.'&&a[i+1][j]=='.')a[i][j]=a[i+1][j]=i%3*3+(j+((i+j)&1))%3+'0';	
	rep(i,1,n)rep(j,1,m)if(a[i][j]=='.'){
		if(isdigit(a[i][j+1]))a[i][j]=a[i][j+1];
		else if(isdigit(a[i][j-1]))a[i][j]=a[i][j-1];
		else if(isdigit(a[i+1][j]))a[i][j]=a[i+1][j];
		else if(isdigit(a[i-1][j]))a[i][j]=a[i-1][j];
		else puts("-1"),exit(0);
	} rep(i,1,n)printf("%s\n",a[i]+1);
}