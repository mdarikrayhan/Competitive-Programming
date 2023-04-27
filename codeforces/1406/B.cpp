#include<bits/stdc++.h>
int64_t t,n,a[200007],i,j,p,s;
main(){
	using namespace std;
	for(cin>>t;t--;cout<<s<<'\n'){
		for(cin>>n,i=0;i<n;)cin>>a[i++];
		for(sort(a,a+n),s=-1e18,j=0;j++<5;s=max(s,p)){
			for(i=0,p=1;i<5-j;i++) p*=a[i];
			for(i=n;i>n-j;) p*=a[--i];
		}
	}
}