// LUOGU_RID: 160487742
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;

int a[N];

inline void fake_main(){
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;){
		int tmp=i;
		while(a[tmp]==a[i]&&tmp<=n) tmp++;
		if(tmp>n){
			ans=max(ans,tmp-i);
			break;
		}
		int j=n,cnt=1;
		while(tmp<=j){
			j=upper_bound(a+tmp,a+j,(a[i]+a[j])/2)-a-1;
			if(tmp>j) break; cnt++;
		}
		ans=max(ans,cnt+tmp-i);
		i=tmp;
	}
	cout<<n-ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) fake_main();
}
