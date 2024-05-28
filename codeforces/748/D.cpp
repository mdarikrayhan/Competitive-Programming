#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ll long long

ll n, a, sz, ans = 0LL, sum;
int k;
string s, r;

string rev(string x) {
	string ret = "";
	for (int i = k - 1; i >= 0; i--) {
		ret += x[i];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	map<string, vector<ll>> palindrome;
	vector<ll> singlePalindrome;
	map<string, pair<vector<ll>, vector<ll>>> ss;

	for (int i = 0; i < n; i++) {
		cin >> s >> a;
		r = rev(s);
		if (r == s) {
			palindrome[r].pb(a);
		} else {
			string mi, ma;
			mi = min(r, s);
			ma = max(r, s);
			if (s == mi) {
				ss[mi].fi.pb(a);
			} else {
				ss[mi].se.pb(a);
			}
		}
	}

	for (auto itr = palindrome.begin(); itr != palindrome.end(); itr++) {
		sz = itr->se.size();
		sort(itr->se.begin(), itr->se.end(), greater<ll>());
		for (int i = 0; i < sz; i += 2) {
			if (i == sz - 1) {
				if (itr->se[i] >= 0) singlePalindrome.pb(itr->se[i]);
				else {
					if (i > 0 && itr->se[i - 1] < 0) {
						singlePalindrome.pb(itr->se[i - 1] * (-1));
					}
				}
				break;
			}
			sum = itr->se[i] + itr->se[i + 1];
			if (sum >= 0) {ans += sum;}
			else {
				if (itr->se[i] >= 0) singlePalindrome.pb(itr->se[i]);
				else {
					if (i > 0 && itr->se[i - 1] < 0) {
						singlePalindrome.pb(itr->se[i - 1] * (-1));
					}
				}
				break;
			}
			if (i == sz - 2) {
				if (sum >= 0 && itr->se[i + 1] < 0) {
					singlePalindrome.pb(itr->se[i + 1] * (-1));
				}
			}
		}
	}

	if(singlePalindrome.size() > 0) {
		sort(singlePalindrome.begin(), singlePalindrome.end(), greater<ll>());
		if (singlePalindrome[0] >= 0) {ans += singlePalindrome[0];}
	}

	for (auto itr = ss.begin(); itr != ss.end(); itr++) {
		int sz1 = itr->se.fi.size(), sz2 = itr->se.se.size();
		int mins = min(sz1, sz2);
		if(mins) {
			sort(itr->se.fi.begin(), itr->se.fi.end(), greater<ll>());
			sort(itr->se.se.begin(), itr->se.se.end(), greater<ll>());
			for(int i = 0; i < mins; i++) {
				sum = itr->se.fi[i] + itr->se.se[i];
				if (sum > 0) {ans += sum;}
				else break;
			}
		}
	}

	cout << ans;
}