#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define len(v) (int)v.size() 
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef Raptor
#include "debug.h"
#else
#define debug(...) 1
#define imie(...) 1;
#endif

void solve(){
	int n; cin>>n;
	ll sum = 0;
	vector<pair<ll,ll>> a(n); 
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		sum += a[i].first;
		a[i].second = i;
	}
	sort(all(a));
	ll ans = -1e16;	
	auto chk = [&](int neg){
		if(neg != (n/2) and neg != ((n+1)/2)) return true;
		vector<int> idx;
		for(int i=0;i<neg;i++) idx.pb(a[i].second);
		sort(all(idx));
		for(int i=1;i<len(idx);i++){
			if(idx[i]-idx[i-1] == 2) continue;
			return true;
		}
		if(len(idx)==0)	return true;
		if(len(idx) == 1 and idx[0] != 1) return true;
		ll cur = sum;
		for(int i=0;i<neg-1;i++) cur -= 2LL*a[i].first;
		cur -= 2LL*a[neg].first;
		ans = max(ans,cur);
		return false;
	};
	ll cur = 0;
	for(int i=0;i<=n;i++){
		if(i >= 1) cur += a[i-1].first;
		if((n + i)%3 != 1) continue;
		if(!chk(i)) continue;
		ans = max(ans,sum - 2LL*cur);
	}
	cout<<ans<<"\n";
	
}
int main(){
	ios::sync_with_stdio(false);
	solve();
	
	return 0;
}
