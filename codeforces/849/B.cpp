#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-18;
const double PI = acos(-1.0);
using f64 = long double;
//判断数的符号，负数返回-1，0返回0，正数返回1
int sgn(f64 x) { return x < -eps ? -1 : x > eps; }
int compare(f64 a, f64 b) { return sgn(a - b); }
struct Point {
    f64 x, y;
    Point() = default;
    Point(f64 _x, f64 _y) : x{_x}, y{_y} {}
    Point &operator+=(Point rhs) { return x += rhs.x, y += rhs.y, *this; }
    Point &operator-=(Point rhs) { return x -= rhs.x, y -= rhs.y, *this; }
    Point &operator*=(f64 rhs) { return x *= rhs, y *= rhs, *this; }
    Point &operator/=(f64 rhs) { return x /= rhs, y /= rhs, *this; }
    Point operator-() { return Point(-x, -y); }
    friend Point operator+(Point a, Point b) { return a += b; }
    friend Point operator-(Point a, Point b) { return a -= b; }
    friend Point operator*(Point a, f64 b) { return a *= b; }
    friend Point operator/(Point a, f64 b) { return a /= b; }
    friend bool operator==(Point a, Point b) { return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0; }
    friend bool operator<(Point a, Point b) {
        if (compare(a.x, b.x) == 0) return compare(a.y, b.y) < 0;
        return compare(a.x, b.x) < 0; 
    }
};
//点积 P · Q == |P| * |Q| * cos(θ)
f64 dot(Point p, Point q) { return p.x * q.x + p.y * q.y; }
//叉积 P × Q == |P| * |Q| * sin(θ)
f64 alpha(Point p) { return atan2l(p.y, p.x); }
f64 cross(Point p, Point q) { return p.x * q.y - p.y * q.x; }
f64 square(Point p) { return dot(p, p); }
//向量p的模长
f64 length(Point p) { return sqrt(square(p)); }
//p, q之间的距离
f64 distance(Point p, Point q) { return length(q - p); }
//向量p的单位向量
Point unit(Point p) { return p / length(p); }
//两向量的夹角
f64 angle(Point p, Point q) { return acosl(dot(p, q) / length(p) / length(q)); }
//点p绕点o逆时针旋转90°
Point rotate90(Point p, Point o) {
    Point v = p - o;
    return o + Point{-v.y, v.x};
}
//点p绕点o逆时针旋转 rad°
Point rotate(Point p, f64 rad, Point o) {
    Point v = p - o;
    f64 s = sin(rad), c = cos(rad);
    return o + Point{v.x * c - v.y * s, v.x * s + v.y * c};
}
// 极角排序
struct argcmp1 {
    bool operator()(Point p, Point q) {
        auto rank = [&](Point p) {
            if (sgn(p.y) < 0) return 1;
            if (sgn(p.y) > 0) return 4;
            if (sgn(p.x) < 0) return 5;
            if (sgn(p.x) > 0) return 3;
            return 2;
        };
        if (rank(p) == rank(q)) return sgn(cross(p, q)) > 0;
        return rank(p) < rank(q);
    }
};
struct argcmp2 {
    bool operator()(Point p, Point q) {
        if (sgn(atan2(p.y, p.x) - atan2(q.y, q.x)) != 0) {
            return atan2(p.y, p.x) < atan2(q.y, q.x);
        }
        return p.x < q.x;
    }
};
struct Line {
    Point a, b;
    Line(Point _a, Point _b) : a(_a), b(_b) {}
};

