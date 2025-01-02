// LUOGU_RID: 158997685
#include<bits/stdc++.h>
using namespace std;
int n,x,y,shu[4]={0,1,2,3};
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	while(scanf("%d%d",&x,&y)!=EOF)
		swap(shu[x],shu[y]);
	printf("%d",shu[n]);
	fclose(stdin);fclose(stdout);
	return 0;
}