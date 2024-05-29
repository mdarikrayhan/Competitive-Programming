// LUOGU_RID: 157603129
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, a[300010], v[300010], dp[300010];
vector<int> res, ther;

void dece(int ind){
	int cnt = min(a[ind], a[ind + 1]);
	if(cnt)
		res.push_back(ind);
	a[ind] -= cnt, a[ind + 1] -= cnt;
}

signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		int F = dp[max(0ll, i - 2)] + a[i], S = dp[max(0ll, i - 3)] + max(a[i], a[i - 1]);
		dp[i] = min(F, S), v[i] = (dp[i] != F ? 1 : 0);//v[i] : whether there are two 0s before i, or there's one
	}
	for(int i = (dp[n - 1] < dp[n] ? n - 1 : n); i > 0; i -= 2 + v[i])//the 2-sized spaces
		ther.push_back(i);
	ther.push_back(0), reverse(ther.begin(), ther.end());
	for(int i = 1; i < ther.size(); i++){
		if(v[ther[i]])
			dece(ther[i] - 1);
		dece(ther[i - 1] + 1), dece(ther[i]);
	}
	cout << res.size() << endl;
	for(int i : res)
		cout << i << endl;
	return 0;
}//////