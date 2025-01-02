#include <bits/stdc++.h>
using namespace std;
int n;
char p[66][66][66];
int main(){
	scanf("%d",&n);
	int X=3*n,Y=3*n,H=3;
	for (int i=1;i<=X;i++)
		for (int j=1;j<=Y;j++)
			for (int k=1;k<=H;k++)
				 p[k][i][j]='#';
	for (int j=1;j<=Y;j++)
		for (int i=1;i<=n;i++){
			p[1][3*i][j]=p[3][j][3*i]='.';
		}
	for (int i=1;i<=n;i++) p[3][3*i][3*i]=i+'0';
	for (int i=1;i<=n;i++){
		p[2][3*i-1][3*i]='.';
		p[2][3*i-1][3*i-1]='.';
		p[1][3*i-1][3*i-1]='.';
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int x; scanf("%d",&x);
			if (!x) continue;
			if (i==j) continue;
			for (int k=1;k<=3;k++) p[k][3*i-1][3*j-1]='.';
		}
	}
	printf("%d %d %d\n",X,Y,H);
	for (int d=1;d<=H;d++){
		for (int i=1;i<=X;i++){
			for (int j=1;j<=Y;j++)
				printf("%c",p[d][i][j]);
			puts("");
		}
		puts("");
	}
	return 0;
}