// LUOGU_RID: 160070137
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
long long ans,n,a[MAX];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%lld",a+i);
	}
	ans=(a[1]-1+1)*(n-a[1]+1);
	for(int i=2;i<=n;++i){
		if(a[i]>=a[i-1]){
			ans+=(a[i]-a[i-1])*(n-a[i]+1);
		}
		else{
			ans+=(a[i]-1+1)*(a[i-1]-a[i]);
		}
	}
	cout<<ans; 
} 