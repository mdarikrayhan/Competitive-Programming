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
    ll x, y;
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

ll cross(point a, point b) {
    return abs(a.x *1LL* b.y - a.y *1LL* b.x);
}

void Solve()
{
    int n;
    ll k;
    cin>>n>>k;
    ll x,y,z;
    vector<point>v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(point(x,y));
    }
    int a=0,b=1,c=2;
    while(true)
    {
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            ll area=cross(v[a]-v[c],v[b]-v[c]);
            if(cross(v[b]-v[i],v[c]-v[i])>area) a=i,ok=false;
            if(cross(v[c]-v[i],v[a]-v[i])>area) b=i,ok=false;
            if(cross(v[a]-v[i],v[b]-v[i])>area) c=i,ok=false;
        }
        if(ok) break;
    }
    point A(v[a]+v[b]-v[c]),B(v[a]+v[c]-v[b]),C(v[b]+v[c]-v[a]);
    cout<<A.x<<' '<<A.y<<endl;
    cout<<B.x<<' '<<B.y<<endl;
    cout<<C.x<<' '<<C.y<<endl;
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
