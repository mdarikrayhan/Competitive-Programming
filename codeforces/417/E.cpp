#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);
	a[0] = 3;
	for(int i=1; i<=n-2; i++) a[i] = 2;
	if(n > 1) a[n-1] = 2 * n;

	b[0] = 3;
	for(int i=1; i<=m-2; i++) b[i] = 2;
	if(m > 1) b[m-1] = 2 * m;

	for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << a[i] * b[j] << " ";
        }
        cout << "\n";
    }
}
