#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
 
#define rep(i,a) repp(i,0,a)
#define repp(i,a,b) for (int i = (a); i < (b); ++i)
#define reppp(i, a, b, d) for (int i = (a); (d) > 0 ? i < (b) : i > (b); i += (d))

#ifndef ONLINE_JUDGE
#define debug(x) (cout<<(#x)<<':'<<(x)<<'\n')
#else
#define debug(x)
#endif

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr) {
    os << "[ ";
    for (const auto& item : arr) os << item << " ";
    os << "]";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[ ";
    for (const auto& item : v) os << item << " ";
    os << "]";
    return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "[ ";
    for (const auto& item : s) os << item << " ";
    os << "]";
    return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s) {
    os << "[ ";
    for (const auto& item : s) os << item << " ";
    os << "]";
    return os;
}
template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
    os << "[ ";
    for (const auto& pair : m) os << "[" << pair.first << "] = " << pair.second << ", ";
    os << "]";
    return os;
}

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if(a + 1 != c) {
        cout << -1 << "\n"; return;
    }
    if(a == 0) {
        cout << b << "\n"; return;
    }
    int cur = 1;
    int h = 0;
    a--;
    while(a >= cur * 2) {
        a -= cur * 2;
        cur *= 2;
        h++;
    }
    if(a + b + c == 0) {
        cout << h << "\n"; return;
    }
    int x = a, y = cur * 2 - a;
    int z = 2 * x + y;
    int q = (b + c) / z;
    int r = (b + c) % z;
    if(a) {
        h += q + 1 + (r > y);
    } else {
        h += q + (r != 0);
    }
    cout << h << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

