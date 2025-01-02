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
	vector<vector<int>> a(n,vector<int> (n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c; cin>>c;
			a[i][j] = c-'0'; 
		}
	}
	vector<int> ans(10);
	for(int d=0;d<10;d++){
		vector<pair<int,int>> p;
		for(int i=0;i<n;i++){
			vector<int> x;
			for(int j=0;j<n;j++){
				if(a[i][j] == d) x.pb(j);
			}
			if(len(x)==0) continue;
			else if(len(x)==1){
				p.pb({i,x[0]});
			}
			else{
				p.pb({i,x[0]});
				p.pb({i,x.back()});
				ans[d] = max(ans[d],(x.back()-x[0])*max(i,n-i-1));
			}
		}
		for(int i=0;i<len(p);i++){
			for(int j=i+1;j<len(p);j++){
				int h = abs(p[i].second - p[j].second);
				int b = max({p[i].first,p[j].first,n-1-p[i].first,n-1-p[j].first}); 
				ans[d] = max(ans[d],h*b);
			}
		}
		
		p.clear();
		for(int j=0;j<n;j++){
			vector<int> x;
			for(int i=0;i<n;i++){
				if(a[i][j] == d) x.pb(i);
			}
			if(len(x)==0) continue;
			else if(len(x)==1){
				p.pb({x[0],j});
			}
			else{
				p.pb({x[0],j});
				p.pb({x.back(),j});
				ans[d] = max(ans[d],(x.back()-x[0])*max(j,n-j-1));
			}
		}
		for(int i=0;i<len(p);i++){
			for(int j=i+1;j<len(p);j++){
				int h = abs(p[i].first - p[j].first);
				int b = max({p[i].second,p[j].second,n-1-p[i].second,n-1-p[j].second}); 
				ans[d] = max(ans[d],h*b);
			}
		}
	}
	for(int i=0;i<10;i++) cout<<ans[i]<<" ";
	cout<<"\n";
	
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
