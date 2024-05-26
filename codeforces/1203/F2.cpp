// LUOGU_RID: 159740076
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e5+10;
const int mod=1e9+7;
int dp[N];
void solve(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> a,b;
	for(int i=1;i<=n;i+=1){
		int x,y;
		cin>>x>>y;
		if(y>=0) a.push_back({x,y});
		else b.push_back({x,-y});
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),[&](auto x,auto y){
		return x.first-x.second>y.first-y.second;
	});

	int ans=0;
	for(auto [x,y]:a){
		if(m>=x) ans+=1,m+=y;
	}
	multiset<int> s;
	for(auto [x,y]:b){
		if(m>=x&&m>=y){
			m-=y;
			s.insert(y);
		}else if(s.size()&&(*s.rbegin()+m)>=max(x,y)&&(*s.rbegin()>y)){
			m+=*s.rbegin();
			m-=y;
			s.erase(s.lower_bound(*s.rbegin()));
			s.insert(y);
		}
	}
	ans+=s.size();
//	if(ans==n){
//		cout<<"YES"<<endl;
//	}else{
//		cout<<"NO"<<endl;
//	}
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