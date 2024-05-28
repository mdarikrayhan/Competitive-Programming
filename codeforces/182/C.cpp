#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for(int i = 0; i < (n); ++i)
#define rFor(i, n) for(int i = (n - 1); i >= 0; i--)
#define FoR(i, st, ed) for(int i = (st); i < (ed); ++i)
#define rFoR(i, st, ed) for(int i = (ed) - 1; i >= (st); --i)
#define FOR(i, st, ed) for(int i = (st); i <= (ed); ++i)
#define rFOR(i, st, ed) for(int i = (ed); i >= (st); --i)
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(a) a.begin(),a.end()
using i64 = long long;
const int INF  = 1e9+7;
const int MAX = 1e5;
const int mod  = 1e9+7;
const double eps = 0.001;
//--------------------------------------------
void solve() {
	int n, len;
	cin >> n >> len;
	vector<int> a(n);
	i64 ans = -1e18;
	For(i, n) cin >> a[i];
	int k;
	cin >> k;

	auto work = [&](){
		vector<i64> sum(n - len + 1);
		For(i, len) sum[0] += a[i];
		FOR(i, 1, n - len) sum[i] = sum[i - 1] - a[i - 1] + a[i + len - 1];
		multiset<int> Use, nUse;
		i64 now = 0;
		For(i, len) if(a[i] < 0) Use.insert(-a[i] * 2), now += -a[i] * 2;
		while(Use.size() > k){
			nUse.insert(*Use.begin());
			now -= *Use.begin();
			Use.erase(Use.begin());
		}
		ans = max(ans, now + sum[0]);
		FOR(i, 1, n - len){
			if(a[i - 1] < 0){
				if(Use.count(-a[i - 1] * 2)){
					now -= -a[i - 1] * 2;
					Use.erase(Use.find(-a[i - 1] * 2));
				}
				else{
					nUse.erase(nUse.find(-a[i - 1] * 2));
				}
			}
			if(a[i + len - 1] < 0) nUse.insert(-a[i + len - 1] * 2);
			while(Use.size() > k - 1){//预留
				nUse.insert(*Use.begin());
				now -= *Use.begin();
				Use.erase(Use.begin());
			}			
			while(Use.size() < k && !nUse.empty()){
				Use.insert(*prev(nUse.end()));
				now += *prev(nUse.end());
				nUse.erase(prev(nUse.end()));				
			}
			ans = max(ans, now + sum[i]);
		}
	};

	work();
	For(i, n) a[i] = -a[i];
	work();
	cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);

	int t = 1;
	//cin >> t;
	while (t--)solve();
	return 0;
}
/*
*/