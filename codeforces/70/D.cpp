#include <bits/stdc++.h>

using point_t = long long;  // 全局数据类型

constexpr point_t eps = 0;
constexpr point_t INF = std::numeric_limits<point_t>::max();

// 点与向量
template <typename T>
struct point {
    T x, y;

    point(const T &x0 = 0, const T &y0 = 0) : x(x0), y(y0) {}
    bool operator==(const point &a) const { return (std::abs(x - a.x) <= eps && std::abs(y - a.y) <= eps); }
    bool operator<(const point &a) const {
        if (std::abs(x - a.x) <= eps) return y < a.y - eps;
        return x < a.x - eps;
    }
    bool operator>(const point &a) const { return !(*this < a || *this == a); }
    point operator+(const point &a) const { return {x + a.x, y + a.y}; }
    point operator-(const point &a) const { return {x - a.x, y - a.y}; }
    point operator-() const { return {-x, -y}; }
    point operator*(const T k) const { return {k * x, k * y}; }
    point operator/(const T k) const { return {x / k, y / k}; }
    T operator*(const point &a) const { return x * a.x + y * a.y; }     // 点积
    T operator^(const point &a) const { return x * a.y - y * a.x; }     // 叉积，注意优先级
    // to-left 测试 | 叉积判断
    int toleft(const point &a) const {
        const auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    }
    T len2() const { return (*this) * (*this); }                        // 向量长度的平方
    T dis2(const point &a) const { return (a - (*this)).len2(); }       // 两点距离的平方
};

using Point = point<point_t>;

// 不需要保证点都在第一象限
struct argcmp {
    bool operator()(const Point &a, const Point &b) const {
        const auto quad = [](const Point &a) {
            if (a.y < -eps) return 1;
            if (a.y > eps) return 4;
            if (a.x < -eps) return 5;
            if (a.x > eps) return 3;
            return 2;
        };
        const int qa = quad(a), qb = quad(b);
        if (qa != qb) return qa < qb;
        const auto t = a ^ b;
        if (abs(t) <= eps) return a * a < b * b - eps;  // 不同长度的向量需要分开
        return t > eps;
    }
};
 
class DynamicConvex {
public:
    std::set<Point, argcmp> hull;
    Point o;

    auto prev(std::set<Point>::iterator it, int n = 1) {
        while (n-- > 0) {
            if (it == hull.begin()) {
                it = std::prev(hull.end());
            } else {
                advance(it, -1);
            }
        }
        return it;
    }
 
    auto next(std::set<Point>::iterator it, int n = 1) {
        while (n-- > 0) {
            if (std::next(it) == hull.end()) {
                it = hull.begin();
            } else {
                advance(it, 1);
            }
        }
        return it;
    }
 
    bool outHull(Point b) {
        if (hull.size() <= 1) return true;
        b = b * 3 - o;
        auto it = hull.lower_bound(b);
        if (it == hull.end()) {
            it = hull.begin();
        }
        auto c = *it, a = *prev(it);
        return ((c - a) ^ (b - a)) < 0;
    }
 
    void insert(Point v) {
        // std::cout << hull.size() << std::endl;
        if (hull.size() <= 1) {
            hull.insert(v * 3);
            return;
        }
        if (hull.size() == 2) {
            Point a = *hull.begin(), b = *hull.rbegin();
            o = (a + b + v * 3) / 3;
            hull.clear();
            hull.insert(a - o);
            hull.insert(b - o);
            hull.insert(v * 3 - o);
            return;
        }
        if (!outHull(v)) return;
        v = v * 3 - o;
        hull.erase(v); // 方向相同的向量会被判为相等
        auto it = hull.insert(v).first;
        while ( ((*next(it) - *it) ^ (*next(it, 2) - *next(it))) <= 0) {
            hull.erase(*next(it));
        }
        while (((*prev(it) - *it) ^ (*prev(it, 2) - *prev(it))) >= 0) {
            hull.erase(*prev(it));
        }
    }  
};
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    DynamicConvex dch;
    int n, op, x, y;
    std::cin >> n;
    // for (int i = 0; i < 3; ++i)
    // {
    //     std::cin >> x >> x2[i] >> y2[i];
    // }
    // centerX = std::accumulate(x2, x2 + 3, 0);
    // centerY = std::accumulate(y2, y2 + 3, 0);
    // for (int i = 0; i < 3; ++i)
    // {
    //     dch.hull.emplace(x2[i] * 3 - centerX, y2[i] * 3 - centerY);
    // }
    // dch.o = Point(centerX, centerY);
    for (int i = 0; i < n; ++i) {
        std::cin >> op >> x >> y;
        Point v(x, y);
        if (op == 1) dch.insert(v);
        else std::cout << (dch.outHull(v) ? "NO" : "YES") << '\n';
    }
    return 0;
}