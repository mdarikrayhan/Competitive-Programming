#include<iostream>
#include<algorithm>
using namespace std;
long long a[250008],n,t,ans;
void solve(){
	long long maxn=a[1],mins=a[1],flag=2;
	for(int i=2;i<=n;i++){
		if(a[i]>maxn) {maxn=a[i];flag^0?flag=0,ans++:0;}
		if(a[i]<mins){mins=a[i];flag^1?flag=1,ans++:0;}
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		solve();
		reverse(a+1,a+1+n);
		solve();
		cout<<max(0ll,ans-1)<<endl;
	}
 }