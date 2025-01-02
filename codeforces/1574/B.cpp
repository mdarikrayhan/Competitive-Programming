#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,n;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>n;
		puts(n>=max(max(a,b),c)*2-a-b-c-1&&n<=a+b+c-3?"YES":"NO");
	}
	return 0;
}