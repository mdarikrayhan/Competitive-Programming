#include<bits/stdc++.h>
using namespace std;
long long n,j,k,sm;
map<long long,long long>mp;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		sm+=k;
		mp[sm]++;
		j=max(j,mp[sm]);
	}
	printf("%lld",n-j);
	return 0;
}