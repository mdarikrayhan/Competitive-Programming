#include <bits/stdc++.h>
#define allr v.rbegin(), v.rend()
#define sllr s.rbegin(), s.rend()
#define all v.begin(), v.end()
#define sll s.begin(), s.end()
#define pii pair <int, int>
#define int long long
#define pb push_back
#define pp pop_back
#define sc second
#define fr first
using namespace std;
const int N=1e3+7, INT=1e6+7, INf=1e9+7, INF=INT64_MAX;
signed main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, i, j;
	cin >> n;
	if (n<3) {
		cout << -1;
		exit(0);
	}
	for (i=n; i>0; i--) {
		cout << i << ' ';
	}
}