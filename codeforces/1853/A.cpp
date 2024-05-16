#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
int a[N];
int n;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int min1=0x3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			min1=min(min1,abs(a[i]-a[j]));
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			cout<<0<<"\n";
			return;
		}
	}

	if(min1%2==0){
		cout<<min1/2+1<<"\n";
	}
	else {
		cout<<(min1+1)/2<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}