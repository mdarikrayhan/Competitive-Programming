#include<cstdio>
 
using namespace std;
 
char a[101][102];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m; scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
		if(a[1][1]=='1'){
			printf("-1\n");
			continue;
		}
		printf("%d\n",n*m-1);
		for(int i=n;i;i--)
			for(int j=m;j;j--)
				if(i!=1)printf ("%d %d %d %d\n",i-(a[i][j]=='1'),j,i,j);
				else if(j!=1) printf("%d %d %d %d\n",i,j-(a[i][j]=='1'),i,j);
	}
}