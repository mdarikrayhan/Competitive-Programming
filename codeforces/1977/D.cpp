#pragma optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int	n, q, m;

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int bs1 = 131;
const int bs2 = 31;

void solve(){
	cin >> n >> m;
	vector<int> aa(n + 1);
	string s[n + 1];
	for(int i = 1; i <= n; i ++) {
		cin >> s[i];
		s[i] = '.' + s[i];
	}
	vector<int> p1(n + 1), p2(n + 1);
	p1[0] = 1, p2[0] = 1;
	for(int i = 1; i <= n; i ++) {
		p1[i] = p1[i - 1] * bs1 % mod1;
		p2[i] = p2[i - 1] * bs2 % mod2;
	}
	map<pair<int,int>, int> mp;
	for(int j = 1; j <= m; j ++) {
		vector<int> on, zr;
		int hs1 = 0, hs2 = 0;
		for(int i = 1; i <= n; i ++) {
			if(s[i][j] & 1) {
				hs1 = (hs1 + i * p1[i]) % mod1;
				hs2 = (hs2 + i * p2[i]) % mod2; 
			}
		}
		for(int i = 1; i <= n; i ++) {
			if(s[i][j] & 1) {
				int h1 = ((hs1 - i * p1[i]) % mod1 + mod1) % mod1;
				int h2 = ((hs2 - i * p2[i]) % mod2 + mod2) % mod2;
				mp[{h1,h2}]	++;	
			} else {
				int h1 = (hs1 + i * p1[i]) % mod1;
				int h2 = (hs2 + i * p2[i]) % mod2;
				mp[{h1, h2}] ++;
			}
		}
	}
	int ans = -1;
	pair<int,int> jl;
	for(auto i : mp) {
		if(i.second > ans) {
			ans = i.second;
			jl = i.first;
		}
	}
	cout << ans << '\n';
	for(int j = 1; j <= m; j ++) {
		vector<int> on, zr;
		int hs1 = 0, hs2 = 0;
		for(int i = 1; i <= n; i ++) {
			if(s[i][j] & 1) {
				hs1 = (hs1 + i * p1[i]) % mod1;
				hs2 = (hs2 + i * p2[i]) % mod2; 
			}
		}
		for(int i = 1; i <= n; i ++) {
			if(s[i][j] & 1) {
				int h1 = ((hs1 - i * p1[i]) % mod1 + mod1) % mod1;
				int h2 = ((hs2 - i * p2[i]) % mod2 + mod2) % mod2;
				if(jl == make_pair(h1, h2)) {
					for(int ii = 1; ii <= n; ii ++) {
						if(s[ii][j] & 1) {
							if(ii == i) cout << 0;
							else cout << 1;
						} else {
							cout << 0;
						}
					}
					cout << '\n';
					return;
				}	
			} else {
				int h1 = (hs1 + i * p1[i]) % mod1;
				int h2 = (hs2 + i * p2[i]) % mod2;
				if(jl == make_pair(h1, h2)) {
					for(int ii = 1; ii <= n; ii ++) {
						if(s[ii][j] & 1) {
							cout << 1;
						} else {
							if(ii == i) cout << 1;
							else cout << 0;
						}
					}
					cout << '\n';
					return;
				}
			}
		}
	}
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int ___ = 1;
	cin >> ___;
	while(___ --)
		solve();
	return 0;
}
