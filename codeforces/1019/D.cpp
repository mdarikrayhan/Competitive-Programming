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
    bool operator < (point p){
        if(y!=p.y) return y < p.y;
        return x < p.x;
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

double ang(point p){
    double r = atan2(p.y,p.x);
    if(r<0) r += 2 * acos(-1);
    return r;
}

ll cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

struct node{
    int u,v; double k;
    bool operator < (node p){
        return k < p.k;
    }
};

void Solve()
{
    int n;
    ll S;
    cin>>n>>S;
    S<<=1;
    vector<point>v(n+1);
    vector<int>pos(n+1);
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        v[i]=point(x,y);
        pos[i]=i;
    }
    sort(v.begin()+1,v.end());
    vector<node>seg(n*(n-1)+1);
    int m=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i==j) continue;
            seg[++m]={i,j,ang(v[j]-v[i])};
        }
    }
    sort(seg.begin()+1,seg.end());
    for(int k=1;k<=m;k++)
    {
        int &i=pos[seg[k].u],&j=pos[seg[k].v];
        int l=1,r=n+1;
        while(r>l+1)
        {
            int mid=(l+r)/2;
            if(cross(v[i]-v[mid],v[j]-v[mid])<=S) l=mid;
            else r=mid;
        }
        if(cross(v[i]-v[l],v[j]-v[l])==S)
        {
            cout<<"Yes"<<endl;
            cout<<v[i].x<<' '<<v[i].y<<endl;
            cout<<v[j].x<<' '<<v[j].y<<endl;
            cout<<v[l].x<<' '<<v[l].y<<endl;
            return;
        }
        swap(i,j);
        swap(v[i],v[j]);
    }
    cout<<"No"<<endl;
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
