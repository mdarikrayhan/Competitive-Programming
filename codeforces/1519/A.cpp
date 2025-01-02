#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> ii;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define db long double
const int inf = 1e18;
const int MAX = 2e5;
const db EPS = 1e-9;
int a, b, x;

void solve(){
	cin >> a >> b >> x;
	if( a > b ) swap(a, b);
	int c1 = b / a + (b % a != 0);
	if( c1-1 <= x ) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	cin >> tt;
	while( tt-- ){
		solve();
	}
	return 0;
}