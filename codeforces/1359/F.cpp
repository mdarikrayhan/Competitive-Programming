// LUOGU_RID: 158240069
#include <bits/stdc++.h>
using namespace std;

using point_t = long double;  //全局数据类型，可修改为 long long 等

constexpr long double eps = 1e-12;
constexpr long double PI = 3.1415926535897932384l;

// x < y = -1 , x == y = 0 , x > y = 1;
int sgn(long double x, long double y)
{
    if (fabs(x - y) <= eps) return 0;
    else return x < y ? -1 : 1;
}

// 点与向量
template<typename T> struct point
{
    T x, y;

    bool operator==(const point& a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
    bool operator<(const point& a) const { if (abs(x - a.x) <= eps) return y < a.y - eps; return x < a.x - eps; }
    bool operator>(const point& a) const { return !(*this < a || *this == a); }
    point operator+(const point& a) const { return { x + a.x,y + a.y }; }
    point operator-(const point& a) const { return { x - a.x,y - a.y }; }
    point operator-() const { return { -x,-y }; }
    point operator*(const T k) const { return { k * x,k * y }; }
    point operator/(const T k) const { return { x / k,y / k }; }
    T operator*(const point& a) const { return x * a.x + y * a.y; }  // 点积
    T operator^(const point& a) const { return x * a.y - y * a.x; }  // 叉积，注意优先级
    int toleft(const point& a) const { const auto t = (*this) ^ a; return (t > eps) - (t < -eps); }  // to-left 测试
    T len2() const { return (*this) * (*this); }  // 向量长度的平方
    T dis2(const point& a) const { return (a - (*this)).len2(); }  // 两点距离的平方

    // 涉及浮点数
    long double len() const { return sqrtl(len2()); }  // 向量长度
    long double dis(const point& a) const { return sqrtl(dis2(a)); }  // 两点距离
    long double ang(const point& a) const { return acosl(max(-1.0l, min(1.0l, ((*this) * a) / (len() * a.len())))); }  // 向量夹角
    point rot(const long double rad) const { return { x * cos(rad) - y * sin(rad),x * sin(rad) + y * cos(rad) }; }  // 逆时针旋转（给定角度）
    point rot(const long double cosr, const long double sinr) const { return { x * cosr - y * sinr,x * sinr + y * cosr }; }  // 逆时针旋转（给定角度的正弦与余弦）
};

using Point = point<point_t>;

// 极角排序
struct argcmp
{
    bool operator()(const Point& a, const Point& b) const
    {
        const auto quad = [] (const Point& a)
        {
            if (a.y < -eps) return 1;
            if (a.y > eps) return 4;
            if (a.x < -eps) return 5;
            if (a.x > eps) return 3;
            return 2;
        };
        const int qa = quad(a), qb = quad(b);
        if (qa != qb) return qa < qb;
        const auto t = a ^ b;
        // if (abs(t)<=eps) return a*a<b*b-eps;  // 不同长度的向量需要分开
        return t > eps;
    }
};

// 直线
template<typename T> struct line
{
    point<T> p, v;  // p 为直线上一点，v 为方向向量

    bool operator==(const line& a) const { return v.toleft(a.v) == 0 && v.toleft(p - a.p) == 0; }
    int toleft(const point<T>& a) const { return v.toleft(a - p); }  // to-left 测试
    bool operator<(const line& a) const  // 半平面交算法定义的排序
    {
        if (abs(v ^ a.v) <= eps && v * a.v >= -eps) return toleft(a.p) == -1;
        return argcmp()(v, a.v);
    }

    // 涉及浮点数
    point<T> inter(const line& a) const { return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v)); }  // 直线交点
    long double dis(const point<T>& a) const { return abs(v ^ (a - p)) / v.len(); }  // 点到直线距离
    point<T> proj(const point<T>& a) const { return p + v * ((v * (a - p)) / (v * v)); }  // 点在直线上的投影
};

using Line = line<point_t>;

