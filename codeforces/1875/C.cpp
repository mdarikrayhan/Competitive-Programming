#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=1e6+5;
const int mod=998244353;
#define lc p<<1
#define rc p<<1|1

int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return res;
}
void solve() {
	int n,m;
	cin>>n>>m;
	
	n%=m;
	int a=n/__gcd(n,m);
	int b=m/__gcd(n,m);
	
//	cout<<b<<endl;
	if(__builtin_popcount(b)!=1)cout<<"-1"<<endl;
	else{
		int res=m*__builtin_popcount(a);
		while(a){
			int x=a&(-a);
			res-=m*x/b;		
			a-=x;
		}
		cout<<res<<endl;
	}
}
signed main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	cin>>T;
	while(T--)
		solve();
}