#include <bits\stdc++.h>
#define vector deque
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
#define yes cout << "Yes"
#define no cout << "No"
#define AA 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve()
{
	ll n, m, i, j, ans = 0, x;
	cin >> n >> m;
	char a[n + 12][m + 12];
	map <ll, ll> mp;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			cin >> a[i][j];
			if (a[i][j] == '1')mp[j]++;
		}
	}
	for (i = 1; i <= n; i++){
		bool ok = true;
		for (j = 1; j <= m; j++){
			if (a[i][j] == '1')mp[j]--;
		}
		for (j = 1; j <= m; j++){
			if (!mp[j]){
				ok = false;
				break;
			}
		}
		if (ok){
			yes;
			return;
		}
		for (j = 1; j <= m; j++){
			if (a[i][j] == '1')mp[j]++;
		}
	}
	no;
}
main()
{
	int t = 1;
	AA;
	// cin >> t;
	while (t --> 0){
		solve();
		cout << "\n";
	}
}