#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
/*--------------------------priority 1--------------------------*/
typedef long long int ll;
typedef int ii;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned char uchar;
typedef pair<ll, ll> pll;
typedef pair<ld,ld> pff;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<ld> vld;
typedef vector<char> vch;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvld;
typedef vector<vector<ull>> vvull;
typedef vector<ui> vui;
typedef vector<ull> vull;
typedef vector<vector<ii>> vvii;
typedef vector<vector<char>> vvch;
typedef set<ll> sll;
typedef pair<int,int> pii;
typedef unordered_set<ll> usll;
typedef queue<ll> qll;
typedef  deque<ll> dll;
typedef stack<ll> stll;
typedef unordered_set<ii> usii;
typedef queue<ii> qii;
typedef  deque<ii> dii;
typedef stack<ii> stii;

#define ACspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
/*--------------------------priority 2--------------------------*/
#define fr(i,m,n) for(ll i=m;i<n;++i)
#define rfr(i,m,n) for(ll i=m;i>n;--i)
#define afr(i,x) for(auto i : x)

#define all(a) begin(a),end(a)
#define rall(a) rbegin(a),rend(a)
/*--------------------------priority 3--------------------------*/
#define frh(i,m,n,h) for(ll i=m;i<n;i+=h)
#define rfrh(i,m,n,h) for(ll i=m;i>n;i-=h)

#define yeah cout << "YES\n"
#define nah cout << "NO\n"
#define wr cout<<"-1\n"
/*--------------------------priority 4--------------------------*/
#define pa pair
#define qe queue
#define ve vector
#define ins insert
#define pb emplace_back
/*--------------------------priority 5--------------------------*/
#define make_uniq(a) a.resize(unique(begin(a),end(a))-begin(a))
#define rev reverse
#define re return
#define br break
/*--------------------------priority 6--------------------------*/
#define INF LLONG_MAX
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
#define mp make_pair
#define X first
#define Y second
#define amin(x,y) x=min(x,y)
#define amax(x,y) x=max(x,y)

#define PI M_PI
const ld rad = 180 / PI;
//const ii c = 1e+7;

#define endl "\n"

template<class T, class U>
istream& operator>>(istream & in, pair<T, U> &v) {
    in >> v.X >> v.Y;
    return in;
}

template<class T, class U>
ostream& operator<<(ostream & out, pair<T, U> &v) {
    out << v.first << " " << v.second;
    return out;
}

template<class T>
istream& operator>>(istream & in, vector <T> &v) {
    for (auto& x : v) { in >> x; }
    return in;
}

template<class T>
ostream& operator<<(ostream & out, vector <T> &v) {
    for (auto& x : v) { out << x << " "; }
    return out;
}

ll gcd(ll a, ll b)
{
    re(b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    re a*b / gcd(a, b);
}

template<class T>
T pow2(T a, T n, T mod=INF)
{
    T res=1;
    while (n)
    {
        if (n & 1) res *= a,res%=mod;
        a *= a;
        a%=mod;
        n >>= 1;
    }

    re res;
}

// segment tree
vll tree,bonus;

void push(ll t, ll tl, ll tr)
{
    if (bonus[t] != 0)
    {
        ll tc = (tl + tr) / 2;
        bonus[2 * t + 1] = bonus[t];
        bonus[2 * t + 2] = bonus[t];
        tree[2 * t + 1] = bonus[t] * (tc - tl);
        tree[2 * t + 2] = bonus[t] * (tr - tc);
        bonus[t] = 0;
    }
}

void update(ll t, ll tl, ll tr, ll l, ll r, ll x)
{
    if (tl == l && tr == r)
    {
        tree[t] = (r - l) * x;
        bonus[t] =x;
        re;
    }

    push(t, tl, tr);
    ll tc = (tl + tr) / 2;
    if (l < tc) update(2 * t + 1, tl, tc, l, min(r, tc), x);
    if (r > tc) update(2 * t + 2, tc, tr, max(l, tc), r, x);

    tree[t] = tree[2 * t + 1] + tree[2 * t + 2];
}

ll get(ll t, ll tl, ll tr, ll l, ll r)
{
    ll ans = 0;
    if (tl == l && tr == r) re tree[t];

    push(t, tl, tr);
    ll tc = (tl + tr) / 2;

    if (l < tc) ans += get(2 * t + 1, tl, tc, l, min(r, tc));
    if (r > tc) ans += get(2 * t + 2, tc, tr, max(l, tc), r);

    re ans;
}

vll v;

void precalc(){}

void solve()
{
    string s; cin>>s;
    vll heavy(s.size()+1);
    vll metal(s.size()+1);
    string x=s.substr(0,4);
    fr(i,4,s.size())
    {
        x+=s[i];
        if(x=="heavy") heavy[i+1]=heavy[i]+1;
        else heavy[i+1]=heavy[i];

        if(x=="metal") metal[i+1]=metal[i]+1;
        else metal[i+1]=metal[i];

        rev(all(x));
        x.pop_back();
        rev(all(x));
    }

    ll ans=0;
    fr(i,1,s.size()+1)
    {
        if(heavy[i]>heavy[i-1])
        {
            ans+=metal.back()-metal[i];
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ACspeed;

    //freopen("points.in", "r", stdin);freopen("points.out", "w", stdout);

    precalc();

    ll t = 1;
    //cin >> t;
    while (t--) solve();
}