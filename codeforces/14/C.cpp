/*
ID: marcofe1
TASK: hoofball
LANG: C++
*/


#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; i++)
#define FAB(i, a, b) for(int i = a; i <= b; i++)
#define SD(n) scanf("%d", &n);
#define SDD(n,m) scanf("%d%d", &n,&m)
#define SDDD(n,m,o) scanf("%d%d%d", &n,&m, &o)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<ll>

//void __prll(int x) {cerr << x;}
//void __prll(long x) {cerr << x;}
//void __prll(long long x) {cerr << x;}
//void __prll(unsigned x) {cerr << x;}
//void __prll(unsigned long x) {cerr << x;}
//void __prll(unsigned long long x) {cerr << x;}
//void __prll(float x) {cerr << x;}
//void __prll(double x) {cerr << x;}
//void __prll(long double x) {cerr << x;}
//void __prll(char x) {cerr << '\'' << x << '\'';}
//void __prll(const char *x) {cerr << '\"' << x << '\"';}
//void __prll(const string &x) {cerr << '\"' << x << '\"';}
//void __prll(bool x) {cerr << (x ? "true" : "false");}
//
//template<typename T, typename V>
//void __prll(const pair<T, V> &x) {cerr << '{'; __prll(x.first); cerr << ','; __prll(x.second); cerr << '}';}
//template<typename T>
//void __prll(const T &x) {ll f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __prll(i); cerr << "}";}
//void _prll() {cerr << "]\n";}
//template <typename T, typename... V>
//void _prll(T t, V... v) {__prll(t); if (sizeof...(v)) cerr << ", "; _prll(v...);}
//#ifndef ONLINE_JUDGE
//#define debug(x...) cerr << "[" << #x << "] = ["; _prll(x)
//#else
//#define debug(x...)
//#endif

//#define fout cout
//#define fin cin

typedef complex<int> P;
#define X real()
#define Y imag()

bool compare(const P a, const P b)
{
    return a.X!=b.X ?a.X<b.X :a.Y > b.Y;
}
bool compare2(const P a, const P b)
{
    return a.X!=b.X ?a.X<b.X :a.Y < b.Y;
}
struct L: public vector <P>  //Linea
{
    L (P a, P b)
    {
        push_back(a);
        push_back(b);
    }
};
bool exist(L a, vector<L> lines){
    FOR(i, lines.size()){
        if(a[0] == lines[i][0] && a[1] == lines[i][1]) return true;
        if(a[1] == lines[i][0] && a[0] == lines[i][1]) return true;
    }
    return false;
}
bool solve(vector<P> points, vector<L> lines){
    if(points[0].X != points[1].X) return false;
    if(points[0].X == points[2].X) return false;
    if(points[2].X != points[3].X) return false;
    if(points[0].Y == points[1].Y) return false;
    if(points[0].Y != points[2].Y) return false;
    if(points[2].Y == points[3].Y) return false;
    if(!exist(L(points[0], points[2]), lines)) return false;
    if(!exist(L(points[0], points[1]), lines)) return false;
    if(!exist(L(points[1], points[3]), lines)) return false;
    if(!exist(L(points[2], points[3]), lines)) return false;
    return true;
}



int main()
{
//    ofstream fout("hoofball.out");
//    ifstream fin("hoofball.in");


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<P> points;
    vector<L> lines;

    FOR(i, 4){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        P p1(x1, y1);
        P p2(x2, y2);
        points.pb(p1);
        points.pb(p2);
        lines.pb(L(p1, p2));
    }
    sort(points.begin(), points.end(), compare2);
    vector<P>::iterator it;
    it = unique(points.begin(), points.end());
    points.resize(distance(points.begin(), it));
    sort(points.begin(), points.end(), compare);
    if((int)points.size() == 4 && solve(points, lines)){
        cout << "YES"<<endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}


