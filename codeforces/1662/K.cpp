#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ld pi = acos(-1);
ld epsilon = 1e-9;

struct vec2 {
    ld x, y;
    vec2(ld _x = 0, ld _y = 0) {x = _x; y = _y;}
    vec2(const vec2& other) {x = other.x; y = other.y;}
    vec2(const vec2& a, const vec2& b) {x = b.x - a.x; y = b.y - a.y;}  //creates A to B
    vec2& operator=(const vec2& other) {x = other.x; y = other.y; return *this;}
    vec2 operator-() const {return vec2(-x, -y);}
    vec2 operator+(const vec2& other) const {return vec2(x + other.x, y + other.y);}
    vec2& operator+=(const vec2& other) {*this = *this + other; return *this;}
    vec2 operator-(const vec2& other) const {return vec2(x - other.x, y - other.y);}
    vec2& operator-=(const vec2& other) {*this = *this - other; return *this;}
    vec2 operator*(ld other) const {return vec2(x * other, y * other);}
    vec2& operator*=(ld other) {*this = *this * other; return *this;}
    vec2 operator/(ld other) const {return vec2(x / other, y / other);}
    vec2& operator/=(ld other) {*this = *this / other; return *this;}

    ld lengthSq() const {return x * x + y * y;}
    ld length() const {return sqrt(lengthSq());}
    vec2 get_normal() const {return *this / length();}
    void normalize() {*this /= length();}   //actually normalizes this vector
    ld distSq(const vec2& other) const {return vec2(*this, other).lengthSq();}
    ld dist(const vec2& other) const {return sqrt(distSq(other));}

    ld dot(const vec2& other) const {return x * other.x + y * other.y;}
    ld cross(const vec2& other) const {return x * other.y - y * other.x;}
    ld angle_to(const vec2& other) const {return acos(dot(other) / length() / other.length());}
    vec2 rotate_CCW(ld theta) const {return vec2(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));}

    //angle from x axis in range (-pi, pi)
    ld polar_angle() {return atan2(y, x);}  

    //projection of other onto this. TODO see if we can get rid of sqrt
    vec2 project(const vec2& other) {vec2 t_n = get_normal(); return t_n * t_n.dot(other);}

    friend std::ostream& operator<<(std::ostream& os, const vec2& v) {os << "[" << v.x << ", " << v.y << "]"; return os;}
    friend std::istream& operator>>(std::istream& is, vec2& v) {is >> v.x >> v.y; return is;}
};
vec2 operator*(ld a, const vec2& b) {return vec2(a * b.x, a * b.y);}

ld cross(vec2 a, vec2 b) {
    return a.x * b.y - a.y * b.x;
}

ld dot(vec2 a, vec2 b) {
    return a.x * b.x + a.y * b.y;
}

ld lerp(ld t0, ld t1, ld x0, ld x1, ld t) {
    ld slope = (x1 - x0) / (t1 - t0);
    return x0 + slope * (t - t0);
}

vec2 lerp(ld t0, ld t1, vec2 x0, vec2 x1, ld t) {
    return vec2(lerp(t0, t1, x0.x, x1.x, t), lerp(t0, t1, x0.y, x1.y, t));
}

//returns the coefficients s and t, where p1 + v1 * s = p2 + v2 * t
vector<ld> lineLineIntersect(vec2 p1, vec2 v1, vec2 p2, vec2 v2) {
    if(cross(v1, v2) == 0){
        return {};
    }
    ld s = cross(p2 - p1, v2) / cross(v1, v2);
    ld t = cross(p1 - p2, v1) / cross(v2, v1);
    return {s, t};
}

vector<vec2> get_equipoints(vec2 p1, vec2 p2) {
    vec2 normalizing_vector = vec2((p1.x + p2.x) / (ld)2, (p1.y + p2.y) / (ld)2);
    p1 -= normalizing_vector;
    p2 -= normalizing_vector;

    vec2 perp_vector = vec2(p1.y,-p1.x);
    vec2 unit_perp = perp_vector / perp_vector.length();

    ld dist = p1.dist(p2) * sqrt((ld)3) / (ld)2;
    return {unit_perp * dist + normalizing_vector, unit_perp * -dist + normalizing_vector};
}

ld calc_r(vec2 p1, vec2 p2, vec2 p3, vec2 p4) {
    return p1.dist(p4) + p2.dist(p4) + p3.dist(p4);
}

