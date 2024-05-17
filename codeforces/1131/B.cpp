//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e6+5;
const long long MOD=100000000;
long long a[N],q[N],b[N],n,k;

void solve(){
	long long x,y;
	long long xx,yy;
	cin>>n;
	long long ans=1;
	x=y=0;
	for(int i=1;i<=n;i++){
		cin>>xx>>yy;
		long long top=min(xx,yy);
		long long but=max(x,y);
		if(top>=but)ans+=top-but+1;
		if(x==y)ans--;
		x=xx;
		y=yy;
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
	//cin>>_;
	for(int i=1;i<=_;i++){
		solve();
	}
}  