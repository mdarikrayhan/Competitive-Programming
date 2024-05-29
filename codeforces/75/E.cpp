#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define endl "\n"
#define Amgad ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

const double EPS=1e-9;

inline int sign(double a) {
	return a < -EPS ? -1 : a > EPS;
}

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
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
};

double cross(point a, point b) {
    return a.x * b.y - a.y *b.x;
}

double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

double norm(point a) {
    return dot(a, a);
}

double dist(point a) {
    return sqrt(norm(a));
}

int orient(point A,point B,point C)
{
    double ret=cross(A-C,B-C);
    if(abs(ret)<EPS) return 0;
    return ret<-EPS?-1:1;
}

point isSS(point p1, point p2, point q1, point q2) {
	double a1 = cross(p1-q1,q2-q1), a2 = -cross(p2-q1,q2-q1);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

bool inMid(point a, point m, point b, bool inc = false) {
	return orient(a,m,b) == 0 && sign(dot(m-a,m-b)) < (inc ? 1 : 0);
}

vector<point> convexCut(const vector<point>&ps, point q1, point q2) {
	vector<point> qs;
	int n = ps.size();
	for (int i = 0; i < n; ++i) {
		point p1 = ps[i], p2 = ps[(i + 1) % n];
		int d1 = orient(q1, q2, p1), d2 = orient(q1, q2, p2);
		if (d1 >= 0)
			qs.push_back(p1);
		if (d1 * d2 < 0)
			qs.push_back(isSS(p1, p2, q1, q2));
	}
	return qs;
}

void convex_hull(vector<point>& a) {
    point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const point& a, const point& b) {
        int o = orient(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*1LL*(p0.x-a.x) + (p0.y-a.y)*1LL*(p0.y-a.y)
                < (p0.x-b.x)*1LL*(p0.x-b.x) + (p0.y-b.y)*1LL*(p0.y-b.y);
        return o < 0;
    });

    int i = (int)a.size()-1;
    while (i >= 0 && orient(p0, a[i], a.back())==0) i--;
    reverse(a.begin()+i+1, a.end());

    vector<point> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && orient(st[st.size()-2], st.back(), a[i])>0)
            st.pop_back();
        st.push_back(a[i]);
    }
    a = st;
}

double calcPerimeter(vector<point>&ps) {
	int n = ps.size();
	double ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += dist(ps[i]-ps[(i+1)%n]);
	}
	return ret;
}

void Solve()
{
    point st,en;
    double x,y;
    cin>>x>>y;
    st=point(x,y);
    cin>>x>>y;
    en=point(x,y);
    int n;
    cin>>n;
    vector<point>v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(point(x,y));
    }
    convex_hull(v);
    vector<point>L=convexCut(v,st,en),R=convexCut(v,en,st);
    cout<<fixed<<setprecision(12);
    if((int)L.size()<3||R.size()<3) {cout<<dist(st-en)<<endl;return;}
    vector<point>is;
    for(int i=0;i<(int)L.size();i++)
    {
        if(inMid(st,L[i],en,true)) is.push_back(L[i]);
    }
    if((int)is.size()<2) {cout<<dist(st-en)<<endl;return;}
    if(dist(st-is[0])>dist(st-is[1])) swap(is[0],is[1]);
    double ans=dist(st-is[0])+dist(is[1]-en);
    double d=dist(is[0]-is[1]);
    ans+=min({2*d,calcPerimeter(L)-d,calcPerimeter(R)-d});
    cout<<ans<<endl;
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
