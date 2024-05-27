// LUOGU_RID: 157044693
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n,k;
	cin>>n>>k;
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		ans++;
		int x;
		cin>>x;
		if(cnt-(i-1)*(n-i)*x<k) cout<<ans<<endl,n--,i--;
		else cnt+=x*(i-1);
	}
	return 0;
}
