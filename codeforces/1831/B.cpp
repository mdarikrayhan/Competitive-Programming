#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
typedef vector<vector<int>> matrix;
void solve(){
	int n,ans=1;
	cin>>n;
	vector<int> a(n),b(n),ma(2*n+1),mb(2*n+1),m(2*n+1,1);
	for(int i=0; i<n; i++){
		cin>>a[i];
		ma[a[i]] = 1;
	}
	for(int i=0; i<n; i++) {
		cin>>b[i];
		mb[b[i]] = 1;
	}
	
	for(int i=0; i<n-1; i++){
		if(a[i] == a[i+1]) m[a[i]]++;
		else{
			ma[a[i]] = max(ma[a[i]],m[a[i]]);
			m[a[i]] = 1;
		}
	}
	if(a[n-1] == a[n-2]) ma[a[n-2]] = max(ma[a[n-2]],m[a[n-2]]);
	
	for(int i=1; i<=2*n ; i++) m[i] = 1;
	
	for(int i=0; i<n-1; i++){
		if(b[i] == b[i+1]) m[b[i]]++;
		else{
			mb[b[i]] = max(mb[b[i]],m[b[i]]);
			m[b[i]] = 1;
		}
	}
	if(b[n-1] == b[n-2]) mb[b[n-2]] = max(mb[b[n-2]],m[b[n-2]]);
	
	for(int i=1; i<=2*n; i++){
		ans = max(ans, ma[i] + mb[i]);
	}
	cout<<ans<<endl;
}
 
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T = 1;
	cin>>T;
	while(T--)
	solve();
	return 0;
}
