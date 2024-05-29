// LUOGU_RID: 109549936
#include<bits/stdc++.h>
using namespace std;
int n;
void work(int x,int y){printf("%d %d\n",x,y);}
int main(){
	scanf("%d",&n);
	if(n%4>1)return puts("NO"),0;
	puts("YES");
	for(int p=1;p<n;){
		int x=p,y=p+1,z=p+2,w=p+3;p+=4;
		for(int i=p;i<=n;i++)work(x,i);
		work(x,y);
		for(int i=n;i>=p;i--)work(y,i);
		for(int i=p;i<=n;i++)work(z,i);
		work(z,w);
		for(int i=n;i>=p;i--)work(w,i);
		work(x,z);work(y,w);work(x,w);work(y,z);
	}
	return 0;
}