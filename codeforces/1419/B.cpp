#include<iostream>
using namespace std;

int main(){
	int T;cin>>T;
	while(T--){
		long long n,ans=0,t=1;cin>>n;
		while((n-=(t*(t+1))/2)>=0) ans++,t=2*t+1;
		cout<<ans<<endl;
	}
}
    		     								 	     	