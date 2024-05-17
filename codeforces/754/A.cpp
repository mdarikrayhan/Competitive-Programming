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
#define yes cout << "YES"
#define no cout << "NO"
#define AA 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve()
{
	ll n, i, sum = 0, ok = 0;
	cin >> n;
	ll a[n + 12];
	vector <pair <ll, ll>> vc;
	for (i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
		if (a[i] == 0)ok++;
	}
	if (ok == n){
		no;
		return;
	}
	yes;
	cout << '\n';
	if (sum != 0){
		cout << "1\n1 " << n;
	}
	else {
		cout << "2\n";
		for (i = 1; i <= n; i++){
			if (a[i] != 0){
				break;
			}
		}
		cout << "1 " << i << '\n';
		cout << i + 1 << ' ' << n; 
	}
}
main()
{
	// cout << fixed << setprecision(10);
	int t = 1;
	AA;
	// cin >> t;
	while (t --> 0){
		solve();
		cout << "\n";
	}
}