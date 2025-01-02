#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define oo 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define mem(a,n) memset((a),n,sizeof (a))
#define sz(s) (int) (s.size())
#define all(v) v.begin(), v.end()
void fast();
ll gcd(ll x, ll y) { return(!y ? x : gcd(y, x % y)); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
using namespace std;
struct point {
    int x, y, t;
    double p;
    point(){}
    point(int x,int y,int t,double p):x(x),y(y),t(t),p(p){}
    bool operator <(const point& e)const {
        return t < e.t;
    }
};
double dp[1000 + 5];
double dis(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
int main() {

    fast();
   
    int n; cin >> n;
    vector<point>v(n);
    for (auto& it : v)
        cin >> it.x >> it.y >> it.t >> it.p;
    sort(all(v));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (v[i].t + dis(v[i], v[j]) <= v[j].t)
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += v[i].p;
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << fixed << setprecision(10);
    cout << ans;


    return 0;
}
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
	  	   			  	 			 	  			 			 	