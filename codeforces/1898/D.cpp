#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <chrono>
#include <iomanip>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <stack>
#include <bitset>
#include <deque>
#include <fstream>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
const ll inf = 1e9 + 7;

multiset<int> cc[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<ll> aa(n), bb(n);
		ll Ans = 0, dd = 0;
		for(int i = 0; i < n; i++) {
			cin >> aa[i];
		}
		for(int i = 0; i < n; i++) { cin >> bb[i]; Ans += abs(aa[i] - bb[i]); }
		vector<vector<ll> > cc(4, vector<ll> (n + 1));
		for(int i = 0; i < n; i++) {
			cc[0][i] = (aa[i] - bb[i]) - abs(aa[i] - bb[i]);
			cc[1][i] = -1 * (aa[i] + bb[i]) - abs(aa[i] - bb[i]);
			cc[2][i] = (aa[i] + bb[i]) - abs(aa[i] - bb[i]);
			cc[3][i] = (bb[i] - aa[i]) - abs(aa[i] - bb[i]);
		}
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < 4; j++) {
				cc[j][i] = max(cc[j][i], cc[j][i - 1]);
			}
		}
		for(int i = 1; i < n; i++) {
			dd = max(dd, cc[0][i - 1] + (aa[i] - bb[i]) - abs(aa[i] - bb[i]));
			dd = max(dd, cc[1][i - 1] + (aa[i] + bb[i]) - abs(aa[i] - bb[i]));
			dd = max(dd, cc[2][i - 1] - (aa[i] + bb[i]) - abs(aa[i] - bb[i]));
			dd = max(dd, cc[3][i - 1] + (bb[i] - aa[i]) - abs(aa[i] - bb[i]));
		}
		cout << Ans + dd<<"\n";

	}
}