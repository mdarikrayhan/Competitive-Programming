#include<cstdio>
#define maxn 105
using namespace std;
int A[maxn],B[maxn][maxn],C[maxn];
int main(){
	int n,m,ok,cnt;
	scanf("%d%d",&n,&m);cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);B[A[i]][i]=1;
	}for(int i=1;i<=m;i++)scanf("%d",&C[i]),cnt+=C[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)B[i][j]+=B[i][j-1];
	}
	for(int i=cnt;i<=n;i++){
		ok=1;
		for(int j=1;j<=m;j++){
			if((B[j][i]-B[j][i-cnt])!=C[j]){
				ok=0;break;
			}
		}if(ok)break;
	}if(ok)printf("YES");else printf("NO");
	return 0;
} 