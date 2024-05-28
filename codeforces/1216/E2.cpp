#include <fstream>
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <set>
#include <map>
 
#define int long long
#define ld long double
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define eb emplace_back
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define all(v) v.begin(), v.end()
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
template<typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
    _out << _p.first << ' ' << _p.second;
    return _out;
}
 
template<typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
    _in >> _p.first >> _p.second;
    return _in;
}
 
template<typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
    if (_v.empty()) { return _out; }
    _out << _v.front();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
 
template<typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}
 
const int MAXN = 3e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
 
int progression(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
}
 
int progression1(int a, int b) {
    return (b - a + 1);
}
 
int dksum(int v) {
    if (v == 0) {
        return 0;
    }
    int x = 1;
    int ans = 0;
    int m = 1;
    while (x * 10 <= v) {
        ans += m * (progression(v - (x * 10 - 1) + 1, v - x + 1));
        x *= 10;
        m++;
    }
    ans += m * progression(1, v - x + 1);
    return ans;
}
 
int get_digit(int v, int k) {
    vc<int> d;
    while (v > 0) {
        d.pb(v % 10);
        v /= 10;
    }
    reverse(all(d));
    return d[k - 1];
}
 
int prefixsum(int v) {
    if (v == 0) {
        return 0;
    }
    int x = 1;
    int ans = 0;
    int m = 1;
    while (x * 10 <= v) {
        ans += m * (progression1(v - (x * 10 - 1) + 1, v - x + 1));
        x *= 10;
        m++;
    }
    ans += m * progression1(1, v - x + 1);
    return ans;
}
 
int get_line(int k) {
    int l = 0;
    int r = 500000000;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (prefixsum(mid) < k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return get_digit(l + 1, k - prefixsum(l));
}
 
int process(int k) {
    int i = 0;
    int ksum = 0;
    int l = 0;
    int r = 500000000;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (dksum(mid) < k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return get_line(k - dksum(l));
}
 
class EC2 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int q;
        in >> q;
        while (q--) {
            int k;
            in >> k;
            out << process(k) << '\n';
        }
    }
};
 
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	EC2 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}