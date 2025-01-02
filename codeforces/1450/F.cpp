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
	vector<int> a(n),occ(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i];
		occ[a[i]]++;
	}
	if(*max_element(all(occ)) > int((n+1)/2)){
		cout<<-1<<"\n";
		return;
	}
	int cnt = 0;
	int prev = 0;
	vector<int> sin(n+1),dob(n+1);
	for(int i=0;i<n-1;i++){
		if(a[i] == a[i+1]){
			cnt++;
			if(a[i]==a[prev]){
				dob[a[i]]++;
			}
			else{
				sin[a[i]]++;
				sin[a[prev]]++;
			}
			prev = i+1;
		}
	}
	if(a[n-1] == a[prev]){
		dob[a[n-1]]++;
	}
	else{
		sin[a[prev]]++;
		sin[a[n-1]]++;
	}
	int ans = cnt;
	for(int i=1;i<=n;i++){
		int d = dob[i],s = sin[i];
		int r = cnt + 1 - dob[i] - sin[i];
		ans = max(ans,cnt + d - (r + 1));  
	}
	cout<<ans<<"\n";
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
