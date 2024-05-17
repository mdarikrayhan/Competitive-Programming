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
	str s, x = "";
	cin >> s;
	ll n = s.size(), i, l = -1, r = -1;
	vector <pair <ll, ll>> vc;
	for (i = 0; i < s.size(); i++){
		if (s[i] != 'a'){
			if (l == -1)l = i;
			r = i;
		}
		else if (l != -1){
			vc.pb({l, r});
			l = -1, r = -1;
		}
	}
	if (l != -1){
		vc.pb({l, n - 1});
	}
	if (vc.empty()){
		s.erase(s.size() - 1, 1);
		s += 'z';
		cout << s;
		return;
	}
	for (i = vc.front().fi; i <= vc.front().se; i++){
		s[i] = char(int(s[i]) - 1);
	}
	cout << s;
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