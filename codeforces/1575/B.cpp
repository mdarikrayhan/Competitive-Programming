#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
// typedef __int128 lll;
// typedef __float128 lld;
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

    //projection of other onto this
    vec2 project(const vec2& other) {return *this * (other.dot(*this) / dot(*this));}

    friend std::ostream& operator<<(std::ostream& os, const vec2& v) {os << "[" << v.x << ", " << v.y << "]"; return os;}
    friend std::istream& operator>>(std::istream& is, vec2& v) {is >> v.x >> v.y; return is;}
};
vec2 operator*(ld a, const vec2& b) {return vec2(a * b.x, a * b.y);}

int calc_amt(vector<vec2>& a, ld r) {
    vector<pair<ld, int>> e(0);
    int ans = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i].x == 0 && a[i].y == 0){
            ans ++;
            continue;
        }
        ld pang = a[i].polar_angle();
        ld x = a[i].length();
        if(x > r * 2){
            continue;
        }
        ld cang = acos(x / (2.0 * r));
        // cout << "ANG : " << pang << " " << cang << "\n";
        e.push_back({pang - cang, i + 1});
        e.push_back({pang + cang, -(i + 1)});
    }
    for(int i = 0; i < e.size(); i++){
        while(e[i].first < -pi) {
            e[i].first += 2 * pi;
        }
        while(e[i].first > pi) {
            e[i].first -= 2 * pi;
        }
    }
    sort(e.begin(), e.end());
    int cnt = 0;
    vector<int> s(a.size() + 1, 0);
    for(int i = 0; i < e.size() * 2; i++){
        int next = e[i % e.size()].second;
        if(next < 0){
            next = -next;
            if(s[next] == 1){
                cnt --;
            }
            s[next] = 0;
        }
        else {
            s[next] = 1;
            cnt ++;
        }
        // cout << "EVENT : " << e[i % e.size()].first << " " << e[i % e.size()].second << "\n";
        ans = max(ans, cnt);
    }
    // cout << "CALC AMT : " << r << " " << ans << "\n";
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<vec2> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }
    ld low = 0;
    ld high = 3 * 1e5;
    ld ans = high;
    while(high - low > 1e-6) {
        ld mid = (high + low) / 2.0;
        if(calc_amt(a, mid) >= k) {
            ans = min(ans, mid);
            high = mid;
        }
        else {
            low = mid;
        }
    }
    cout << fixed << setprecision(10) << ans << "\n";
    
    return 0;
}