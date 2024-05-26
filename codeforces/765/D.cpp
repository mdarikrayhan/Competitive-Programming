// By the name of Allah, Most Gracious, and Merciful
#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5+5; 
vector<int>f(N), ff(N), g(N), h(N);
void solve() {
    int n, m=0;
    cin >> n;
    for(int i=1; i<=n; i++){
    	cin >> f[i];
	}
	for(int i=1; i<=n; i++){
		if(ff[f[i]]==0){
			m++;
			h[m]=f[i];
			ff[f[i]]=m;
		}
		g[i]=ff[f[i]];
	}
	for(int i=1; i<=m; i++){
		if(g[h[i]]!=i){
			cout << -1 << "\n";
			return;
		}
	}
	cout << m << "\n";
	for(int i=1; i<=n; i++){
		cout << g[i] << " ";
	}
	cout << "\n";
	for(int i=1; i<=m; i++){
		cout << h[i] << " ";
	}
	
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
