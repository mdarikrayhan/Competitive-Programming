#include<iostream>
using namespace std;
main(){
	int t,n,a[100003],i;
	const string s[] = {"First","Second"};
	for(cin>>t;t--;){
		for(cin>>n,i=0;i<n;) cin>>a[i++];
		for(i=0;i<n&&a[i]<2;++i);
		cout<<s[i+(i<n?0:1)&1]<<'\n';
	}
}