// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long double, long double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<ll> > matrix;
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(),x.end()
template <class T> inline T sqr(T x) { return x * x; };
template <class T> inline bool maximize(T& a, T b) { return (a < b) ? a = b, true : false; }
template <class T> inline bool minimize(T& a, T b) { return (a > b) ? a = b, true : false; }
 
string lowcase = "abcdefghijklmnopqrstuvwxyz";
string upcase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string number = "0123456789";
int dx4[] = {0, 0, -1, 1};
int dy4[] = {-1, 1, 0, 0};
int dx8[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy8[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const ll pd = 1000000007;
const ll oo = 1e17 + 1;
const int MX = 1000010, base = 137;
void TwinHter() {
    ll ts, te, k; cin >> ts >> te >> k;
    int n; cin >> n;
    vector<ll> a(n+10);
    for(int i=0; i<n; i++) cin >> a[i];

    ll minn = oo, ans = 0;
    vector<ll> valid;
    valid.push_back(0);
    for(int i=0; i<n; i++) valid.push_back(max((ll)0, a[i]-1));
    valid.push_back(te-k);
    sort(all(valid));

    ll cur = ts;
    int l = 0;
    for(ll u:valid) {
        while(a[l] <= u && l < n) {
            cur = max(cur, a[l]) + k;
            l++;
        }

        ll des = max(cur + k, u + k);
        if(des > te) break;
        if(minn > des-u) {
            minn = des-u;
            ans = u;
        }
    }
    cout << ans << '\n';
} 
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}