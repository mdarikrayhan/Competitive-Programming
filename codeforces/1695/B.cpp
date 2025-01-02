#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

ll n, a[59], i,minn;
void solve()
{
	cin >> n;
	minn = 1;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] < a[minn])minn = i;
	}
	if (n % 2 == 0)
	{
		if(minn%2!=0)cout << "Joe" << "\n";
		else cout << "Mike" << "\n";
	}
	else cout << "Mike" << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll T;
	cin >> T;
	//T = 1;
	while (T--)
		solve();
	return 0;
}