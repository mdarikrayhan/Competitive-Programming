#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using PII=pair<ll,ll>;

const int N=2e6+10,M=210;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
ll n;
double dp[1<<19];
double a[19][19];
ll c(int n,int m){
	ll res=1;
	for(int i=1;i<=m;i++)
		res=res*(i+n-m)/i;
	return res;
}
void solve(){
	cout << fixed << setprecision(8);
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin >> a[i][j];
	}
	dp[(1<<n)-1]=1;
	for(int mask=(1<<n)-1;mask;mask--){
		for(int i=0;i<n;i++){
			if(mask>>i&1) continue;
			for(int j=0;j<n;j++){
				if(!(mask>>j&1)) continue;
				int nmask=mask|(1<<i);
				dp[mask]+=dp[nmask]*1.0/c(__builtin_popcount(nmask),2)*a[j][i];
//				cout << dp[nmask]*1.0/c(__builtin_popcount(nmask),2)*a[j][i] << "\n";
			}
		}
	}
	for(int i=0;i<n;i++) cout << dp[1<<i] << " ";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int O_o=1;
//	cin >> O_o;
	while(O_o--) solve();
	return 0;
}
//make it count
//开ll plz