#include<bits/stdc++.h>
using namespace std;
const int N=260;
int n,d[N],p[N],x;
char ans[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("? %d ",i);
		for(int j=1;j<=n;j++) putchar(i^j?'1':'0');
		puts(""),fflush(stdout);
		scanf("%d",&d[i]),p[i]=i,ans[i]='0';
	}
	sort(p+1,p+1+n,[](int x,int y){return d[x]>d[y];});
	for(int i=1,s=0;i<=n;i++){
		ans[p[i]]='1',s+=d[p[i]];
		if(s==i*(i-1)/2+i*(n-i)) break;
	}
	printf("! %s\n",ans+1),fflush(stdout);
	return 0;
}