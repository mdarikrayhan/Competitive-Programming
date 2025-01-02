#include <bits/stdc++.h>
#define int int32_t 
#define long int64_t
using f32 = float;
using f64 = double;
using namespace std;
template <class T> using vec = vector<T>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class T> using hashmap = unordered_map<Key, T>;
template <class T> using heap = priority_queue<T>;
using str = std::string_view;
template <class Cont> constexpr long len(Cont const& cont) { return static_cast<long>(cont.size()); } 

pair<int, int> test(int n, int m) {
    int cnt[2] = {n, m};
    --cnt[0];
    int last = 0, turn = 1, p[2] = {0};
    while (cnt[0] > 0 || cnt[1] > 0) {
        if (cnt[last^turn] > 0) {
            cnt[last^turn]--;
            p[turn]++;
            last = last ^ turn;
        } else {
            cnt[last^(turn^1)]--;
            p[turn^1]++;
            last = last ^ (turn^1);
        }
        turn ^= 1;
    }
    return {p[0], p[1]};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    auto [p1, v1] = test(n, m);
    auto [p2, v2] = test(m, n);
    if (p1 > p2) {
        cout << p1 << " " << v1 << "\n";
    } else {
        cout << p2 << " " << v2 << "\n";
    }
}

