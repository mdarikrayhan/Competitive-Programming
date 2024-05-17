//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#ifdef Mhmd_Bakr
#include "mhmd_bakr.h"
#endif

//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;

// Author: Mohamed Bakr

#define ll long long int
#define INT int32_t
#define int ll
#define vct vector
//#define int128 number<cpp_int_backend<128, 128, unsigned_magnitude, unchecked, void>>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sum(v) accumulate(all(v), 0LL)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define ln "\n"
#define lln cout<<ln
#define umap unordered_map
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln
#define precision(x,y) fixed<<setprecision(y)<<x
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define PI 3.141592653589793238462643383279502884197
#define toDeg(theta) theta*(180.0/PI)
#define toRad(theta) theta*(PI/180.0)
#define sz(v) (int64_t)v.size()

template <typename T, typename C>
istream& operator>>(istream& istream, pair<T, C>& pi) { cin >> pi.first >> pi.second; return istream; }
template <typename T, typename C>
ostream& operator<<(ostream& ostream, pair<T, C>& pi) { cout << pi.first << " " << pi.second;  return ostream; }
template <typename T>
istream& operator>>(istream& istream, vector<T>& v) { for (T& it : v) cin >> it; return istream; }
template <typename T>
ostream& operator<<(ostream& ostream, vector<T>& v) { for (T it : v) cout << it << " "; return ostream; }
template <typename T>
ostream& operator<<(ostream& ostream, set<T>& v) { for (T it : v) cout << it << " "; return ostream; }


bool prime(int num) { if (num <= 1) return false; int ch = 2; while (ch * ch <= num) { if (!(num % ch)) return false; ch++; }return true; }
int fact(int n) { if (n == 0) return 1; return n * fact(n - 1); }
int nPr(int n, int r) { int val = 1; for (int i = n - r + 1; i <= n; i++) val *= i; return val; }
int nCr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int biPow(int x, int y) { int val = 1; while (y) { if (y % 2) { val *= x; y--; } else { x *= x; y /= 2; } }return val; }
int modPow(int x, int y, int m) { int val = 1; x %= m; while (y) { if (y % 2) { val *= x; val %= m; y--; } else { x *= x; x %= m; y /= 2; } }return val % m; }
int sumRng(int l, int r) { return (r - l + 1) * (l + r) / 2; }

string mv[8] = { "U", "R", "D", "L", "UR","UL","DR","DL" };
int xd[9] = { -1, 0, 1,  0, -1, -1, 1,  1, 0 };
int yd[9] = { 0, 1, 0, -1,  1, -1, 1, -1, 0 };



void answer(int test)
{
	int n; cin >> n;
	string s; cin >> s;
	s += '_';
	vct<string>a;
	string cur = "";
	for (int i = 0; i <= n; i++) {
		if (s[i] == '_') {
			if (sz(cur)) {
				a.push_back(cur);
				cur = "";
			}
		}
		else if (s[i] == '(') {
			if (sz(cur)) {
				a.push_back(cur);
				cur = "";
			}
			a.push_back("(");
		}
		else if (s[i] == ')') {
			if (sz(cur)) {
				a.push_back(cur);
				cur = "";
			}
			a.push_back(")");
		}
		else cur.push_back(s[i]);
	}
	bool inp = 0;
	int l = 0, r = 0;
	for (int i = 0; i < sz(a); i++) {
		if (inp) {
			if (a[i] == ")") inp = 0;
			else r++;
		}
		else {
			if (a[i] == "(") inp = 1;
			else l = max(l, sz(a[i]));
		}
	}
	cout << l << " " << r;
}
bool multiTests = false;
INT main()
{
#ifdef Mhmd_Bakr
	//Contest : -
	//Problem : -
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	fastio;
	int tests = 1;
	if (multiTests) cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		//cout << "Case #" << test << ": ";
		answer(test);
	}
#ifdef Mhmd_Bakr
	End();
#endif
}