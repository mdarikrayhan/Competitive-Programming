#include<bits/stdc++.h>
#define taskname "1499D"
using namespace std;
typedef long long ll;
const int lim = 2e7 + 1;
int cnt[lim];
vector<int>prime;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i = 2; i < lim; i++){
		if(cnt[i] == 0){
			prime.emplace_back(cnt[i] = i);
		}
		for(int& x : prime){
			int value = x * i;
			if(value >= lim){
				break;
			}
			if((cnt[value] = x) == cnt[i]){
				break;
			}
		}
		int x = i / cnt[i];
		while(x % cnt[i] == 0){
			x /= cnt[i];
		}
		cnt[i] = cnt[x] + 1;
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int c, d, x;
		cin >> c >> d >> x;
		ll ans = 0;
		auto work = [&] (int g){
			if((x / g + d) % c == 0){
				ans += 1 << cnt[(x / g + d) / c];
			}
		};
		for(int i = 1; i * i <= x; i++){
			if(x % i == 0){
				work(i);
				if(i * i != x){
					work(x / i);
				}
			}
		}
		cout << ans << "\n";
	}
}