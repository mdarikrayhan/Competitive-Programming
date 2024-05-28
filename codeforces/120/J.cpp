#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <bitset>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <fstream>
#include <unordered_set>
#include <numeric>
#include <math.h>
#include <cassert>
#include <climits>
#include <chrono>
#include <random>
#pragma warning(disable:4996)
#define endl "\n"
#define ld long double
#define int long long
#define uint unsigned long long
#define _default std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout << fixed; cout.precision(20);
typedef long long ll;
using namespace std;
using vi = vector<long long>;
using vvi = vector<vector<long long>>;


#define dbg(x) cout << __LINE__ << ": " << #x << " = " << x << endl





ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll mod = (ll)1e9 + 7;
//ll mod = (ll)998244353;

//IMBA
int mulmod(ll a, ll b) {
    return (a * b) % mod;
}

int powmod(int a, int b) {
    if (!b) return 1;
    int p = powmod(a, b / 2);
    p = mulmod(p, p);
    return (b & 1) ? mulmod(p, a) : p;
}

int divmod(int a, int b) {
    return mulmod(a, powmod(b, mod - 2));
}

int addmod(int a, int b) {
    return (((a + mod) % mod + (b + mod) % mod) + mod) % mod;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

ostream& operator<<(ostream& o, string& a) {
    for (auto& el : a) {
        o << el;
    }
    return o;
}

template<typename T, template<typename... Args> class cont>
ostream& operator<<(ostream& o, cont<T>& a) {
    for (auto el : a) {
        o << el << " ";
    }
    o << "\n";
    return o;
}

int test;

struct point{
    int x, y, i;
    int ind;
    point(){
        x = 0;
        y = 0;
        i = 0;
        ind = 0;
    }
    point(int x, int y, int i){
        this->x = x;
        this->y = y;
        ind = i;
    }
};

int pif(int x1, int y1, int x2, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void add(unordered_map<int, vector<point>>& m, point& a, int dist){
    int X = (a.x + (dist - 1)) / dist;
    int Y = (a.y + (dist - 1)) / dist;
    m[X * mod + Y].push_back(a);
}

void solve() {
 
    int n; cin >> n;

    vector<point> a(n);

    for(int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;
        a[i] = point(abs(x), abs(y), i + 1);
        if(x < 0 && y < 0){
            a[i].i = 4;
        }
        else if(x < 0){
            a[i].i = 2;
        }
        else if(y < 0){
            a[i].i = 3;
        }
        else{
            a[i].i = 1;
        }
    }


    unordered_map<int, vector<point>> m;
    pair<point, point> ans = {a[0], a[1]};
    mt19937 g(1337);

    shuffle(a.begin(), a.end(), g);

    int dist = pif(a[0].x, a[0].y, a[1].x, a[1].y);
    if(dist == 0){
        cout << ans.first.ind << " " << ans.first.i << " " << ans.second.ind << " " << 5 - ans.second.i << endl; 
        return;
    }
    add(m, a[0], dist);
    add(m, a[1], dist);



    for(int i = 2; i < n; ++i){
        int newDist = dist;

        for(int dx = -1; dx <= 1; ++dx){
            for(int dy = -1; dy <= 1; ++dy){
                int x = a[i].x + dx * dist;
                int y = a[i].y + dy * dist;
                int X = (x + (dist - 1)) / dist;
                int Y = (y + (dist - 1)) / dist;
                for(auto& el : m[X * mod + Y]){
                    int res = pif(a[i].x, a[i].y, el.x, el.y);
                    if(res < newDist){
                        newDist = res;
                        ans = {a[i], el};
                    }
                }
            }
        }


        if(newDist < dist){
            dist = newDist;
            if(dist == 0){
                cout << ans.first.ind << " " << ans.first.i << " " << ans.second.ind << " " << 5 - ans.second.i << endl; 
                return;
            }
            m.clear();
            for(int j = 0; j < i; ++j){
                add(m, a[j], dist);
            }

        }


        

        add(m, a[i], dist);
    }

    cout << ans.first.ind << " " << ans.first.i << " " << ans.second.ind << " " << 5 - ans.second.i << endl; 
    
 
    return;
}


signed main() {
    _default;
    srand(time(NULL));
#ifdef TSAR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("hullp.in", "r", stdin);
    //freopen("hullp.out", "w", stdout);
#endif
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;

    //cin >> t;

    for (test = 1; test <= t; ++test) {
        solve();
    }



    return 0;
}

/*
7
1 1 1 6 1 1 6

5 6 6 6 6 6 6

*/