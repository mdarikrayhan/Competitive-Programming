#include<bits/stdc++.h>
using namespace std;
int main(){
	int a1,a2,b3,b4;
	cin>>a1>>a2>>b3>>b4;
	if(b3>=a2-1&&b3<=2*(a2+1)){
		cout<<"YES";
		return 0;
	}
	if(b4>=a1-1&&b4<=2*(a1+1)){
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
	return 0;
} 
						  				       	   	 	 			