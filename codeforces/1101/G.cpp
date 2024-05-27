//   you're already the best
//             _
//   ^ ^      //
// >(O_O)<___//
//   \ __ __  \
//    \\ \\ \\\\
//
#include <bits/stdc++.h>

using namespace std;

const int N=200010;

int n,ans;
int a[N],bs[35];

void insert(int x){
	for(int i=30;i>=0;i--){
		if((x>>i)&1){
			if(!bs[i]){
				ans++;
				bs[i]=x;
				return;
			}
			else x=bs[i]^x;
		}
	}
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
	
	if(a[n]==0){
		cout<<-1<<endl;
		return;
	}
	
	for(int i=1;i<=n;i++) insert(a[i]);
	
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return (0-0);
}
