#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
int main(){
	int T; scanf("%d", &T);
	while (T--){
		int k, n;
		ll ans = 0;
		string s; cin >> k >> s;
		n = s.size();
		vector<int> v;
		stack<int> stk;
		for (int i = 0; i < n; i++){
			if (s[i] == '(') stk.push(i);
			else{
				ans += (i - stk.top() - 1) / 2;
				v.pb((i - stk.top() - 1) / 2);
				stk.pop(); 
			}
		}
		sort(v.begin(), v.end());
		while (v.size() > 0 && k--){
			ans -= *v.rbegin(); v.pop_back();
		}
		printf("%lld\n", ans);
	}
	return 0;
}