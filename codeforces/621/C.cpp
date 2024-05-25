#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()
const ll N = 2e5 + 9;

void test_case(){
  ll n , p;
  cin >> n >> p;
  ll l[n] , r[n];
  for(int i = 0 ; i < n ; i++){
    cin >> l[i] >> r[i];
  }
  cout << setprecision(12) << fixed;
  lld ans = 0;
  for(int i = 0 ; i < n ; i++){
    ll nxt = (i + 1)%n;
    lld tot = lld(r[i]/p - (l[i] - 1)/p)/lld(r[i] - l[i] + 1) + lld(r[nxt]/p - (l[nxt] - 1)/p)/lld(r[nxt] - l[nxt] + 1);
    tot -= lld(r[i]/p - (l[i] - 1)/p)/lld(r[i] - l[i] + 1) * lld(r[nxt]/p - (l[nxt] - 1)/p)/lld(r[nxt] - l[nxt] + 1);
    ans += tot*2000;
  }
  cout << ans << endl;
}
int32_t  main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	// cin >> t;
	for(int i = 0 ; i < t ; i++) {
		test_case();
	}
}