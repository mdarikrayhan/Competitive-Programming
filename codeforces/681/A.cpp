#include <bits/stdc++.h>
using namespace std;
#define ar array
#define int long long
#define double long double
#define pb push_back
#define mkp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define INF 1e18
#define ve vector
#define HungryBoy ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define P pair
#define fori(a, n) for (int i = a; i < n; i++)
#define forj(a, n) for (int j = a; j < n; j++)
#define printv(v) for ( auto i : v) { cout << i << " ";}
void debug(string add, auto obj){
cout << add << " " << obj << endl;}
void solve();

signed main()
{
 HungryBoy;

 int tc = 1;
//  cin >> tc;
 for (int t = 1; t <= tc; t++)
 {
 // cout << "Case #" << t << ": ";
 solve();
 }
}

void solve()
{
	int n;
	cin >> n;
	bool ans = 0; 
	while (n--)
	{
		string s;
		cin >> s;
		int b, a;
		cin >> b >> a; 
		if ( a > b && b>=2400  ){
			ans = 1; 

		}
	}
	if( ans )
		YES; 
	else
		NO; 
}