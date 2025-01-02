
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).begin()+1+n
#define ls id << 1
#define rs id << 1 | 1

const int inf = 0x3f3f3f3f3f3f3f3f;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int>a(n+5), pre(n+5), cnt(n+5);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		pre[i] = a[i] + pre[i-1];
		cnt[i] = cnt[i-1] + (a[i] == 0);
	}

	if(k*cnt[n] < abs(pre[n])) {
		cout << "-1\n";
		return;
	}

	int nd = -pre[n];

	int ans = 0;

	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			int ct1 = cnt[j] - cnt[i-1];
			int ct2 = cnt[n] - ct1;
			int sum = pre[j] - pre[i-1];
			int mx = min(nd+k*ct2, k*ct1);
			int mn = max(nd-k*ct2, -k*ct1);
			ans = max(ans, abs(sum + mx) + 1);
			ans = max(ans, abs(sum + mn) + 1);
		}
	}

	cout << ans << endl;
}

signed main(){

	IO;
	int t = 1;
	//cin >> t;
	while(t--) solve();

	return 0;
}
