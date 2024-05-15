#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <stack>
#include <list>

using namespace std;

#ifdef TXT
struct FileOpener {
    FileOpener() {
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
} fileopener;
#endif

#define ll int64_t
#define vll vector<ll>
#define ull uint64_t
#define vi vector<ll>
#define vvi vector<vector<int>>
#define pi pair<ll,ll>
#define vpi vector<pair<ll,ll>>
#define vvpi vector<vector<pi>>
#define fore(i,b,e) for (int64_t i = (b); i < (e); ++i)
#define foree(i,b,e) for (int64_t i = (b); i <= (e); ++i)
#define ford(i,b,e) for (int64_t i = (e)-1; i >= (b); --i)
#define fordd(i,b,e) for (int64_t i = (e); i >= b; --i)
#define ff first 
#define ss second 
#define pb push_back  
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fastIO ios::sync_with_stdio(false)
#define ceilll(n,d) (((n)+(d)-1)/(d))
#define print_arr(arr,b,e) fore(i,(b),(e)) cout << arr[i] << ' '; cout << '\n';
#define id(x) #x
#define re return
#define fi first
#define se second

const double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll INF = 2000000000;

inline ull gcd(ull a, ull b) {
    while (a && b) { a > b ? a %= b : b %= a; }
    return a ? a : b;
}

template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) { in >> x; }
    re in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
    for (auto x : v) { out << x << ' '; }
    re out;
}


bool is_palindrom(string s) {
    bool f = true;

    fore(i, 0, s.size() / 2) {
        if (s[i] != s[s.size() - i - 1]) {
            f = false;
            break;
        }
    }
    re f;
}

////////////////////////////////////////////////////////////////////
ll a, b, c;
void solve() {
    ll ans = INT64_MAX;
    cin >> a >> b >> c;
    fore(i, -1, 2) {
        fore(j, -1, 2) {
            fore(k, -1, 2) {

                ans = min(ans, abs(a + i - b - j) + abs(a + i - c - k) + abs(b + j - c - k));

            }
        }
    }
    cout << ans << '\n';
}

int main() {
    //fastIO;
    //cin.tie(0), cout.tie(0);
    //cout.precision(12)

    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}