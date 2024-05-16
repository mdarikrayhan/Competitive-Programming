#include <bits/stdc++.h>

using namespace std;


int n;

void solve()
{
	cin >> n;
	if(n % 2 == 0)
	{
		for(int i = 1; i <= n - 2; i ++)
			if(i & 1) cout << i + 1 << " ";
		else cout << i - 1 << " ";
		cout << n - 1 << " " << n << "\n";
	}
	else
	{
		cout << "1 2 3 ";
		for(int i = 4; i <= n - 2; i ++)
			if(i & 1) cout << i - 1 << " ";
			else cout << i + 1 << " ";
		
		cout << n - 1 << " " << n << "\n";
	}
	
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