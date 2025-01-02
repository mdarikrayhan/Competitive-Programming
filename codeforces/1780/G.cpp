#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pii> vii;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

const int MAX_LEN = 1000000 + 10;
struct state{
	int len = 0; 
	int cnt = 1; 
	int link = 0; 
	map<char, int> nxt; 
};

state st[MAX_LEN * 2];
int sz = 0, last = 0;

void SA_init() {
	st[0].len = 0; 
	st[0].link = -1; 
	sz++; 
	last = 0;
}

void SA_extend(char c) {  
	int cur = sz++; 
	st[cur].len = st[last].len + 1; 
	int p = last; 
	while(p != -1 && !st[p].nxt.count(c)) {
		st[p].nxt[c] = cur; 
		p = st[p].link; 
	}

	if(p == -1) {
		st[cur].link = 0; 
	}else{
		int q = st[p].nxt[c]; 
		if(st[p].len + 1 == st[q].len) { 
			st[cur].link = q; 
		}else{
			int clone = sz++; 
			st[clone].len = st[p].len + 1; 
			st[clone].nxt = st[q].nxt; 
			st[clone].link = st[q].link; 
			st[clone].cnt = 0; 
			while(p != -1 && st[p].nxt[c] == q) {
				st[p].nxt[c] = clone; 
				p = st[p].link; 
			}
			st[q].link = st[cur].link = clone; 
		}
	}
	last = cur; 
}

vi sorted_by_lens[MAX_LEN]; 

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n; 
	string t; cin >> t; 
	SA_init();
	for(char c : t) SA_extend(c);

	for(int i = 0; i <= sz; i++) sorted_by_lens[st[i].len].push_back(i);
	for(int i = MAX_LEN - 1; i > 0; i--) {
		for(int cur : sorted_by_lens[i]) {
			st[st[cur].link].cnt += st[cur].cnt; 
		}
	}

	vector<vii> events(sz); 
	for(int i = 1; i < sz; i++) {
		int min_len = st[st[i].link].len; 
		int max_len = st[i].len; 
		if(min_len >= 0) events[min_len].emplace_back(st[i].cnt, -1);
		if(max_len >= 0) events[max_len].emplace_back(st[i].cnt, 1);
	}

	ll ans = 0;
	vi counter(sz);
	for(int i = 1; i < sz; i++) {
		for(int j = i; j < sz; j += i) counter[j]++; 
		for(auto j : events[i]) {
			ans += 1LL * j.first * counter[j.first] * j.second; 
		}
	}
	cout << ans << "\n"; 
}
