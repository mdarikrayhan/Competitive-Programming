#include<bits/stdc++.h>
using namespace std;
int n,k,q,top,a[13][100010];
struct node {
	int op,x,y;
} p[100020];
int find(int x,int y) {
	if (x<=k) return a[x][y];
	if (p[x].op==1) return max(find(p[x].x,y),find(p[x].y,y));
	if (p[x].op==2) return min(find(p[x].x,y),find(p[x].y,y));
}
int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for (int i=1;i<=k;i++) for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	top=k;
	while (q--) {
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if (op<3) p[++top]=(node){op,x,y};
		else printf("%d\n",find(x,y));
	} 
	return 0;
}

	 					 		  	         		  			 	