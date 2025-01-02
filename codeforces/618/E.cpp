#include <bits/stdc++.h>
using namespace std;
// 19/20
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define testcase(...) 42
#endif

#define int long long int

#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll,ll>
#define all(x) (x).begin(),(x).end()
template<typename T> using min_heap = priority_queue<T,vector<T>,greater<T>>;
template<typename T> using max_heap = priority_queue<T>;
const int max_int=2'147'483'647;
const unsigned int max_uint=4'294'967'295;
const ll max_ll=9'223'372'036'854'775'807;
//const unsigned ll max_ull=18'446'744'073'709'551'615;

clock_t startTime;
double getCurrentTime() {
	return (double)(clock()-startTime)/CLOCKS_PER_SEC;
}

const long double Pi=acos(-1);

struct line {
	long double x,y;
	long double ang;

	line(long double _x=0, long double _y=0, long double _ang=0) : x(_x), y(_y), ang(_ang) {}
};

long double sqr(long double x) {
	return x*x;
}
 
line operator+(line &a, line &b) {
	return line(a.x+b.x*cos(a.ang)-b.y*sin(a.ang),a.y+b.y*cos(a.ang)+b.x*sin(a.ang),a.ang+b.ang);
}

struct segTree {
    int sze=0;
    vector<line> seg;

    segTree(int sze=0) : sze(sze) {
        seg.resize(4*sze);
        build(1,0,sze-1);
    }

    void build(int v, int tl, int tr) {
        if (tl==tr) {
            seg[v]=line(1,0,0);
        }
        else {
            int tm=tl+(tr-tl)/2;
            build(v*2,tl,tm);
            build(v*2+1,tm+1,tr);
            seg[v]=seg[v*2]+seg[v*2+1];
        }
    }

    void update(int pos, int new_val, int v, int tl, int tr) {
        if (tl==tr) {
            long double cur_sze=sqrt(sqr(seg[v].x)+sqr(seg[v].y));
            seg[v].x*=(cur_sze+new_val)/cur_sze;
            seg[v].y*=(cur_sze+new_val)/cur_sze;
        }
        else {
            int tm=tl+(tr-tl)/2;
            if (pos<=tm) {
                update(pos,new_val,v*2,tl,tm);
            }
            else {
                update(pos,new_val,v*2+1,tm+1,tr);
            }
            seg[v]=seg[v*2]+seg[v*2+1];
        }
    }
    void update(int pos, int new_val) {
        update(pos,new_val,1,0,sze-1);
    }

    void degree_update(int pos, int degree, int v, int tl, int tr) {
        if (tl==tr) {
            long double cur_ang=atan2(seg[v].y,seg[v].x);
            long double cur_sze=sqrt(sqr(seg[v].x)+sqr(seg[v].y));
            cur_ang-=degree*Pi/180;
            seg[v].x=cur_sze*cos(cur_ang);
            seg[v].y=cur_sze*sin(cur_ang);
            seg[v].ang-=degree*Pi/180;
        }
        else {
            int tm=tl+(tr-tl)/2;
            if (pos<=tm) {
                degree_update(pos,degree,v*2,tl,tm);
            }
            else {
                degree_update(pos,degree,v*2+1,tm+1,tr);
            }
            seg[v]=seg[v*2]+seg[v*2+1];
        }
    }
    void degree_update(int pos, int new_val) {
        degree_update(pos,new_val,1,0,sze-1);
    }
};

void solve() {
    int n,m;
    cin >> n >> m;
    segTree data(n);
    int num,x,y;
    cout << fixed << setprecision(12);
    for (int i=0; i<m; i++) {
        cin >> num >> x >> y;
        if (num==1) {
            x--;
            data.update(x,y);
        }
        else {
            x--;
            data.degree_update(x,y);
        }
        cout << data.seg[1].x << ' ' << data.seg[1].y << '\n';
    }
}

int32_t main() {
    startTime=clock();
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t=1;
    for (int i=0; i<t; i++) {
        testcase(i);
        solve();
        debug(getCurrentTime());
    }
    return 0;
}