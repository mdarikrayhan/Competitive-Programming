#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define str string
#define all(x) x.begin(),x.end()
#define fr(i,n) for(ll i=0;i<n;i++)
using namespace std;
int main(){
	ll n,k; cin>>n>>k;
	ll ans1=-1,ans2=INT_MAX;
	for(int i=0;i<n;i++){
		int x,y; cin>>x>>y;
		if(min(x,y)>ans1){
			ans1=min(x,y);
		}
		if(max(x,y)<ans2){
			ans2=max(x,y);
		}
	}
	if(ans2<ans1){
		cout<<-1<<endl;
	}else {
		ll jwb=INT_MAX;
		for(int i=ans1;i<=ans2;i++){
			int temp=abs(i-k);
			if(jwb>temp){
				jwb=temp;
			}
		}
		cout<<jwb<<endl;
	}
	return 0;
}
