// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'
#define fi first 
#define se second
#define pb push_back
#define PII pair<int, int>

using namespace std;

const int N = 1e6 + 10;
const int mod = 1e9 + 7; 

void solve()
{
	int a, b;
	cin >> a >> b;
	int ans = 1;
	for(int i = 1; i * i <= a; i++)
	{
		if(a % i == 0) {
			if(b <= i) ans = max(ans, a / i);
			if(b <= a / i) ans = max(ans, i);
		}
	}
	cout << ans << endl;
}

signed main(){
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}