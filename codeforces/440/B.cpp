// LUOGU_RID: 159788774
#include <bits/stdc++.h>
using namespace std;
long long k,n,a[20000002],ans; 
int main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		k+=a[i];
	}
	k/=n;
	for(long long i=1;i<=n;i++){
		a[i+1]+=(a[i]-k);
		ans+=abs(a[i]-k);
	}
	cout<<ans;
	return 0;
}
