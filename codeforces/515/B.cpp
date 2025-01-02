#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define stp(n,x)  fixed << setprecision(x) << n

using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	int b[n] = {}, g[m] = {};
	int boy; cin >> boy;
	while(boy--){
		int x; cin >> x;
		b[x] = 1;
	}
	int girl; cin >> girl;
	while(girl--){
		int x; cin >> x;
		g[x] = 1;
	}
	int r = lcm(n, m);
	for(int i = 0; i < 5e6; ++i){
		int i1 = i % n, i2 = i % m;
		//cout << i << ' ' << max(b[i1], g[i2]) << endl;
		b[i1] = max(b[i1], g[i2]);
		g[i2] = max(b[i1], g[i2]);
	}
	//for(int x : b) cout << x << ' '; cout << endl;
	//for(int x : g) cout << x << ' '; cout << endl;
	for(int i = 0; i < n; ++i){
		if(!b[i]){
			cout <<"No";
			return;
		}
	}
	for(int i = 0; i < m; ++i){
		if(!g[i]){
			cout << "No";
			return;
		}
	}
	cout << "Yes";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
}

