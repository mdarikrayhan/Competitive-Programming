#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	int pa=a/m,pb=b/m;
	if(a%m!=0)pa++;
	if(b%m!=0)pb++;
	if(n==1||m==1||pa==pb){
		cout<<1<<endl;
		return 0;
	}
	if(a%m==1&&(b%m==0||b==n)){
		cout<<1<<endl;
	}else if((a%m==1||b%m==0)||(b-a+1)%m==0||pb-pa<=1||b==n){
		cout<<2<<endl;
	}else{
		cout<<3<<endl;
	}
	return 0;
}

						 	  	    				 	 	  	 	