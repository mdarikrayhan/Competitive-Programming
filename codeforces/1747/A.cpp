#include<iostream>
using namespace std;
int main(){
	int t,n,x;cin>>t;
	while(t--){
		cin>>n;long long s=0;
		while(n--)cin>>x,s+=x;
		cout<<abs(s)<<"\n";
	}
}