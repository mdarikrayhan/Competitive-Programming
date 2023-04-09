#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n==5){
		puts("1 2 3");
		puts("1 3 3");
		puts("2 4 2");
		puts("4 5 1");
		puts("3 4");
		puts("3 5");
		return 0;
	}
	else{
		int t=n/2;
		for(int i=1;i<=t;i++)printf("%d %d %d\n",i,i+t,1);
		for(int i=1;i+t<n;i++)printf("%d %d %d\n",i+t,i+t+1,2*i-1);
		for(int i=1;i<t;i++)printf("%d %d\n",i,i+1);
		puts("1 3");
	}
}
		 	  				    	 		 	 	    	