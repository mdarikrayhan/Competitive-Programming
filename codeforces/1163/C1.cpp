// LUOGU_RID: 158667405
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e3+10;
const int mod=1e9+7;
i64 a[N],b[N];
void solve(){
	int n,m;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	set<pair<double,double>> s;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			double k;
			if(a[i]==a[j]) k=-198191803;
			else k=1.0*(b[i]-b[j])/(a[i]-a[j]);
			double d;
			if(a[i]!=a[j])
			d=b[i]-k*a[i];
			else{
				d=a[i];
			}
			
			s.insert({k,d});
		}
	}
	double o=1e8,p=1e9+112;
	vector<pair<double,double>> dt;
	double eps=1e-8;
	for(auto [x,y]:s){
		if(abs(x-o)<=eps&&abs(y-p)<=eps){
			dt.push_back({x,y});
		}
		o=x,p=y;
	}
	for(auto [x,y]:dt) s.erase({x,y});
	for(auto [x,y]:s){
		for(auto [o,p]:s){
			if(abs(x-o)<=eps) continue;
			ans+=1;
		}
	}
	ans/=2;
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}