// LUOGU_RID: 155009550
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define pb emplace_back
#define sz(a) int(a.size())

int n;
string str;
bool ask(const string &s)
{
	cout << "? " << s << endl;
	int k, x;
	cin >> k;
	if (!~k) {
		exit(-1);
	}
	for (int i = 1; i <= k; ++i) {
		cin >> x, --x;
		for (int j = 0; j < sz(s); ++j) {
			str[x + j] = s[j];
		}
	}
	return k;
}
void work()
{
	cin >> n;
	str.resize(n);
	for (auto &c : str) {
		c = ' ';
	}
	if (n == 4) {
		for (auto s : {"CC", "CO", "CH", "HO"}) {
			if (ask(s)) {
				string pre;
				auto dfs = [&](auto self, int p) {
					if (p == 4) {
						if (sz(pre) && ask(pre)) {
							str = pre;
							return true;
						}
						pre = str;
						return false;
					}
					if (str[p] != ' ') {
						return self(self, p + 1);
					}
					for (char c : {'C', 'H', 'O'})  {
						if (s == "HO" && c == 'C' && p != 3) {
							continue;
						}
						str[p] = c;
						if (self(self, p + 1)) {
							return true;
						}
						str[p] = ' ';
					}
					return false;
				};
				dfs(dfs, 0);
				str = pre;
				goto End;
			}
		}
		if (ask("OO")) {
			if (str == "OO  ") {
				str = ask("OOHH") ? "OOHH" : "OOHC";
			}else if (str == "OOO ") {
				str = ask("OOOH") ? "OOOH" : "OOOC";
			}
		}else {
			if (ask("HHH")) {
				if (str == "HHH ") {
					str = "HHHC";
				}else if (str == " HHH") {
					str = "OHHH";
				}
			}else {
				str = "OHHC";
			}
		}
	}else {
		ask("CO"), ask("CC"), ask("CH"), ask("OO"), ask("HO");
		for (int i = 1; i < n - 1; ++i) {
			if (str[i] == ' ') {
				str[i] = 'H';
			}
		}
		bool o1 = str[0] == ' ', o2 = str.back() == ' ';
		for (char c : {'H', 'O'}) {
			for (char d : {'C', 'H'}) {
				if (o1) {
					str[0] = c;
				}
				if (o2) {
					str.back() = d;
				}
				if (c == 'O' && d == 'H' || ask(str)) {
					goto End;
				}
				if (o1) {
					str[0] = ' ';
				}
				if (o2) {
					str.back() = ' ';
				}
			}
		}
	}
	End:;
	cout << "! " << str << endl;
	int sb;
	cin >> sb;
	assert(sb);
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int test;
	for (cin >> test; test--; ) {
		work();
	}
	return 0;
}
