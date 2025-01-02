#include<bits/stdc++.h>
#define skip continue
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
	cin >> t;
	while (t--)
    {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> dem(n + 1);
		int ans = 0;
		for (auto &it : a)
        {
			cin >> it;
			dem[it]++;
		}
		for (int l = 0; l < n; l++)
		{
			int sum = 0;
			for (int r = l; r < n; r++)
			{
				sum += a[r];
				if (l == r) continue;
				if (sum <= n)
				{
					ans += dem[sum];
					dem[sum] = 0;
				}
			}
		}
		cout << ans <<'\n';
	}
    return 0;
}
