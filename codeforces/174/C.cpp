#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, cnt, a[N], s[N];
vector<pair<int, int> > ans;
signed main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)	scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++){
		if(a[i - 1] > a[i]){
			for(int j = a[i]; j < a[i - 1]; j++)	ans.emplace_back(make_pair(s[cnt--], i - 1));
		}else{
			for(int j = a[i - 1]; j < a[i]; j++)	s[++cnt] = i;
		}
	}
	while(cnt)	ans.emplace_back(make_pair(s[cnt--], n));
	printf("%lld\n", (int)ans.size());
	for(auto i : ans)	printf("%lld %lld\n", i.first, i.second);
	return 0;
}