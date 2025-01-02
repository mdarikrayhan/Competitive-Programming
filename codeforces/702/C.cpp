#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 102
/*
freopen("pairup.in","r",stdin);
freopen("pairup.out","w",stdout);
*/

int32_t main() { 
	int n, m;
	cin >> n >> m;
	int c[n], t[m];
	for(int i=0; i<n; i++) cin >> c[i];		
	for(int i=0; i<m; i++) cin >> t[i];	

	int torre=0, ans=0LL;
	for(int i=0; i<n; i++) {
		while (abs(t[torre+1]-c[i]) <= abs(t[torre]-c[i]) && torre+1<m) torre++;
		ans=max(ans, abs(t[torre]-c[i]));	
	}
	cout << ans;
	return 0;
}
