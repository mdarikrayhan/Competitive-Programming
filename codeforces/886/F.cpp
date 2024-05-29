#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int inf = 2e18;
const double eps = 1e-12;
const double PI = acos(-1.0);

template<class T>
struct pt {
    T x, y;
    pt() { x = 0, y = 0; }
    pt(T x, T y): x(x), y(y) {}
    pt& operator+=(const pt &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    pt& operator-=(const pt &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    pt& operator*=(T t) {
        x *= t;
        y *= t;
        return *this;
    }
    pt& operator/=(T t) {
        x /= t;
        y /= t;
        return *this;
    }
    pt operator+(const pt &t) const {
        return pt(*this) += t;
    }
    pt operator-(const pt &t) const {
        return pt(*this) -= t;
    }
    pt operator*(T t) const {
        return pt(*this) *= t;
    }
    pt operator/(T t) const {
        return pt(*this) /= t;
    }
    bool operator ==(const pt<T>& o) {
        return x == o.x && y == o.y;
    }
    template<class U = T> typename enable_if<is_same<U, double>::value, bool>::type operator ==(const pt<T>&o) {
        return abs(x-o.x) < eps && abs(y-o.y) < eps;
    }
};
template<class T>
pt<T> make_vec(pt<T> a, pt<T> b) {
    return {b.x - a.x, b.y - a.y};
}

bool balanced(const vector<int>& a) {
    for (int l = 0, r = a.size()-1; l < r; l++, r--) {
        if (a[l] != -a[r]) return false;
    }
    return true;
}

int n;
inline long long GCD(long long a,long long b){return b==0?a:GCD(b,a%b);}

void solve() {
    cin >> n;
    pt<int> center;
    vector<pt<int>> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
        center += pts[i];
        pts[i] *= n;
    }

    vector<bool> del(n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (pts[i]+pts[j] == center*2) {
                del[i] = del[j] = true;
            }
        }
    }
    {
        auto PTS = pts;
        pts.clear();
        for (int i = 0; i < n; i++) if (!del[i]) {
            pts.push_back(PTS[i]);
        }
        n = pts.size();
    }
    if (!n) {
        cout << -1 << '\n';
        return;
    }

    map<pair<int, int>, bool> counted;
    int ans = 0;
    for (int i = 0; i < n; i++) pts[i] -= center;
    // for (int i = 0; i < n; i++) cerr << pts[i].x << ' ' << pts[i].y << endl;
    for (int i = 0; i < n; i++) {
        int dx = -(pts[0].y + pts[i].y), dy = pts[0].x + pts[i].x;
        {
            // cerr << "called w " << dx << ' ' << dy << endl;
            int gc = gcd(dx, dy);
            dx /= gc, dy /= gc;
        }
        if (dx<0) {
            dx *= -1;
            dy *= -1;
        }
        if (dx == 0 && dy < 0) dy *= -1;

        if (counted[{dx, dy}]) continue;
        counted[{dx, dy}] = true;

        vector<int> proj(n);
        for (int j = 0; j < n; j++) proj[j] = dx*pts[j].x + dy*pts[j].y;
        sort(begin(proj), end(proj));
        if (balanced(proj)) ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();    
}
