#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using point_t = long double; //全局数据类型，可修改为 long long 等

const point_t eps = 1e-11;
const long double PI = acosl(-1);
//const long double PI = numbers::pi_v<long double>;

// 点与向量
template <typename T>
struct point{
    T x, y;

    bool operator==(const point &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
    bool operator<(const point &a) const{
        if (abs(x - a.x) <= eps)
            return y < a.y - eps;
        return x < a.x - eps;
    }
    bool operator>(const point &a) const { return !(*this < a || *this == a); }
    point operator+(const point &a) const { return {x + a.x, y + a.y}; }
    point operator-(const point &a) const { return {x - a.x, y - a.y}; }
    point operator-() const { return {-x, -y}; }
    point operator*(const T k) const { return {k * x, k * y}; }
    point operator/(const T k) const { return {x / k, y / k}; }
    T operator*(const point &a) const { return x * a.x + y * a.y; } // 点积
    T operator^(const point &a) const { return x * a.y - y * a.x; } // 叉积，注意优先级
    int toleft(const point &a) const
    {
        const auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    }                                                             // to-left 测试
    T len2() const { return (*this) * (*this); }                  // 向量长度的平方
    T dis2(const point &a) const { return (a - (*this)).len2(); } // 两点距离的平方

    // 涉及浮点数
    long double len() const { return sqrtl(len2()); }                                                                      // 向量长度
    long double dis(const point &a) const { return sqrtl(dis2(a)); }                                                       // 两点距离
    long double ang(const point &a) const { return acosl(max(-1.0l, min(1.0l, ((*this) * a) / (len() * a.len())))); }      // 向量夹角
    point rot(const long double rad) const { return {x * cosl(rad) - y * sinl(rad), x * sinl(rad) + y * cosl(rad)}; }          // 逆时针旋转（给定角度）
    point rot(const long double cosr, const long double sinr) const { return {x * cosr - y * sinr, x * sinr + y * cosr}; } // 逆时针旋转（给定角度的正弦与余弦）
};

using Point = point<point_t>;

// 极角排序
struct argcmp
{
    bool operator()(const Point &a, const Point &b) const
    {
        const auto quad = [](const Point &a)
        {
            if (a.y < -eps)
                return 1;
            if (a.y > eps)
                return 4;
            if (a.x < -eps)
                return 5;
            if (a.x > eps)
                return 3;
            return 2;
        };
        const int qa = quad(a), qb = quad(b);
        if (qa != qb)
            return qa < qb;
        const auto t = a ^ b;
        // if (abs(t)<=eps) return a*a<b*b-eps;  // 不同长度的向量需要分开
        return t > eps;
    }
};

// 直线
template <typename T>
struct line
{
    point<T> p, v; // p 为直线上一点，v 为方向向量

    bool operator==(const line &a) const { return v.toleft(a.v) == 0 && v.toleft(p - a.p) == 0; }
    int toleft(const point<T> &a) const { return v.toleft(a - p); } // to-left 测试
    bool operator<(const line &a) const                             // 半平面交算法定义的排序
    {
        if (abs(v ^ a.v) <= eps && v * a.v >= -eps)
            return toleft(a.p) == -1;
        return argcmp()(v, a.v);
    }

    // 涉及浮点数
    point<T> inter(const line &a) const { return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v)); } // 直线交点
    long double dis(const point<T> &a) const { return abs(v ^ (a - p)) / v.len(); }         // 点到直线距离
    point<T> proj(const point<T> &a) const { return p + v * ((v * (a - p)) / (v * v)); }    // 点在直线上的投影
    point<T> symmetry(const point<T> &a) const { return proj(a) * 2 - a;}                    // 点关于直线的对称点 
};

using Line = line<point_t>;

//线段
template <typename T>
struct segment
{
    point<T> a, b;

    bool operator<(const segment &s) const { return make_pair(a, b) < make_pair(s.a, s.b); }

    // 判定性函数建议在整数域使用

    // 判断点是否在线段上
    // -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
    int is_on(const point<T> &p) const
    {
        if (p == a || p == b)
            return -1;
        return (p - a).toleft(p - b) == 0 && (p - a) * (p - b) < -eps;
    }

    // 判断线段直线是否相交
    // -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
    int is_inter(const line<T> &l) const
    {
        if (l.toleft(a) == 0 || l.toleft(b) == 0)
            return -1;
        return l.toleft(a) != l.toleft(b);
    }

