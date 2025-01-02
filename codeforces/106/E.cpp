#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Point{
    double x, y, z;
};
double dist(Point a, Point b){
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}
signed main()
{
    int n;
    double x,y,z;
    cin>>n;
    vector<Point> P;
    double miX=1e9,maX=-1e9,miY=1e9,maY=-1e9,miZ=1e9,maZ=-1e9; 
    for(int i=0; i<n; i++) {
        cin>>x>>y>>z;
        miX = min(miX,x);
        maX = max(maX,x);
        miY = min(miY,y);
        maY = max(maY,y);
        miZ = min(miZ,z);
        maZ = max(maZ,z);
        P.pb({x,y,z});
    }
    
    Point Res;
    Res.x = uniform_real_distribution<double>(miX,maX)(rng);
    Res.y = uniform_real_distribution<double>(miY,maY)(rng);
    Res.z = uniform_real_distribution<double>(miZ,maZ)(rng);
    
    double tmp = 1.;
    for(int i=0;i<100000;i++){
        int ind=0;
        for(int i=0;i<n;i++){
            if(dist(Res,P[i])>dist(Res,P[ind]))ind=i;
        }
        // entonces quiero acercarme a P[ind]
        Res.x += (P[ind].x-Res.x) * tmp;
        Res.y += (P[ind].y-Res.y) * tmp;
        Res.z += (P[ind].z-Res.z) * tmp;
        tmp*=0.999;
    }
    cout<<fixed<<setprecision(10);
    cout<<Res.x<<" "<<Res.y<<" "<<Res.z<<endl;
    
    return 0;
}

// claramente Clara no me queria