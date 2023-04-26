#include<bits/stdc++.h>
using namespace std;
 
int _,n,t,i,x,a[100001],b[100001];
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		t=0;
		memset(a,0,sizeof a);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			if(x<=n&&!a[x])a[x]=1;else b[++t]=x;
		}
		sort(b+1,b+t+1);
		for(i=t=1;i<=n;i++)if(!a[i])if(i*2>=b[t]){puts("-1");goto br;}else t++;
		printf("%d\n",t-1);
		br:;
	}
}