#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n;
int main(){
	scanf("%d",&n);
	int cnt1=n/2,cnt2=n-n/2;
	printf("%d\n",cnt1*cnt2);
	for(int i=1;i<=cnt1;i++)
		for(int j=cnt1+1;j<=n;j++)
			printf("%d %d\n",i,j);
	return 0;
} 
				    		   	    							  		 	