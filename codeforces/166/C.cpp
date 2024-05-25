#include <bits/stdc++.h>
#define int int32_t 
#define long int64_t
#define all(x) (x).begin(), (x).end()
#define rev std::reverse
#define gt std::greater
using f32 = float;
using f64 = double;
using namespace std;
template <class T> using vec = vector<T>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class T> using hashmap = unordered_map<Key, T>;
template <class T> using heap = priority_queue<T>;
using str = std::string_view;
template <class Cont> constexpr long len(Cont const& cont) { return static_cast<long>(cont.size()); } 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x;
    cin >> n >> x;
    
    vec<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    auto it1 = lower_bound(all(a), x);
    auto it2 = upper_bound(all(a), x);
    
    int l = it1 - a.begin(), r = it2 - a.begin(), c = 0;
    if (l == r) {
        r = l + 1;
        ++n; c = 1;
    }
    
    int m = (n - 1) / 2;
    if (m >= l && m < r) {
        cout << c << "\n";
    } else if (m < l) {
        cout << (l - m) * 2 - (n % 2 == 0) + c << "\n";
    } else {
        cout << (m - r + 1) * 2 - (n % 2) + c << "\n";
    }
}

