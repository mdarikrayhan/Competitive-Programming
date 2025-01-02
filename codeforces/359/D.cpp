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
 
    int n;
    cin >> n;

    vec<int> a(n);
    vec<pair<int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(all(b));

    vec<char> us(n);
    vec<int> ll;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (us[b[i].second]) continue;
        int l = b[i].second;
        while (l >= 0 && a[l] % b[i].first == 0) { us[l] = 1; --l; }
        int r = b[i].second;
        while (r < n && a[r] % b[i].first == 0) { us[r] = 1; ++r; } 

        if (r-l-2 > mx) {
            mx= r-l-2;
            ll.clear();
            ll.push_back(l+1);
        } else if (r-l-2 == mx) {
            ll.push_back(l+1);
        }
    }

    sort(all(ll));
    cout << len(ll) << " " << mx << "\n";
    for (auto&& el : ll) cout << el + 1 << " ";
}