//线段
template<typename T> struct segment
{
    point<T> a, b;

    bool operator<(const segment& s) const { return make_pair(a, b) < make_pair(s.a, s.b); }

    // 判定性函数建议在整数域使用

    // 判断点是否在线段上
    // -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
    int is_on(const point<T>& p) const
    {
        if (p == a || p == b) return -1;
        return (p - a).toleft(p - b) == 0 && (p - a) * (p - b) < -eps;
    }

    // 判断线段直线是否相交
    // -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
    int is_inter(const line<T>& l) const
    {
        if (l.toleft(a) == 0 || l.toleft(b) == 0) return -1;
        return l.toleft(a) != l.toleft(b);
    }

    // 判断两线段是否相交
    // -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
    int is_inter(const segment<T>& s) const
    {
        if (is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b)) return -1;
        const line<T> l{ a,b - a }, ls{ s.a,s.b - s.a };
        return l.toleft(s.a) * l.toleft(s.b) == -1 && ls.toleft(a) * ls.toleft(b) == -1;
    }

    // 点到线段距离
    long double dis(const point<T>& p) const
    {
        if ((p - a) * (b - a) < -eps || (p - b) * (a - b) < -eps) return min(p.dis(a), p.dis(b));
        const line<T> l{ a,b - a };
        return l.dis(p);
    }

    // 两线段间距离
    long double dis(const segment<T>& s) const
    {
        if (is_inter(s)) return 0;
        return min({ dis(s.a),dis(s.b),s.dis(a),s.dis(b) });
    }
};

using Segment = segment<point_t>;

// 判断多条线段是否有交点
// 扫描线，复杂度 O(nlogn)
bool segs_inter(const vector<Segment>& segs)
{
    if (segs.empty()) return false;
    using seq_t = tuple<point_t, int, Segment>;
    const auto seqcmp = [] (const seq_t& u, const seq_t& v)
    {
        const auto [u0, u1, u2] = u;
        const auto [v0, v1, v2] = v;
        if (abs(u0 - v0) <= eps) return make_pair(u1, u2) < make_pair(v1, v2);
        return u0 < v0 - eps;
    };
    vector<seq_t> seq;
    for (auto seg : segs)
    {
        if (seg.a.x > seg.b.x + eps) swap(seg.a, seg.b);
        seq.push_back({ seg.a.x,0,seg });
        seq.push_back({ seg.b.x,1,seg });
    }
    sort(seq.begin(), seq.end(), seqcmp);
    point_t x_now;
    auto cmp = [&] (const Segment& u, const Segment& v)
    {
        if (abs(u.a.x - u.b.x) <= eps || abs(v.a.x - v.b.x) <= eps) return u.a.y < v.a.y - eps;
        return ((x_now - u.a.x) * (u.b.y - u.a.y) + u.a.y * (u.b.x - u.a.x)) * (v.b.x - v.a.x) < ((x_now - v.a.x) * (v.b.y - v.a.y) + v.a.y * (v.b.x - v.a.x)) * (u.b.x - u.a.x) - eps;
    };
    multiset<Segment, decltype(cmp)> s{ cmp };
    for (const auto [x, o, seg] : seq)
    {
        x_now = x;
        const auto it = s.lower_bound(seg);
        if (o == 0)
        {
            if (it != s.end() && seg.is_inter(*it)) return true;
            if (it != s.begin() && seg.is_inter(*prev(it))) return true;
            s.insert(seg);
        }
        else
        {
            if (next(it) != s.end() && it != s.begin() && (*prev(it)).is_inter(*next(it))) return true;
            s.erase(it);
        }
    }
    return false;
}

int n;
void solve()
{
    cin >> n;
    vector<Line> pos(n);
    vector<int> st(n);
    for (int i = 0; i < pos.size(); i++)
    {
        Point p;
        cin >> p.x >> p.y;
        Point v;
        cin >> v.x >> v.y;
        pos[i] = { p , v };
        cin >> st[i];
    }
    point_t l = 0, r = 1e12;
    point_t ans = -1;
    while (r - l > 1e-8)
    {
        point_t mid = (l + r) / 2;
        vector<Segment> s(n);
        for (int i = 0; i < s.size(); i++)
        {
            Point u = pos[i].p;
            Point v = pos[i].p + pos[i].v / pos[i].v.len() * st[i] * mid;
            s[i] = { u,v };
        }
        if (segs_inter(s)) ans = mid, r = mid - eps;
        else l = mid + eps;
    }
    if (sgn(ans, -1) == 0) printf("No show :(\n");
    else printf("%.10Lf\n", ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}