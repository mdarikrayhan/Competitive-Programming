#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int a[N];
int n;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];

	sort(a+1,a+1+n);

	int min1=a[1];
	if(min1&1){
		cout<<"YES"<<"\n";
		return;
	}

	else{
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]&1){
				flag=false;
			}
		}
		if(flag)cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
		return;
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