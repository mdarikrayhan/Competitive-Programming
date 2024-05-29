#include <bits/stdc++.h>

#define ft first
#define sd second

using namespace std;

using ll = long long;
using ld = long double;
using pp = pair<int, int>;
using tp = tuple<int, int, int>;

template<typename T, typename F>
istream &operator>>(istream &s, pair<T, F> &a) {
    s >> a.ft >> a.sd;
    return s;
}

template<typename T, typename F>
ostream &operator<<(ostream &s, pair<T, F> &a) {
    s << a.ft << ' ' << a.sd << (char) (10);
    return s;
}

template<typename T>
istream &operator>>(istream &s, vector<T> &a) {
    for (T &el : a) {
        s >> el;
    }
    return s;
}

template<typename T>
ostream &operator<<(ostream &s, vector<T> &a) {
    for (T &el : a) {
        s << el << ' ';
    }
    s << (char) (10);
    return s;
}


struct Rect {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    int type() {
        if (x1 < x2) {
            return 0;
        }
        if (x1 == 1) {
            return 1;
        }
        return 2;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Rect> rects(n);
    for (auto &[x1, y1, x2, y2] : rects) {
        cin >> x1 >> y1 >> x2 >> y2;
    }
    vector<int> tmp;
    for (auto &[x1, y1, x2, y2] : rects) {
        for (int d = -1; d <= 1; d++) {
            tmp.push_back(y1 + d);
            tmp.push_back(y2 + d);
        }
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    int L = tmp.size();
    for (auto &[x1, y1, x2, y2] : rects) {
        y1 = lower_bound(tmp.begin(), tmp.end(), y1) - tmp.begin();
        y2 = lower_bound(tmp.begin(), tmp.end(), y2) - tmp.begin();
        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    }
    vector<vector<int>> in(L), out(L);
    for (int i = 0; i < n; i++) {
        auto [x1, y1, x2, y2] = rects[i];
        in[y1].push_back(i);
        out[y2].push_back(i);
    }
    set<pp> lefts;  // l, id
    for (int i = 0; i < L; i++) {
        for (int id : in[i]) {
            lefts.emplace(rects[id].y1, id);
        }
        for (int id : out[i]) {
            if (rects[id].type() == 0 && !lefts.empty() && lefts.begin()->first < rects[id].y1) {
                int cover_id = lefts.begin()->second;
                int new_type = 3 - rects[cover_id].type();
                if (new_type != 3) {
                    rects[id] = {new_type, rects[id].y1, new_type, rects[id].y2};
                }
            }
            lefts.erase({rects[id].y1, id});
        }
    }
    vector<set<int>> active(3);
    vector<int> taken(3, -1);
    vector<Rect> ans(n);
    for (int i = 0; i < L; i++) {
        for (int id : in[i]) {
            active[rects[id].type()].insert(id);
        }
        if (taken[0] == -1) {
            if (!active[0].empty()) {
                taken[0] = *active[0].begin();
                //cout << "take " << taken[0] << " at " << tmp[i] << " as 0\n";
                ans[taken[0]].y1 = tmp[i];
                ans[taken[0]].x1 = 1;
                ans[taken[0]].x2 = 2;
                for (int it = 1; it <= 2; it++) {
                    if (taken[it] != -1) {
                        //cout << "cut " << taken[it] << " at " << tmp[i - 1] << "\n";
                        ans[taken[it]].y2 = tmp[i] - 1;
                        taken[it] = -1;
                    }
                }
            } else {
                for (int it = 1; it <= 2; it++) {
                    if (taken[it] == -1 && !active[it].empty()) {
                        taken[it] = *active[it].begin();
                        ans[taken[it]].y1 = tmp[i];
                        ans[taken[it]].x1 = ans[taken[it]].x2 = it;
                        //cout << "take " << taken[it] << " at " << tmp[i] << " as " << it << "\n";
                    }
                }
            }
        }
        for (int id : out[i]) {
            active[rects[id].type()].erase(id);
            if (id == taken[rects[id].type()]) {
                //cout << "cut " << taken[rects[id].type()] << " at " << tmp[i] << "\n";
                ans[taken[rects[id].type()]].y2 = tmp[i];
                taken[rects[id].type()] = -1;
            }
        }
    }
    int S = 0;
    for (auto &[x1, y1, x2, y2] : ans) {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
            continue;
        }
        S += (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    cout << S << '\n';
    for (auto &[x1, y1, x2, y2] : ans) {
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
