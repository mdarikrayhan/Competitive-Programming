#include<bits/stdc++.h>
using namespace std;
using lli = long long;

lli n, m;
vector<lli> a,p;

void solve(){
	cin>>n;
	a.resize(n);
	for(lli i=0; i<n; i++) cin>>a[i];
	cin>>m;
	p.resize(m);
	for(lli i=0; i<m; i++){
		cin>>p[i];
		// p[i] = (n-p[i]);
	}

	for(lli i=1; i<m; i++){
		p[i] += p[i-1];
	}
	// cout<<p[m-1]<<endl;
	lli idx = (p[m-1]%n);

	cout<<a[idx]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}