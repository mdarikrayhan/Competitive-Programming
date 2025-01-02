// LUOGU_RID: 159914848
#include<bits/stdc++.h>
using namespace std;

namespace llzGeo{
typedef long double db;
typedef long long ll;

using T=db;

constexpr T eps=1e-12;

int sgn(const T& x){
    if(fabs(x)<=eps)return 0;
    else if(x>0)return 1;
    else return -1;
}

bool eq(const T& a,const T& b){return sgn(a-b)==0;}

inline int type(T x, T y) {
    if(x == 0 and y == 0) return 0;
    if(y < 0 or (y == 0 and x < 0)) return -1;
    return 1;
}

//点 or 向量
struct Point{
    T x;
    T y;
    constexpr Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}

    //正负操作
    constexpr Point operator+() const noexcept { return *this; }
    constexpr Point operator-() const noexcept { return Point(-x, -y); }
    
    //加减操作
    constexpr Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    constexpr Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point &operator+=(const Point &p) { return x += p.x, y += p.y, *this; }
    Point &operator-=(const Point &p) { return x -= p.x, y -= p.y, *this; }

    //乘法（除法）操作
    Point &operator*=(const T &k) { return x *= k, y *= k, *this; }
    constexpr Point operator*(const T &k) { return Point(x * k, y * k); }

    constexpr bool operator==(const Point &r) const noexcept { return r.x == x and r.y == y; }

    //点积
    constexpr T operator*(const Point &p) const { return x * p.x + y * p.y; }
    //叉积
    constexpr T operator%(const Point &r) const { return x * r.y - y * r.x; }

    //x为第一关键字, y为第二关键字升序
    bool operator<(const Point &r) const { 
        if(x==r.x)return y<r.y;
        return x<r.x;
    }

    //判断r向量是否在该向量逆时针方向
    //是：1, 否：-1, 共线：0
    int toLeft(const Point& r) const {return sgn((*this)%r);}

    //向量的长度的平方
    T len2(){return (*this)*(*this);}

    //比较两个向量和x轴正方向夹角大小关系
    bool arg_cmp(const Point &r) const {
        int L = type(x, y), R = type(r.x, r.y);
        if(L != R) return L > R;
 
        T X = x * r.y, Y = r.x * y;
        if(X != Y) return X > Y;
        return x < r.x;
    }

};
}
using namespace llzGeo;
const int N=2505;

Point p[N];
ll C[N][5];

void llz(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>p[i].x>>p[i].y;
    C[0][0]=1;
    for(int i=1;i<=n;++i){
        C[i][0]=1;
        for(int j=1;j<=min(i,4);++j)C[i][j]=(C[i-1][j-1]+C[i-1][j]);
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        vector<Point> v;
        for(int j=1;j<=n;++j){
            if(j==i)continue;
            v.push_back(p[j]-p[i]);
        }
        sort(v.begin(),v.end(),[&](const Point& a,const Point& b){
            return a.arg_cmp(b);
        });
        for(int j=0;j<n-1;++j)v.push_back(v[j]);
        ans+=C[n-1][4];
        int p=0;
        for(int j=0;j<n-1;++j){
            while(p<v.size()&&p-(n-1)!=j&&sgn(v[j]%v[p])>=0)p++;
            // if(i==3){
            //     cout<<j<<" "<<v[j].x<<" "<<v[j].y<<" "<<" "<<p<<"\n";
            // }
            ans-=C[p-j-1][3];
        }
        //cout<<i<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
}

signed main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    while(T--)llz();
    return 0;
}