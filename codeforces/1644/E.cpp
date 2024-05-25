#include <bits/stdc++.h>

using namespace std;

#define int long long 
const int N = 2e5 + 10;

int n;
string str;

void solve()
{
	cin >> n >> str;
	int x = 1, y = 1;
	for(int i = 0; i < str.size(); i ++)
		if(str[i] == 'D') x ++;
		else y ++;
	
	int num_x = n - x, num_y = n - y;
	int ans = str.size() + 1;
	for(int i = 0, num = 1; i < str.size(); i ++)
		if(str[i] == 'R')
		{
			ans += (x - num + 1) * (n - y);
			break;
		}
		else num ++;
	
	for(int i = 0, num = 1; i < str.size(); i ++)
		if(str[i] == 'D')
		{
			ans += (y - num + 1) * (n - x);
			break;
		}
		else num ++;
	
	if(x > 1 && y > 1) ans += (n - x) * (n - y);
		
	cout << ans << "\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t = 0;
	cin >> t;
	
	while(t --) solve();
	
	return 0;
}