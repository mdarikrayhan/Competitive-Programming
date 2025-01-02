#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
#define pb emplace_back
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, m;
queue < string > q;
map < string, string > MP;
int a, p;
void bfs() {
	a = 4, p = 4;
	string cur = "AP";
	MP[cur] = "";
	q.push(cur);
	while(!q.empty()) {
		string u = q.front();
		q.pop();
		if(sz(u) > 21)continue;
		L(i, 0, sz(u) - 1) {
			if(u[i] == 'P') {
				string v = u;
				v.insert(v.begin() + i + 1, 'A');
				v.insert(v.begin() + i, 'A');
				if(!MP.count(v))MP[v] = u, q.push(v);
			}
		}
		L(i, 0, sz(u) - 1) {
			if(u[i] == 'A') {
				string v = u;
				v.insert(v.begin() + i + 1, 'P');
				v.insert(v.begin() + i, 'P');
				if(!MP.count(v))MP[v] = u, q.push(v);
			}
		}
		L(i, 0, sz(u) - a) {
			int can = 1;
			L(j, i, i + a - 1) can &= u[j] == 'A';
			if(can){
				string v = u;
				L(j, 0, a - 1)v.erase(v.begin() + i);
				if(!MP.count(v))MP[v] = u, q.push(v);
			}
		}
		L(i, 0, sz(u) - p) {
			int can = 1;
			L(j, i, i + p - 1) can &= u[j] == 'P';
			if(can){
				string v = u;
				L(j, 0, p - 1)v.erase(v.begin() + i);
				if(!MP.count(v))MP[v] = u, q.push(v);
			}
		}
	}
	int cnt = 0, go = 0;
	L(len, 8, 8) {
		L(sub, 0, (1 << len) - 1) {
			string cur;
			L(j, 0, len - 1)
				if(sub >> j & 1)
					cur += 'A';
				else 
					cur += 'P';
			++cnt;
			if(MP.count(cur)) {
				++go;
				// cout << "cant reach " << cur << endl;
			}
		}
	}
	cout << 1. * go / cnt << endl;
	return ;
	vector<string>ans;
	for(string s = "APP"; sz(s);) {
		ans.pb(s);
		s = MP[s];
	}
	reverse(ans.begin(), ans.end());
	for(auto&u : ans) {
		cout << u << endl;
	}
}
vector < string > operator + (vector < string > a, vector < string > b) {
	for(auto&p : b)
		a.pb(p);
	return a;
}
vector < string > to_good(string s) {
	vector < string > ans;
	ans.pb(s);
	if(s[0] == 'A') {
		s.insert(s.begin(), 'P');
		s.insert(s.begin() + 2, 'P');
		ans.pb(s);
	} 
	if(s[0] == 'P') {
		s.insert(s.begin(), 'A');
		s.insert(s.begin() + 2, 'A');
		ans.pb(s);
	}
	while(true) {
	int upd = 0;
	R(j, sz(s) - 2, 0) {
		if(s[j] == 'P' && s[j + 1] == 'A') {
			upd = 1;
			int pos = j + 1;
			while(pos < sz(s) - 1 && s[pos + 1] == 'A') {
				++pos;
			}
			int length = pos - j;
			while(length < a) {
				s.insert(s.begin() + j, 'A');
				++j;
				s.insert(s.begin() + j + 1, 'A');
				ans.pb(s);
				++length;
			}
			L(t, 0, a - 1) {
				if(s[j + 1] != 'A') {
					cout << "xiaxiaixiaiaiaiaiaiai" << endl;
					exit(0);
				}
				s.erase(s.begin() + j + 1);
			}
			ans.pb(s);
			break;
		}
	}
	if(!upd)break;
	}
	auto asst = [&] (char a, char b) {
		if(a != b) {
			cout << "wa" << endl;
			exit(0);
		}
	};
	auto add_p4 = [&] () { // A -> APPPP
		int fp = 0;
		while(fp < sz(s) && s[fp + 1] == 'A') ++fp;
		s.insert(s.begin() + fp, 'P'), s.insert(s.begin() + fp + 2, 'P');
		ans.pb(s);
		s.insert(s.begin() + fp, 'A'), s.insert(s.begin() + fp + 2, 'A');
		ans.pb(s);
		s.insert(s.begin() + fp, 'P'), s.insert(s.begin() + fp + 2, 'P');
		ans.pb(s);
		L(tst, 1, a - 1) {
			s.insert(s.begin() + fp, 'A');
			s.insert(s.begin() + fp + 2, 'A');
			ans.pb(s);
			++fp;
		}
		L(i, 0, a - 1) asst(s[fp + 1], 'A'), s.erase(s.begin() + fp + 1);
		ans.pb(s);
		
		L(tst, 3, p - 1) {
			s.insert(s.begin() + fp + tst, 'P');
			s.insert(s.begin() + fp + tst + 2, 'P');
			ans.pb(s);
		}
		
		L(i, 0, p - 1) asst(s[fp], 'P'), s.erase(s.begin() + fp);
		ans.pb(s);

		++fp;
		L(tst, p - 3, p - 1) {
			s.insert(s.begin() + fp + tst, 'P');
			s.insert(s.begin() + fp + tst + 2, 'P');
			ans.pb(s);
		}

		L(i, 0, p - 1) asst(s[fp], 'P'), s.erase(s.begin() + fp);
		ans.pb(s);
/*
A
PAP
APAAP
PAPPAAP
(a-1A)P(a-1A)APPAAP
(a-1A)PPPAAP
(a-1A)PPP((p-3)P)A((p-3)P)AP
((p-3)P)AP
((p-3)P)(3P)A(3P)P

APPPP
*/
	};
	auto add_p2 = [&] () { // A -> APPPP
		int fp = 0;
		while(fp < sz(s) && s[fp + 1] == 'A') ++fp;
		s.insert(s.begin() + fp, 'P'), s.insert(s.begin() + fp + 2, 'P');
		ans.pb(s);
		L(tst, 1, a - 1) {
			s.insert(s.begin() + fp, 'A');
			s.insert(s.begin() + fp + 2, 'A');
			ans.pb(s);
			++fp;
		}
		L(i, 0, a - 1)
			asst(s[fp + 1], 'A'), s.erase(s.begin() + fp + 1);
		ans.pb(s);
/*
A
PAP
((a-1)A)P((a-1)A)AP
((a-1)A)PP
*/
	};
	int ca = 0, cp = 0;
	for(auto&c : s)
		if(c == 'A') ++ca;
		else if(c == 'P') ++cp;
		else cerr << "kidding" << endl, exit(0);
	pair<int,int>best={114514,114514};
	
	int ti = 0, tj = 0;
	L(ij, 0, 233)
		L(i, 0, ij) {
			int j = ij - i;
			int na = ca - 2 * i, np = cp + 2 * i + 4 * j;
			na = (na % a + a) % a;
			np = (np % p + p) % p;
			auto mp = make_pair(na, np);
			if(mp < best)
				best = mp, ti = i, tj = j;
		}
	auto del_bad = [&] () {
	while(true) {
		int upd = 0;
		L(i, 0, a) if(i < sz(s)) upd += s[i] == 'A';
		if(upd != a + 1)break;
		L(i, 0, a - 1)s.erase(s.begin());
		ans.pb(s);
	}
	while(true) {
		int upd = 0;
		L(i, 0, p) if(i < sz(s)) upd += s[sz(s) - i - 1] == 'P';
		if(upd != p + 1)break;
		L(i, 0, p - 1)s.erase(--s.end());
		ans.pb(s);
	}
	};
	L(i, 1, ti)
		add_p2(), del_bad();
	L(i, 1, tj)
		add_p4(), del_bad();
	del_bad();
	return ans;
}
string move1(string u, int i) {
	if(u[i] == 'P') {
		string v = u;
		v.insert(v.begin() + i + 1, 'A');
		v.insert(v.begin() + i, 'A');
		return v;
	} else return "-";
}
string move2(string u, int i) {
	if(u[i] == 'A') {
		string v = u;
		v.insert(v.begin() + i + 1, 'P');
		v.insert(v.begin() + i, 'P');
		return v;
	} else return "-";
}
string move3(string u, int i) {
	if(i + a > sz(u))return "-";
	int can = 1;
	L(j, i, i + a - 1) can &= u[j] == 'A';
	if(can){
		string v = u;
		L(j, 0, a - 1)v.erase(v.begin() + i);
		return v;
	} else return "-";
}
string move4(string u, int i) {
	if(i + p > sz(u))return "-";
	int can = 1;
	L(j, i, i + p - 1) can &= u[j] == 'P';
	if(can){
		string v = u;
		L(j, 0, p - 1)v.erase(v.begin() + i);
		return v;
	} else return "-";
}
string Get(string a, pair < int, int > b) {
	if(b.first == 1)return move1(a, b.second);
	if(b.first == 2)return move2(a, b.second);
	if(b.first == 3)return move3(a, b.second);
	if(b.first == 4)return move4(a, b.second);
	return a;
}
pair < int, int > get_operation(string a, string b) {
	L(i, 0, sz(a) - 1)if(move1(a, i) == b) return make_pair(1, i);
	L(i, 0, sz(a) - 1)if(move2(a, i) == b) return make_pair(2, i);
	L(i, 0, sz(a) - 1)if(move3(a, i) == b) return make_pair(3, i);
	L(i, 0, sz(a) - 1)if(move4(a, i) == b) return make_pair(4, i);
	return make_pair(-1, -1);
}
void Main() {
	string s, t;
	cin >> a >> p >> s >> t;
	auto A = to_good(s);
	auto B = to_good(t);
	if(A.back() != B.back()) {
		cout << -1 << '\n';
	} else {
		vector<pair<int,int>>ans;
		L(i, 1, sz(A) - 1) {
			auto op = get_operation(A[i - 1], A[i]);
			ans.pb(op);
		}
		R(i, sz(B) - 1, 1) {
			auto op = get_operation(B[i - 1], B[i]);
			vector < pair < int, int > > opt;
			int pos = op.second;
			if(op.first == 1) {
				L(i, 1, a - 1)
					opt.pb(1, i + pos);
				opt.pb(3, pos);
				opt.pb(3, pos + 1);
			} else if(op.first == 2) {
				L(i, 1, p - 1)
					opt.pb(2, i + pos);
				opt.pb(4, pos);
				opt.pb(4, pos + 1);
			} else if(op.first == 3) {
				while(pos < sz(B) && B[i][pos] == 'A') 
					++pos;
				if(pos < sz(B) && B[i][pos] == 'P') {
					L(i, 0, a - 1)
						opt.pb(1, pos + i);
					opt.pb(3, pos + a + 1);
				} else {
					--pos;
					while(pos >= 0 && B[i][pos] == 'A')
						--pos;
					assert(pos >= 0);
					L(i, 0, a - 1)
						opt.pb(1, pos + i);
					opt.pb(3, pos);
				}
			} else {
				while(pos < sz(B) && B[i][pos] == 'P') 
					++pos;
				if(pos < sz(B) && B[i][pos] == 'A') {
					L(i, 0, p - 1)
						opt.pb(2, pos + i);
					opt.pb(4, pos + p + 1);
				} else {
					--pos;
					while(pos >= 0 && B[i][pos] == 'P')
						--pos;
					assert(pos >= 0);
					L(i, 0, p - 1)
						opt.pb(2, pos + i);
					opt.pb(4, pos);
				}
			}
			for(auto&r : opt)
				ans.pb(r);
			continue;
			string cur = B[i];
			for(auto&u : opt)cur = Get(cur, u);
			if(cur != B[i - 1]) {
				cout << "quancuole" << endl;
			}
		}
		cout << sz(ans) << '\n';
		for(auto&u : ans) {
			if(u.first == 1) 
				cout << "+P " << u.second + 1 << '\n';
			if(u.first == 2) 
				cout << "+A " << u.second + 1 << '\n';
			if(u.first == 3) 
				cout << "-A " << u.second + 1 << '\n';
			if(u.first == 4) 
				cout << "-P " << u.second + 1 << '\n';
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
} 