    // 判断两线段是否相交
    // -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
    int is_inter(const segment<T> &s) const
    {
        if (is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b))
            return -1;
        const line<T> l{a, b - a}, ls{s.a, s.b - s.a};
        return l.toleft(s.a) * l.toleft(s.b) == -1 && ls.toleft(a) * ls.toleft(b) == -1;
    }

    // 点到线段距离
    long double dis(const point<T> &p) const
    {
        if ((p - a) * (b - a) < -eps || (p - b) * (a - b) < -eps)
            return min(p.dis(a), p.dis(b));
        const line<T> l{a, b - a};
        return l.dis(p);
    }

    // 两线段间距离
    long double dis(const segment<T> &s) const
    {
        if (is_inter(s))
            return 0;
        return min({dis(s.a), dis(s.b), s.dis(a), s.dis(b)});
    }

    // 只求整点交点可以不使用浮点数,避免精度问题,使用前需要先判断是否有交点 
    pair<bool, point<T> > int_inter(const segment &s){

        // 线段转为直线的一般式
        auto seg2line = [&](const segment &s){
            T A = s.a.y - s.b.y;
            T B = s.b.x - s.a.x;
            T C = -A * s.a.x - B * s.a.y;
            return array{A, B, C};
        };

        auto [A1, B1, C1] = seg2line(*this);
        auto [A2, B2, C2] = seg2line(s);
        T dx = C1 * B2 - C2 * B1;
        T dy = A1 * C2 - A2 * C1;
        T d = B1 * A2 - B2 * A1;
        if (d == 0) return {false, {}};
        if (dy % d || dx % d) return {false, {}};
        return {true, {dx / d, dy / d}};
    }

};
using Segment = segment<point_t>;

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<Point> p(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p[i] = {1.0L * x, 1.0L * y};
    }
    long double z1, z2, z3;
    Point s;
    cin >> s.x >> s.y;
    for(auto &pt : p){
        pt = pt - s;
    }
    Point v1, v2;
    cin >> v1.x >> v1.y;
    cin >> z1 >> z2;
    z2 = -z2;
    cin >> v2.x >> v2.y >> z3;
    z3 = -z3;
    Point p1 = v1 + v2 * (z1 / z3);
    Point p2 = v2 * (-z2 / z3);

    const double INF = 1e9;
    long double x = INF, y = INF;

    for(int i = 0; i < n; i++){
        Segment s = {p[i], p[(i + 1) % n]};

        auto check = [&](long double mid){
            Point q1 = {0.0, 0.0};
            Point q2 = p1 * mid;
            Point q3 = q2 + p2 * (mid * z1 / z2);
            if ((q2 ^ q3) < 0) swap(q2, q3);
            Point q[3] = {q1, q2, q3};
            for(int i = 0; i < 3; i++){
                Segment ns = {q[i], q[(i + 1) % 3]};
                if (s.is_inter(ns) != 0){
                    return true;
                }
            }
            if (abs((q2 - q1) ^ (q3 - q1)) > eps){
                for(auto pt : {p[i], p[(i + 1) % n]}){
                    bool ok = true;
                    for(int i = 0; i < 3; i++){
                        ok &= ((q[(i + 1) % 3] - q[i]) ^ (pt - q[i])) > -eps;
                    }
                    if (ok){
                        return true;
                    }
                }
            }
            return false;
        };

        long double l = 0, r = INF;
        for(int j = 0; j < 100; j++){
            long double mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        if (r < INF / 2){
            long double xx = r, yy;
            {
                auto check = [&](long double mid){
                    Point q2 = p1 * xx;
                    Point q3 = q2 + p2 * mid;
                    Segment ss = {q2, q3};
                    return ss.is_inter(s) != 0;
                };

                long double l = 0, r = xx * z1 / z2;
                for(int j = 0; j < 100; j++){
                    long double mid = (l + r) / 2;
                    if (check(mid)) r = mid;
                    else l = mid;
                }
                yy = r;
            }
            if (xx < x || (abs(xx - x) < eps && yy < y)){
                x = xx;
                y = yy;
            }
        }
    }

    if (x > INF / 2){
        cout << -1 << ' ' << -1 << '\n';
        return 0;
    }
    cout << x << ' ' << y << '\n';

}