#include<bits/stdc++.h>
using namespace std;
int i,T,sum,Max,s[255];double v,ans;
int main(){
	scanf("%d",&T);
	while(T--){
		sum=Max=0;
		for (i=1;i<=250;i++)scanf("%d",s+i),sum+=s[i],Max=max(s[i],Max);
		v=sum/250.0;ans=0;
		for (i=1;i<=250;i++)ans+=(s[i]-v)*(s[i]-v);
		printf("%.0f\n",ans/250.0/v>2?Max*1.04/2:v);
	}
	return 0;
}