#include <bits/stdc++.h>
using namespace std;
int i,x,T,Max;double s;
int main(){
	scanf("%d",&T);
	while (T--){
		for (s=Max=0,i=1;i<=250;i++)
			scanf("%d",&x),s+=x*x,Max=max(Max,abs(x));
		printf("%s\n",(s/250/Max/Max<0.25)?"poisson":"uniform");
	} 
	return 0;
}