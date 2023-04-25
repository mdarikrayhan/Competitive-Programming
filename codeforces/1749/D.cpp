#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P=998244353;
int main(){
	ll n,m,ans=0,mul=1,nm=1,tmp=1;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		if(mul<=m&&__gcd(mul,i)==1)mul*=i;
		nm=m%P*nm%P;tmp=(m/mul)%P*tmp%P;
		ans=(ans+nm-tmp+P)%P;
	}
	cout<<ans<<endl;
	return 0;
}