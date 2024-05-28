#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
int phiq(int n){
	int ans=n;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans/n*(n-1);
    return ans;
}
void solve() {
    int n,k;
    cin>>n>>k;
    if(k==1)    {cout<<3<<'\n';return ;}
    vector<bool> isprime(n+1);
    vector<int> ip;
    vector<int> phi(n+1);
    for(int i=2;i<=n;i++){
        if(!isprime[i]){
            ip.push_back(i);
            phi[i]=i-1;
        }
        for(auto j:ip){
            if(1ll*i*j<=n){
                isprime[i*j]=1;
                if(i%j!=0) phi[i*j]=phi[i]*(j-1);
                else {phi[i*j]=phi[i]*j;break;}
            }
            else break;
        }
    }
    sort(phi.begin()+3,phi.end());
    ll ans=2;
    for(int i=3;i<k+3;i++) ans+=phi[i];
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}
