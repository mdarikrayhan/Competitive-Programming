#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define endl "\n"
#define Amgad ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

const double EPS=1e-9;

struct point {
    double x, y;
    point() {}
    point(double x, double y): x(x), y(y) {}
    bool operator<(const point& p) const
    {
        return (x < p.x - EPS || abs(x - p.x) < EPS && y < p.y - EPS);
    }
    point& operator+=(const point &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point& operator-=(const point &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point& operator*=(double t) {
        x *= t;
        y *= t;
        return *this;
    }
    point& operator/=(double t) {
        x /= t;
        y /= t;
        return *this;
    }
    point operator+(const point &t) const {
        return point(*this) += t;
    }
    point operator-(const point &t) const {
        return point(*this) -= t;
    }
    point operator*(double t) const {
        return point(*this) *= t;
    }
    point operator/(double t) const {
        return point(*this) /= t;
    }
};

struct line {
    double a, b, c;

    line() {}
    line(point p, point q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        double z = sqrt(a * a + b * b);
        if (abs(z) > EPS)
            a /= z, b /= z, c /= z;
    }

    double dist2line(point p) const { return a * p.x + b * p.y + c; }
};

double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

double norm(point a) {
    return dot(a, a);
}

double dist(point a) {
    return sqrt(norm(a));
}

void Solve()
{
    int n;
    cin>>n;
    vector<point>v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(point(x,y));
    }
    double ans=1e18;
    for(int i=0;i<n;i++)
    {
        line L=line(v[(i-1+n)%n],v[(i+1)%n]);
        ans=min(ans,L.dist2line(v[i]));
    }
    cout<<fixed<<setprecision(12)<<ans/2<<endl;
}

int main()
{
    Amgad
    ll T=1;
    //cin>>T;
    while(T--)
    {
        Solve();
    }
}
