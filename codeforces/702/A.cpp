#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ll t; cin>>t;
	ll a[t];
	ll cont=1, max=1;
	for(ll i=0;i<t;i++) cin>>a[i];
	for(ll i=0;i<t-1;i++) {
		if(a[i]<a[i+1]) cont++;
		else cont=1;
		max=cont>max?cont:max;
	}
	cout<<max<<endl;
	return 0;
}
