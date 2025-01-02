#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
#include<unordered_map>

#define sz(s) (int)(s.size())
#define all(v) v.begin(),v.end()
#define endl '\n'
#define PI acos(-1)
typedef long long ll;
typedef unsigned long long ull;

using namespace std;
typedef complex<double> point;
#define length(a)   (hypot((a).imag(), (a).real()))  
#define vec(a,b)  ((b)-(a)) 
#define X real() 
#define Y imag()
#define cp(a,b)   ( (conj(a)*(b)).imag() )
void file() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("jobs.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}
int gcd(int a, int b) {

    while (b != 0) {
        int x = a;
        a = b;
        b = x % b;
    }
    return a;
}
int mod = 1e9 + 7;
ll fastPower(ll base, ll power) {
    if (power == 0)return 1;
    ll res = fastPower(base, power / 2);
    res = ((res % mod) * (res % mod)) % mod;
    if (power % 2) {
        return ((res % mod) * (base % mod)) % mod;
    }
    else return res % mod;
}
template<class val>
istream& operator>>(istream& is, vector<val>& vec) {
    for (int i = 0; i < vec.size(); i++)
        is >> vec[i];
    return is;
}

template<class val>
ostream& operator<<(ostream& os, vector<val>& vec) {
    for (int i = 0; i < sz(vec); i++) {
        os << vec[i];
        if (i + 1 < sz(vec))
            os << ' ';
    }
    return os;
}

template<class f, class s>
istream& operator>>(istream& is, pair<f, s>& p) {
    is >> p.first >> p.second;
    return is;
}

template<class f, class s>
ostream& operator<<(ostream& os, pair<f, s>& p) {
    os << p.first << ' ' << p.second;
    return os;
}
//int n; 
//vector<pair<int, int>>arr;
//double triangleArea(double a, double b, double c) {
//    double s = (a + b + c) / 2.0;
//    return sqrt((s - a) * (s - b) * (s - c) * s);
//}
//double triangleArea(point p0, point p1, point p2) {
//    double a = length(vec(p1, p0)), b = length(vec(p2, p0)), c = length(
//        vec(p2, p1));
//    return triangleArea(a, b, c);
//}
//bool cmp(point a, point b) {
//    return a.X < b.X || (a.X == b.X && a.Y < b.Y);
//}
//bool cw(point a, point b, point c) {
//    return cp(vec(a, b), vec(b, c)) < 0;
//}
//bool ccw(point a, point b, point c) {
//    return cp(vec(a, b), vec(b, c)) > 0;
//}
//vector<point> convex_hull(vector<point>& p) {
//    if (p.size() == 1) return p;
//    sort(p.begin(), p.end(), &cmp);
//    point p1 = p[0], p2 = p.back();
//    vector<point> up, down;
//    up.push_back(p1);
//    down.push_back(p1);
//    for (int i = 1; i < (int)p.size(); i++) {
//        if (i == p.size() - 1 || cw(p1, p[i], p2)) {
//            while (up.size() >= 2
//                && !cw(up[up.size() - 2], up[up.size() - 1], p[i]))
//                up.pop_back();
//            up.push_back(p[i]);
//        }
//        if (i == p.size() - 1 || ccw(p1, p[i], p2)) {
//            while (down.size() >= 2
//                && !ccw(down[down.size() - 2], down[down.size() - 1], p[i]))
//                down.pop_back();
//            down.push_back(p[i]);
//        }
//    }
//    vector<point> convex;
//    for (int i = 0; i < (int)down.size(); i++)
//        convex.push_back(down[i]);
//    for (int i = up.size() - 2; i > 0; i--)
//        convex.push_back(up[i]);
//    return convex;
//}
void solve() {
    int n;
    vector<vector<int>>arr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        vector<int>v;
        while (x--) {
            int y; cin >> y;
            v.push_back(y);
        }
        sort(all(v));
        arr.push_back(v);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(arr[i]) - 1; ++j) {
            int left = 0, right = 0, vl = i - 1, vr = i + 1;
            if (!i) {
                vl = n - 1;
            }
            if (i == n - 1)vr = 0;
            int idx1 = upper_bound(all(arr[vl]), arr[i][j]) - arr[vl].begin();
            int idx2 = upper_bound(all(arr[vl]), arr[i][j + 1]) - arr[vl].begin();
            left = idx2 - idx1;
            idx1 = upper_bound(all(arr[vr]), arr[i][j]) - arr[vr].begin();
            idx2 = upper_bound(all(arr[vr]), arr[i][j + 1]) - arr[vr].begin();
            right = idx2 - idx1;
            if (left != right)cnt++;
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    file();
    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}
 		 					  				    		   		   	