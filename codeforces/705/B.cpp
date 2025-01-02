#include <iostream>
using namespace std;

int main(){
	int n,i,sum=0,a; 
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		sum+=a-1; 
		if(sum%2==0) cout<<2<<endl;
		else cout<<1<<endl;
	}
}