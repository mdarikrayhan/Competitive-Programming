#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
typedef long long LL;
using namespace std;
const int mod = 998244353;
const double eps = 1e-6;
const int N = 1e6+10;

int n, m, a[210][210], vis[210], fz[210];

bool check(int x) {
	int f = 0;
	for(int i = 1; i < n; i ++) {
		vector<int> b(m);
		for(int j = 0; j < m; j ++) {
			b[j] = vis[j] ? !a[i][j] : a[i][j];
		}
		if(!x) fz[i] = !b[0];
		else fz[i] = f ? !b[0] : b[0];
		for(int j = 0; j < m; j ++) {
			if(j && b[j] != b[j-1]) f ++;
		}
	}
	return (x && f <= 1) || (!x && !f);
}

signed main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			cin>>a[i][j];
		}
	}
	for(int i = 0; i <= m; i ++) {
		for(int j = 0; j < m; j ++) {
			fz[j] = 0;
			vis[j] = j < i ? a[0][j] : !a[0][j];
		}
		if(check(i == m)) {
			cout<<"YES\n";
			for(int j = 0; j < n; j ++) cout<<fz[j]<<(j == n-1 ? "\n" : "");
			for(int j = 0; j < m; j ++) cout<<vis[j]<<(j == m-1 ? "\n" : "");
			return 0;
		}
		for(int j = 0; j <= m; j ++) vis[j] ^= 1;
		fz[0] = 1;
		if(check(i == m)) {
			cout<<"YES\n";
			for(int j = 0; j < n; j ++) cout<<fz[j]<<(j == n-1 ? "\n" : "");
			for(int j = 0; j < m; j ++) cout<<vis[j]<<(j == m-1 ? "\n" : "");
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}


    	   	   	 	    		 			 		 		