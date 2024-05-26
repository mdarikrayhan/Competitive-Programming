#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
#define All(x) (x).begin(),(x).end()
#define len(x) (int) (x).size()
#define pb push_back

const int N = 1e5 + 7;
bool pr[N], match[N];
int n;

int32_t main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<pii> ans;
	cin >> n;
	for (int i = 2; i <= n; i++)
		if (!pr[i]) 
			for (int j = 2 * i; j <= n; j += i) 
				pr[j] = true;
	for (int i = n; i >= 2; i--) 
		if (!pr[i]) {
			vector<int> vec;
			for (int j = i; j <= n; j += i)
				if (!match[j])
					vec.pb(j);
			if (len(vec) == 1)
				continue;
			swap(vec[1], vec[len(vec) - 1]);
			for (int k = 1; k < len(vec); k += 2) {
				match[vec[k]] = match[vec[k - 1]] = true;
				ans.pb({vec[k], vec[k - 1]});
			}
		}
	cout << len(ans) << '\n';
	for (auto [a, b]: ans)
		cout << a << ' ' << b << '\n';
	return 0;
}
