// #pragma GCC diagnostic warnig "-std=c++11"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define pp pop_back
#define endl '\n'
#define ff first
#define ss second
#define stop exit(0)
#define sz(x) (int)x.size()
#define pause system("pause")
#define all(x) (x).begin(),(x).end()
#define deb(x) cout << #x << "-" << x  << endl
 
typedef char chr;
typedef string str;
typedef long long ll;
typedef vector <int> vii;
typedef pair <int,int> pii;
 
const long long INF = LLONG_MAX;
const int inf = INT_MAX;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
const double PI = 2 * acos(0.0);

const int N = 2e5 + 5;

int n,x,y,ans;

inline void test_case () {  

    cin >> n;
    cout << "? " << 1 << " " << n << endl;
    cout.flush(); 
    cin >> x;
    if (x > 1 && x < n) {
        cout << "? " << 1 << " " << x << endl;
        cout.flush(); 
        cin >> y;
        if (x == y) {
            int l = 1; int r = x-1;
            while (l <= r) {
                int mid = (l+r)/2;
                cout << "? " << mid << " " << x << endl;
                cout.flush(); 
                cin >> y;
                if (x == y) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        } else {
            int l = x+1; int r = n;
            while (l <= r) {
                int mid = (l+r)/2;
                cout << "? " << x << " " << mid << endl;
                cout.flush(); 
                cin >> y;
                if (x == y) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        cout <<"! " <<  ans << endl;  
        cout.flush(); 
    } else if (x == 1)  {
        int l = x+1; int r = n;
        while (l <= r) {
            int mid = (l+r)/2;
            cout << "? " << x << " " << mid << endl;
            cout.flush(); 
            cin >> y;
            if (x == y) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout <<"! " <<  ans << endl;  
        cout.flush(); 
    } else {
        int l = 1; int r = x-1;
        while (l <= r) {
            int mid = (l+r)/2;
            cout << "? " << mid << " " << x << endl;
            cout.flush(); 
            cin >> y;
            if (x == y) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout <<"! " <<  ans << endl;  
        cout.flush(); 
    }

}
 
signed main () {
 
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) {
        test_case();
    }
    
    return 0;
 
}