// 1表示在直线左侧，0表示在直线上，-1表示在直线右侧
int toLeft(Point p, Line l) { return sgn(cross(l.b - l.a, p - l.a)); }
//判断点是否在线段上
bool onSegment(Point p, Line s) {
    return sgn(cross(p - s.a, s.b - s.a)) == 0 &&
           sgn(min(s.a.x, s.b.x) - p.x) <= 0 &&
           sgn(max(s.a.x, s.b.x) - p.x) >= 0 &&
           sgn(min(s.a.y, s.b.y) - p.y) <= 0 &&
           sgn(max(s.a.y, s.b.y) - p.y) >= 0;
}
//判断两直线是否平行
bool LineParallel(Line l1, Line l2) {
    return sgn(cross(l1.a - l1.b, l2.a - l2.b)) == 0;
}
//判断两直线是否垂直
bool LineVertical(Line l1, Line l2) {
    return sgn(dot(l1.a - l1.b, l2.a - l2.b)) == 0;
}
//判断两直线是否相交(-1 重合，0不相交，1 相交)
int lineCrossLine(Line l1, Line l2) {
    if (LineParallel(l1, l2)) {
        if (toLeft(l1.a, l2) == 0) return -1;
        else return 0;
    } else {
        return 1;
    }
}
//直线L1和直线L2的交点
Point crossPoint(Line l1, Line l2) {
    f64 t = cross(l2.b - l2.a, l1.a - l2.a) / cross(l1.b - l1.a, l2.b - l2.a);
    return l1.a + (l1.b - l1.a) * t;
}

// 点 P 到直线 L 的距离
f64 distanceToLine(Point p, Line l) {
    return fabs(cross(l.b - l.a, p - l.a) / length(l.b - l.a));
}
// 点 P 到线段 S 的最短距离
f64 distanceToSegment(Point p, Line s) {
    if (s.a == s.b) return length(p - s.a);
    if (sgn(dot(s.b - s.a, p - s.a)) < 0) return length(p - s.a);
    if (sgn(dot(s.a - s.b, p - s.b)) < 0) return length(p - s.b);
    return distanceToLine(p, s); 
}
//点 p 在直线L上的投影点
Point projectPoint(Point p, Line l) {
    return l.a + (l.b - l.a) * dot(l.b - l.a, p - l.a) / square(l.b - l.a);
}

//多边形相关
f64 area(vector<Point> ps) {
    f64 res = 0;
    int n = ps.size();
    for (int i = 0; i < n; i ++) res += cross(ps[i], ps[(i + 1) % n]);
    return res / 2;
}

//2:在多边形上 1:在多边形内 0:在多边形外
int pointInPolygon(Point p, vector<Point> ps) {
    int n = ps.size();
    for (int i = 0; i < n; i ++) {
        if (onSegment(p, Line{ps[i], ps[(i + 1) % n]})) {
            return 2;
        }
    }
    int t = 0;
    for (int i = 0; i < n; i ++) {
        auto u = ps[i], v = ps[(i + 1) % n];
        if (u.x < p.x && v.x >= p.x && toLeft(p, Line{v, u})) {
            t ^= 1;
        }
        if (u.x >= p.x && v.x < p.x && toLeft(p, Line{u, v})) {
            t ^= 1;
        }
    }
    return t == 1;
}
//flag为1时表示严格凸包，flag为0时表示不严格凸包
vector<Point> staticConvex(vector<Point> ps, int flag) {
    int n = ps.size();
    vector<Point> ans(n * 2);
    sort(ps.begin(), ps.end());
    int now = -1;
    for (int i = 0; i < n; i ++) {
        while (now > 0 && toLeft(ps[i], Line{ans[now - 1], ans[now]}) < flag) now --;
        ans[++now] = ps[i]; 
    }
    int pre = now;
    for (int i = n - 2; i >= 0; i --) {
        while (now > pre && toLeft(ps[i], Line{ans[now - 1], ans[now]}) < flag) now --;
        ans[++now] = ps[i];
    }
    ans.resize(now);
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<Point> p(n + 1);
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        p[i] = {i, x};
    }

    auto func = [&](int i, int j) -> bool {
        int ok1 = 0, ok2 = 0;
        Point x{}, y{};
        int cnt = 0;
        for (int k = 1; k <= n; k ++) {
            if (k == i || k == j) continue;
            if (toLeft(p[k], Line{p[i], p[j]}) == 0) {
                continue;
            } else if (!ok1) {
                x = p[k];
                ok1 = true;
                cnt ++;
            } else if (!ok2) {
                y = p[k];
                ok2 = true;
                cnt ++;
                if (!LineParallel(Line{p[i], p[j]}, Line{x, y})) return false;
            } else if (toLeft(p[k], Line{x, y}) == 0) {
                cnt ++;
            } else {
                return false;
            }
        }
        return cnt > 0;
    };
    
    if (func(1, 2) || func(1, 3) || func(2, 3)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
