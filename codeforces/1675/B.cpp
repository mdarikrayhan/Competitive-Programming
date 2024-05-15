#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==1){
		cout<<0<<endl;
		return;
	}
	int ans=0;
	for(int i=n-2;i>=0;i--){
		while(a[i]&&a[i]>=a[i+1]){
			ans++;
			a[i]/=2;
		}
		if(a[i]==a[i+1]){
			cout<<-1<<endl;
			return;
		}
	}
	cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
