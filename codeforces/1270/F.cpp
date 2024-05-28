#include <bits/stdc++.h>

#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) (int)x.size()
#define pii pair<int, int>
using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int K = 80;
const int N = (int)3e5 + 100;
const int inf = (int)2e9;
          
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


int n, pref[N], nxt[N];
string s;

int get(int lf, int l, int r, int x){
	l -= lf;
	r -= lf;

	int L = max(l, K * x + 1); 
	int res = max(0, r / x - (L ? (L - 1) / x : 0));

	return res;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<int, int, custom_hash> cnt;
void solve() {
	cin >> s;
	n = s.size();
	s = "#" + s;

	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + (s[i] == '1');
	}	

	long long ans = 0;
	for(int k = 1; k <= K; k++){
		cnt.clear();
		cnt[0] = 1;
		for(int i = 1; i <= n; i++){
			int x = i - pref[i] * k;
			ans += cnt[x]++;
		}
	}

	int lst = n + 1;
	for(int i = n; i >= 1; i--){
		nxt[i] = lst;
		if(s[i] == '1')
			lst = i;
	}

	for(int i = 1; i <= n; i++){
		int j = i;
		while(j <= n){
			int r = nxt[j];
			int cnt = pref[j] - pref[i - 1];
			if(cnt > n / K + 1)
			    break;
			if(cnt){
				ans += get(i - 1, j, r - 1, cnt);
			}

			j = nxt[j];
		}
	}
	cout << ans << "\n";
}

main() {    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}