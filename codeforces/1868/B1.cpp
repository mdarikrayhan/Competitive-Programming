#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define endl '\n'
const int MAX = 3e5 + 67;
int a[MAX], icl[MAX];
int lowbit(int x) {
	return x & (-x);
}
void run() { 
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int sn = 1;
	if(sum % n) sn = 0;
	else {
		map<int, int> ps, pp;
		int ave = sum / n;
		int top = 0;
		for(int i = 1; i <= n; i++) {
			int now = abs(ave - a[i]);
			if(!now) {
				for(int i = 31; i >= 0; i--) {
					if((1ll << i) & a[i]) {
						icl[++top] = (1ll << i);
						break;
					}
				}
				continue;
			}
			int st = 1, cnt = 0;
			while(st <= now) {
				if(now & st) {
					 now += st;
					 break;
				}
				st <<= 1;
			}
			
			if(lowbit(now) != now) {
				sn = 0;
				break;
			}
			if(a[i] < ave) swap(st, now);
			ps[st]++;
			ps[now]--;
		}
		if(sn) {
//			sort(icl + 1, icl + 1 + top);
			for(auto it = ps.begin();  it != ps.end(); it++) {
				if(it->second != 0) sn = 0;
			}
			
		}
	}
	if(sn) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) {
		run();
	}
	return 0;
} 