ld find_r(vec2 p1, vec2 p2, vec2 p3) {
    vector<vector<vec2>> points(2);
    points[0] = get_equipoints(p1,p2);
    points[1] = get_equipoints(p2,p3);
    ld res = LDBL_MAX;
    for(int i = 0; i < 4; i++) {
        vec2 trypoint1 = points[0][i & 1];
        vec2 trypoint2 = points[1][i / 2];

        vec2 d1 = p3 - trypoint1;
        vec2 d2 = p1 - trypoint2;

        vector<ld> fermatalmost = lineLineIntersect(trypoint1, d1, trypoint2, d2);
        if(fermatalmost.size()) {
            vec2 p4 = trypoint1 + d1 * fermatalmost[0];
            res = min(res, calc_r(p1,p2,p3,p4));
        }
    }
    res = min(res, calc_r(p1,p2,p3,p1));
    res = min(res, calc_r(p1,p2,p3,p2));
    res = min(res, calc_r(p1,p2,p3,p3));
    return res;
}

ld get_r(vec2 p1, vec2 p2, vec2 p3, vec2 trypoint) {
    return max({find_r(p1,p2,trypoint),find_r(p1,p3,trypoint), find_r(p2,p3,trypoint)});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vec2 a, b, c; cin >> a >> b >> c;
    ld lox = min({a.x,b.x,c.x});
    ld hix = max({a.x,b.x,c.x});

    while(hix - lox > epsilon) {
        ld x1 = lox + (hix - lox) / 3;
        ld x2 = lox + (hix - lox) * 2 / 3;
        ld loy = min({a.y,b.y,c.y});
        ld hiy = max({a.y,b.y,c.y});
        while(hiy - loy > epsilon) {
            ld y1 = loy + (hiy - loy) / 3;
            ld y2 = loy + (hiy - loy) * 2 /3;
            vec2 v1 = vec2(x1,y1);
            vec2 v2 = vec2(x1,y2);
            if(get_r(a,b,c,v1) < get_r(a,b,c,v2)) {
                hiy = y2;
            } else {
                loy = y1;
            }
        }

        vec2 v1 = vec2(x1, loy);
        loy = min({a.y,b.y,c.y});
        hiy = max({a.y,b.y,c.y});
        while(hiy - loy > epsilon) {
            ld y1 = loy + (hiy - loy) / 3;
            ld y2 = loy + (hiy - loy) * 2 /3;
            vec2 v1 = vec2(x2,y1);
            vec2 v2 = vec2(x2,y2);
            if(get_r(a,b,c,v1) < get_r(a,b,c,v2)) {
                hiy = y2;
            } else {
                loy = y1;
            }
        }

        vec2 v2 = vec2(x2,loy);
        if(get_r(a,b,c,v1) < get_r(a,b,c,v2)) {
            hix = x2;
        } else {
            lox = x1;
        }
    }

    ld loy = min({a.y,b.y,c.y});
    ld hiy = max({a.y,b.y,c.y});
    while(hiy - loy > epsilon) {
        ld y1 = loy + (hiy - loy) / 3;
        ld y2 = loy + (hiy - loy) * 2 /3;
        vec2 v1 = vec2(lox,y1);
        vec2 v2 = vec2(lox,y2);
        if(get_r(a,b,c,v1) < get_r(a,b,c,v2)) {
            hiy = y2;
        } else {
            loy = y1;
        }
    }

    cout << fixed << setprecision(10) << get_r(a,b,c,vec2(lox,loy)) << '\n';
    
    // //correct here
    // vec2 p1 = vec2(0,0);
    // vec2 p2 = vec2(5,0);
    // vec2 p3 = vec2(3,3);
    // vec2 p4 = vec2(2.3842,0.4151);

    // cout << fixed << setprecision(8) << find_r(p1,p2,p4) << '\n';
    // cout << fixed << setprecision(8) << find_r(p2,p3,p4) << '\n';
    // cout << fixed << setprecision(8) << find_r(p1,p3,p4) << '\n';

    // vec2 p1 = vec2(5,0);
    // vec2 p2 = vec2(3,3);
    // vec2 p3 = vec2(2.3842,0.4151);

    // cout << fixed << setprecision(8) << find_r(p1,p2,p3) << '\n';

    return 0;
}