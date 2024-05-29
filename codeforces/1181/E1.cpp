#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1001;
int n;
struct Rec {
    int a, b, c, d;
};
vector<Rec> rec;
bool split(vector<int> &r) {
    if (r.size() <= 1) {
        return 1;
    }
    vector<pair<int, int>> h, v;
    for (int i = 0; i < r.size(); i++) {
        h.push_back({rec[r[i]].a, 1});
        h.push_back({rec[r[i]].c, -1});
        v.push_back({rec[r[i]].b, 1});
        v.push_back({rec[r[i]].d, -1});
    }
    sort(begin(h), end(h));
    sort(begin(v), end(v));
    vector<int> p1, p2;
    int cnt = h[0].second, br = -1;
    for (int i = 1; i < h.size() - 1; i++) {
        cnt += h[i].second;
        if (cnt == 0) {
            br = h[i].first;
            break;
        }
    }
    if (br != -1) {
        for (int i = 0; i < r.size(); i++) {
            if (rec[r[i]].c <= br) {
                p1.push_back(r[i]);
            } else {
                p2.push_back(r[i]);
            }
        }
        return split(p1) && split(p2);
    }
    cnt = v[0].second, br = -1;
    for (int i = 1; i < v.size() - 1; i++) {
        cnt += v[i].second;
        if (cnt == 0) {
            br = v[i].first;
            break;
        }
    }
    if (br != -1) {
        for (int i = 0; i < r.size(); i++) {
            if (rec[r[i]].d <= br) {
                p1.push_back(r[i]);
            } else {
                p2.push_back(r[i]);
            }
        }
        return split(p1) && split(p2);
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rec.resize(n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
        cin >> rec[i].a >> rec[i].b >> rec[i].c >> rec[i].d;
    }
    if (split(v)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}