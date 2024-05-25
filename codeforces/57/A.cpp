#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <numeric>
#include <cmath>
#include <deque>
#include <cctype>
#include <iomanip>
#include <queue>

using namespace std;

#define vec vector
#define ll long long
#define ull unsigned long long 
#define ii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define pp pop_back()
#define re return
#define vi vec<int>
#define vvi vec<vi>
#define si set<int>
#define vvii vec<vec<ii>>
#define vii vec<ii>
#define INF 1e9
#define mii map<int,int>
#define all(x) x.begin(), x.end()
#define INF_SMALL 1e6
#define INF_MAX 9234567890789012345LL
#define M (1000000007)
#define vll vec<ll>
#define vull vec<ull>
#define endl '\n'
#define vvull vec<vull>
#define vc vec<char>
#define vvc vec<vc>
#define ni int n;cin>>n
#define nmi int n,m;cin>>n>>m
#define nmll ll n,m;cin>>n>>m
#define vs vec<string>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define vvll vec<vll>
#define vpsisi vec<pair<si,si>>


template<class T> ostream& operator << (ostream& o, vector<T>& x) { for (auto& el : x) o << el << ' '; re o; }
template<class T> istream& operator >> (istream& o, vector<T>& x) { for (auto& el : x) o >> el; re o; }

//struct node {
//    ll sum;
//    node* le;
//    node* ri;
//    node() {
//        sum = 0;
//        le = ri = 0;
//    }
//};
//
//node arr[2000000];
//int fre = 0;
//ll get1(node* core, int core_l, int core_r, int l, int r) {
//
//    if (core_r - core_l == 1) {
//        return core->sum;
//    }
//    ll sum = core->sum;
//    int center = (core_r + core_l) / 2;
//    if (l < center) {
//        if (core->le) {
//            sum += get1(core->le, core_l, center, l, min(r, center));
//        }
//    }
//    if (r > center) {
//        if (core->ri) {
//            sum +=get1(core->ri, center, core_r, max(center, l), r);
//        }
//    }
//    return sum;
//
//}
//
////node* build1(vll& v, int l, int r) {
////    arr[fre] = node();
////    node* _node = &arr[fre];
////    fre++;
////
////    if (r - l == 1) {
////        _node->sum = 0;
////        return _node;
////    }
////    else {
////        int cn = (l + r) / 2;
////        _node->ri = build1(v, (l + r) / 2, r);
////        _node->le = build1(v, l, (r + l) / 2);
////        _node->sum = 0;
////        return _node;
////    }
////
////}
//void add_otrez(node* core, int core_l, int core_r, int l, int r, int x) {
//
//    if ((core_r-core_l==1)||(core_l == l && core_r == r)) {
//        core->sum += x; return;
//    }
//
//    int center = (core_l + core_r) / 2;
//    if (l < center) {
//        if (!core->le) {
//            arr[fre] = node();
//            core->le = &arr[fre];
//            fre++;
//        }
//        add_otrez(core->le, core_l, center, l, r, x);
//    }
//    if (r > center) {
//        if (!core->ri) {
//            arr[fre] = node();
//            core->ri = &arr[fre];
//            fre++;
//        }
//        add_otrez(core->ri, center, core_r, l, r, x);
//    }
//    return;
//
//}
bool gg(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;

    if (x2 == 0 || x2 == n) {
        swap(x1, x2);
        swap(y1, y2);
    }

    if (x1 == x2 && (x1 == 0 || x2 == n)) {
        cout << abs(y1 - y2);
        return 0;
    }
    if (y1 == y2 && (y1 == 0 || y2 == n)) {
        cout << abs(x1 - x2);
        return 0;
    }
    if (x1 == 0) {

        if (x2 == n) {

            cout << min(y1 + n + y2,n-y1 + n-y2 + n);
            return 0;

        }
        if (y2 == 0) {
            cout << y1 + x2;
            return 0;
        }
        if (y2 == n) {
            cout << n - y1 + x2;
            return 0;
        }
        else if (y2 == 0) {
            cout << y1 + x2;
            return 0;
        }
        cout << n - y1 + x2;
        return 0;
    }
    if (x1 == n) {
        if (x2 == 0) {

            cout << min(y1 + n + y2, n - y1 + n - y2 + n);
            return 0;

        }
        if (y2 == 0) {
            cout << y1 +n -  x2;
            return 0;
        }
        if (y2 == n) {
            cout << n - y1 + n - x2;
            return 0;
        }
        else if (y2 == 0) {
            cout << y1 + n - x2;
            return 0;
        }
        cout << n - y1 + x2;
        return 0;
    }
    
    cout << min(x1 + x2 + n, n - x1 + n - x2 + n);
    return 0;
}


