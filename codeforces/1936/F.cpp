//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
//#pragma GCC option("arch=native","tune=native","no-zero-upper")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
//#define INF 2147483647
#define infL (1LL<<60)
#define inf (1<<30)
#define inf9 (1000000000)
#define MOD  998244353 //1000000007
#define EPS 1e-9
#define Gr 9.8
#define PI acos(-1)
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REQ(i,n) for(int (i)=1;(i)<=(int)(n);(i)++)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define readmp(n) for(int i=0,u,v;i<n;i++) {scanf("%d%d",&u,&v); mp[u].push_back(v); mp[v].push_back(u);}
typedef  long long ll;
typedef pair<int, int> pii;
typedef pair<int, vector<int>> piv;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ValType;
template<typename  T> void maxtt(T& t1, T t2) {
    t1=max(t1,t2);
}
template<typename  T> void mintt(T& t1, T t2) {
    t1=min(t1,t2);
}


bool debug = 0;
int n,m,k;
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
string direc="RDLU";
const ll MOD2 = (ll)MOD * (ll)MOD;
ll ln, lk, lm;
void etp(bool f = 0) {
    puts(f ?"YES" : "NO");
    exit(0);
}
void addmod(int &x, int y, int mod = MOD){
    x+=y; if (x>=mod) x-=mod;
    if(x<0) x+=mod;
    assert(x>=0 && x<mod);
}
void et(int x=-1) {
    printf("%d\n", x); exit(0);
}
ll fastPow(ll x, ll y, int mod=MOD) {
    ll ans = 1;
    while(y>0) {
        if(y&1) ans = (x * ans)%mod;
        x = x*x%mod;
        y>>=1;
    }
    return ans;
}
ll gcd1(ll x, ll y) {
    return y?gcd1(y,x%y):x;
}

//#include <atcoder/all>
//using mint = atcoder::modint998244353;
#define MAX (500005)


struct Point {
    ValType x, y;
    Point() { }
    Point(ValType x, ValType y) : x(x), y(y) { }
    ValType abs(){return sqrt(x*x+y*y);}
    Point operator*(ValType o) const { return {x * o, y * o}; }
    Point operator+(const Point& o) const { return {x + o.x, y + o.y}; }
    Point operator-(const Point& o) const { return {x - o.x, y - o.y}; }
    Point operator/(ValType o) const { return {x / o, y / o}; }
};
struct Circle
{
    Point o;
    ValType r;
    Circle(){}
    Circle(Point _o,ValType _r):o(_o),r(_r){}
};
bool isBInA(Circle &a,Circle &b){
    return a.r>=(b.r+(a.o-b.o).abs())-(1e-10);
}
Circle base2(Circle &a,Circle &b){
    Point aa=a.o,bb=b.o,ab=bb-aa;
    Point d=ab / ab.abs();
    Point ar=aa+d*a.r,br=bb-d*b.r;
    return {(ar+br)/2,(ar-br).abs()/2};
}
Circle base3(Circle &a, Circle &b, Circle &c){
    Circle t=base2(a,b);
    if(isBInA(c,t)) return t;
    t=base2(b,c);
    if(isBInA(a,t)) return t;
    t=base2(c,a);
    if(isBInA(b,t)) return t;
    ValType x1=a.o.x,x2=b.o.x,x3=c.o.x,y1=a.o.y,y2=b.o.y,y3=c.o.y;
    ValType r1=a.r,r2=b.r,r3=c.r;
    ValType a2=x1-x2,a3=x1-x3,b2=y1-y2,b3=y1-y3,c2=r2-r1,c3=r3-r1;
    ValType d1=x1*x1+y1*y1-r1*r1,d2=d1-x2*x2-y2*y2+r2*r2,d3=d1-x3*x3-y3*y3+r3*r3;
    ValType ab=a3*b2-a2*b3;
    ValType xa=(b2*d3-b3*d2)/(ab*2)-x1;
    ValType xb=(b3*c2-b2*c3)/ab;
    ValType ya=(a3*d2-a2*d3)/(ab*2)-y1;
    ValType yb=(a2*c3-a3*c2)/ab;
    ValType A=xb*xb+yb*yb-1;
    ValType B=2*(r1+xa*xb+ya*yb);
    ValType C=xa*xa+ya*ya-r1*r1;
    ValType r=-(A?(B-sqrt(B*B-4*A*C))/(2*A):C/B);
    Point o=Point(x1+xa+xb*r,y1+ya+yb*r);
    return {o,r};
}
Circle cc[MAX];
mt19937_64 rnd(64);
void fmain(int tid) {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    REQ(i,n) {
//        scanf("%Lf%Lf%Lf", &cc[i].o.x, &cc[i].o.y, &cc[i].r);
        cin>>cc[i].o.x>>cc[i].o.y>>cc[i].r;
    }
    shuffle(cc+1,cc+1+n, rnd);
    Circle res({0,0}, 4e18);
    REQ(i,n) {
        if (!isBInA(cc[i], res)) {
            res = cc[i];
            REQ(j,i-1) if (!isBInA(cc[j], res)){
                    res = base2(cc[i], cc[j]);
                    REQ(z,j-1) if (!isBInA(cc[z], res)) {
                            res = base3(cc[i],cc[j],cc[z]);
                        }
                }
        }
    }
//    printf("%.10Lf %.10Lf %.10Lf\n", res.o.x, res.o.y, res.r);
    cout<<setprecision(10)<<fixed<<res.o.x<<" "<<res.o.y<<" "<<res.r<<endl;
}
int main() {
//    freopen("sample1.in","r",stdin);
//    freopen("so2.txt","w",stdout);
    int t=1;
//    ios::sync_with_stdio(false);
//    cin.tie(0); cout.tie(0);
//    cin>>t;
//    scanf("%d", &t);
    REQ(i,t) {
        fmain(i);
    }
    return 0;
}