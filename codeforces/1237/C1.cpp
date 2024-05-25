#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using ll = long long;
using ld = long double;

// to_string implementations
string to_string(bool b);

string to_string(string s);

template <typename T, typename U>
string to_string(pair<T, U> p);

template <typename T, typename U, typename V>
string to_string(tuple<T, U, V> tp);

template <typename T>
string to_string(const T &c);

string to_string(bool b) {
    return b ? "true" : "false";
}

string to_string(string s) {
    return s;
}

template <typename T, typename U>
string to_string(pair<T, U> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename T, typename U, typename V>
string to_string(tuple<T, U, V> tp) {
    return "(" + to_string(get<0>(tp)) + ", " + to_string(get<1>(tp)) + ", " +
           to_string(get<2>(tp)) + ")";
}

template <typename T, typename U, typename V, typename W>
string to_string(tuple<T, U, V, W> tp) {
    return "(" + to_string(get<0>(tp)) + ", " + to_string(get<1>(tp)) + ", " +
           to_string(get<2>(tp)) + ", " +
           to_string(get<3>(tp)) + ")";
}

template <typename T>
string to_string(const T &c) {
    string out = "{";
    bool f = true;
    for (const auto &x : c) {
        if (f) {
            out += to_string(x);
            f = false;
            continue;
        }
        out += ", " + to_string(x);
    }
    out += "}";
    return out;
}

#define debug(v) \
    { cerr << #v << ' ' << to_string(v) << '\n'; }

void init_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    init_io();
    int n;
    cin >> n;
    vector<array<int, 4>> pts(n);
    for (int j = 0; j < n; j++) {
        int x, y, z;
        cin >> x >> y >> z;
        pts[j] = {x, y, z, j + 1};
    }
    sort(pts.begin(), pts.end());
    vector<bool> covered(n, false);
    for (int j = 0; j < n;) {
        int k = j;
        while (j < n and pts[j][0] == pts[k][0])
            j++;
        for (int p = k; p < j; p++) {
            if (p + 1 < j and pts[p][1] == pts[p + 1][1]) {
                cout << pts[p][3] << " " << pts[p + 1][3] << '\n';
                covered[p] = covered[p + 1] = true;
                p++;
            }
        }
        for (int p = k; p < j;) {
            if (!covered[p]) {
                int c = p;
                p++;
                while (p < j and covered[p])
                    p++;
                if (p != j) {
                    covered[c] = covered[p] = true;
                    cout << pts[c][3] << " " << pts[p][3] << '\n';
                }
            }
            else
                p++;
        }
    }
    for (int j = 0; j < n;) {
        if (!covered[j]) {
            int c = j;
            j++;
            while (j < n and covered[j])
                j++;
            covered[c] = covered[j] = true;
            cout << pts[c][3] << " " << pts[j][3] << '\n';
        }
        else
            j++;
    }
    // vector<pair<int, int>> ans;
    // for (auto &[x, pts] : x_pts) {
    //     sort(pts.begin(), pts.end());
    //     int n_pts = pts.size();
    //     for (int j = 0; j + 1 < n_pts; j += 2)
    //         ans.push_back();
    // }
    return 0;
}