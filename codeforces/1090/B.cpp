#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
//#include"testlib.h"
#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(s) s.rbegin(), s.rend()
#define RT(s) return cout << s, 0
#define sz(s) (int)(s.size())
//#define PI acos(-1)
#define EPS 1e-8
#define watch(x) cout << (#x) << " = " << x << endl
#define mk(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//int dy[] = { 1, 0, -1, 0, -1, 1, 1, -1 };
//int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
//int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1 };
//int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
vector<vi> _dir{ {2, 3}, {2, 3}, {0, 1}, {0, 1} };
void file()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("C:\\Users\\karemo\\source\\repos\\generator\\generator\\out.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("calc.in", "r", stdin);
	//freopen("calc.out", "w", stdout);
#endif
}

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
}
template <class val>
istream& operator>>(istream& is, vector<val>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		is >> vec[i];
	return is;
}
template <class val>
ostream& operator<<(ostream& os, vector<val>& vec)
{
	os << "{";
	for (int i = 0; i < sz(vec); i++)
	{
		os << vec[i];
		if (i + 1 < sz(vec))
			os << ",";
	}
	os << "}";
	return os;
}
template <class f, class s>
istream& operator>>(istream& is, pair<f, s>& p)
{
	is >> p.first >> p.second;
	return is;
}
template <class f, class s>
ostream& operator<<(ostream& os, pair<f, s>& p)
{
	os << "{" << p.first << ',' << p.second << "}";
	return os;
}
#include <chrono>
#include <random>

//write this line once in top
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()* ((uint64_t) new char | 1));


int main() {
	file();
	fast();
	string s;
	map<string, int> ref;
	int cnt = 1;
	while(true) {
		cin >> s;
		if (s == "\\begin{thebibliography}{99}") {
			break;
		}
		if (s.find("\\cite{") == 0 && s.find("}") != string::npos) {
			s.erase(0, 6);
			while (s.back() != '}')
				s.pop_back();
			s.pop_back();
			s = "\\bibitem{" + s + "}";
			ref[s] = cnt++;
		}
	}
	string input;
	cin.ignore();
	while (true) {
		getline(cin, s);
		if (s == "\\end{thebibliography}")
			break;
		input += s + "\n";
	}
	string bib = "\\bibitem{";
	s = input;
	vector<pair<int, string>> v;
	while (!s.empty()) {
		int pos = s.find(bib, bib.size());
		if (pos == (int)string::npos)pos = s.size();
		string tmp = s.substr(0, pos);
		s.erase(0, pos);
		string refs = tmp.substr(0, tmp.find_first_of("}") + 1);
		v.emplace_back(ref[refs], tmp);
	}
	bool valid = true;
	for (int i = 0; i < v.size(); i++)
		if (v[i].first != i + 1)
			valid = false;
	if (valid) {
		cout << "Correct\n";
		return 0;
	}
	sort(all(v));
	cout << "Incorrect" << endl;
	cout << "\\begin{thebibliography}{99}" << endl;
	for (auto& it : v)cout << it.second;
	cout << "\\end{thebibliography}" << endl;
}
	 	   			 	  	      	   	 					