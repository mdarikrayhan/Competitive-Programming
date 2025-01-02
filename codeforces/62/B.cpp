#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int> v[30];
string s;
signed main(){
	scanf("%lld%lld", &n, &m);
	cin >> s;
	for(int i = 0; i < s.size(); i++)	v[s[i] - 'a'].emplace_back(i);
	while(n--){
		int ans = 0;
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			int minn = 2e18;
			if(v[s[i] - 'a'].size() == 0){
				ans += s.size();
				continue;
			}
			for(auto j : v[s[i] - 'a'])	minn = min(minn, abs(j - i));
			ans += minn;
		}
		printf("%lld\n", ans);
	}
	return 0;
}