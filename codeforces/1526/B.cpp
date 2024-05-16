#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char maxs[200500];
char mins[200500];
void solve (){
	ll n;
	cin>>n;
	ll f=0;
	for(int i=0;i<11;i++){
		ll p=i*111;
		if(n-p<0)break;
		if((n-p)%11==0){
			f=1;
			break;
		}
	}
	if(f)cout<<"YES\n";
	else{
		cout<<"NO\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}