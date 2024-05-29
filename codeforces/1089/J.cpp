#include <bits/stdc++.h>
#define isletter(c) (isalnum(c) || c == '_' || c == '$')

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_set<string> reserved;
unordered_map<string, string> ctarget;
vector<string> target, tokens;
int tidx = 0;

int parse(string s) {
	int nxt1 = 1, nxt2 = 1;
	if (isdigit(s[0]))
		while (nxt1 < int(s.size()) && isdigit(s[nxt1])) ++nxt1;
	else if (isletter(s[0]))
		while (nxt1 < int(s.size()) && isletter(s[nxt1])) ++nxt1;
	if (int(s.size()) > 20) s = s.substr(0, 20);
	for (int i = int(s.size()); i > 0; i--, s.pop_back())
		if (reserved.count(s)) { nxt2 = i; break; }
	return max(nxt1, nxt2);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m; string line, token;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> token, reserved.insert(token);

	for (char i = 'a'; i <= 'z'; i++)
		if (!reserved.count({i})) target.push_back({i});
	for (char i = 'a'; i <= 'z'; i++)
		for (char j = 'a'; j <= 'z'; j++)
			if (!reserved.count({i, j})) target.push_back({i, j});
	for (char i = 'a'; i <= 'z'; i++)
		for (char j = 'a'; j <= 'z'; j++)
			for (char k = 'a'; k <= 'z'; k++)
				if (!reserved.count({i, j, k})) target.push_back({i, j, k});

	cin >> m; cin.ignore();
	while (m--) {
		getline(cin, line); line = line.substr(0, line.find('#'));
		stringstream ss(line);
		while (ss) {
			token = ""; ss >> token;
			while (!token.empty()) {
				int nxt = parse(token); string cur = token.substr(0, nxt);
				if (!reserved.count(cur) && !isdigit(cur[0]))
					tokens.push_back(ctarget.count(cur) ? ctarget[cur] : ctarget[cur] = target[tidx++]);
				else
					tokens.push_back(cur);
				token = token.substr(nxt);
			}
		}
	}

	int sz = tokens.size(); string res = "";
	for (int i = sz - 1; i >= 0; i--)
		res = tokens[i] + (parse(tokens[i] + res) != int(tokens[i].size()) ? " " : "") + res;
	cout << res << '\n';
	return 0;
}