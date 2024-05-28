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

double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

double norm(point a) {
    return dot(a, a);
}

double dist(point a) {
    return sqrt(norm(a));
}

bool cmp(point a,point b)
{
    return a.x+a.y<b.x+b.y;
}

double arr[3005][3005];

void Solve()
{
    int n;
    double x,y;
    cin>>n;
    vector<point>v;
    for(int i=0;i<n;i++)
    {

        cin>>x>>y;
        v.push_back(point(x,y));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            arr[i][j]=dist(v[i]-v[j])/2;
        }
    }
    double ans=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            double ab=arr[i][j];
            if(ab+EPS<ans) continue;
            for(int k=j+1;k<n;k++)
            {
                double ac=arr[i][k];
                double bc=arr[j][k];
                ans=max(ans,min({ab,ac,bc}));
            }
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
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
