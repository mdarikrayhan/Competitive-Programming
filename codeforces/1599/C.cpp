#include<bits/stdc++.h>
#define int long long

using namespace std;

int nCr(int n , int r){
	if(r>n) return 0;
	if(r==0) return 1;
	int ans = 1;
	for (int i = 0; i < r; ++i)
		ans *= (n-i);
	for (int i = 1; i <=r; ++i)
		ans /= i;
	return ans;
}

void solve(){
	int n ;
	double p  ;
	cin>>n;
	cin>>p;
	int prob = (int)(p*10000 + 0.5);
	for (int x = 0; x <= n; ++x)
	{
		double ans = 0;
		ans += (double)nCr(x,3)/(double)nCr(n,3);
		ans += (double)(nCr(x,2) * nCr(n-x,1))/(double)(nCr(n,3));
		ans += (double)(nCr(x,1) * nCr(n-x,2))/(double)(nCr(n,3)*2);
		int f = (int)(ans*10000 + 0.5);
		//cout<<x<<" "<<ans<<endl;
		if(ans>=p){
			cout<<x<<endl;
			return;
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}