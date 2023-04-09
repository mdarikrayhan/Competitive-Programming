#include <iostream>
#include <set>
using namespace std;
int n, q, k, i, qq, num, a[1000005];
set<int> st;
main() {
	cin >> n >> k >> q;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 0; i < q; i++)
	{
		cin >> qq >> num;
		if (qq == 2) {
			if (st.count(a[num]) == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
		{
			st.insert(a[num]);
			if (st.size() > k) {
				st.erase(st.begin());
			}
		}
	}
}