
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
const int mod = 998244353;

int qpow(int a, int b) {
	int ret = 1;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
int bit(int x){
	int ret = 0;
	while(x) {
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}

void solve(){
	int n, q, tot = 0;
	cin >> n;
	string s, t;
	cin >> s;
	for(auto c : s) tot += (c == '?');

	vector<array<int,18>>a(1<<17);
	vector<int>f(1<<17);
	auto calc = [&](int l, int r) {
		int x = 0, d = 0;
		while(l >= 0 && r < n){
			if(s[l] == '?' && s[r] == '?'){
				if(l != r) d++;
			}else if(s[l] == '?' || s[r] == '?'){
				d++;
				char c = s[l] != '?' ? s[l] : s[r];
				if(((x>>(c-'a'))&1) == 0) x |= 1<<(c-'a');
			}else if(s[l] != s[r]) break;
			for(int i = 1;i <= 17;i++) (a[x][i] += qpow(i, tot-d)) %= mod;
			l--, r++;
		}	
	};

	//calc(2, 3);
	for(int i = 0;i < n;i++){
		calc(i, i);
		calc(i, i+1);
	}

	for(int i = 0;i < (1<<17);i++){
		int len = bit(i);
		for(int j = i;1;j = (j-1)&i){
			(f[i] += a[j][len]) %= mod;
			if(!j) break;
		}
	}

	cin >> q;
	while(q--){
		cin >> t;
		int x = 0;
		for(auto c : t) x |= 1<<(c-'a');
		cout << f[x] << endl;
	}
}

signed main(){

	IO;
	int t = 1;
	//cin >> t;
	while(t--) solve();

	return 0;
}