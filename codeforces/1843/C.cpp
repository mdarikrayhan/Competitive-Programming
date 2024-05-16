#include<bits/stdc++.h>
using namespace std;
long long t,n;
int main(){
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
		long long ans=0;
		while(n){
			ans+=n;
			n>>=1;
		}
		cout<<ans<<"\n";
	}
}