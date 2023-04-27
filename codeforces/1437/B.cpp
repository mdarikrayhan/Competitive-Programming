#include<iostream>
using namespace std;
int n,t,a;
string s;
main(){
	for(cin>>t;t--;cout<<(a+1)/2<<'\n')
		for(cin>>n>>s,a=0;--n;)a+=s[n-1]==s[n];
}