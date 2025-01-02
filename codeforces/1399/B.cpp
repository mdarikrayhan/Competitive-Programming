#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define clr(x) memset(x, 0, sizeof(x))
#define all(a) a.begin(),a.end()
#define s second
#define f first
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define forn(i, a,b) for(int i = int(a); i < int(b); ++i)
#define forn_r(i, b, a) for(int i = int(b); i > int(a); i--)
#define trav(a,x) for (auto& a : x)
#define pA(array, length) for(int i = 0; i < length; i++) cout<< array[i] << (i == length - 1 ? '\n' : ' '); 
#define print(x) cout << x << '\n'
#define print2(x, y) cout << x << ' ' << y << '\n'
#define HA cout<<"YES"<<endl;
#define modi 1000000007
#define NA cout<<"NO"<<endl;
#define dbg(x) cout << #x << "=" << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
using namespace std;
typedef long long ll; 
const int INF = INT_MAX;
const ll LNF  = LONG_LONG_MAX;
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline ll  gcd(ll  a, ll  b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
 
 
 
 
void solve() {
    ll n;
    cin>>n;

    vll a(n),b(n);

    for(ll i=0;i<n; i++){
        cin>>a[i];
    }

    for(ll i=0 ; i<n ;i++){
        cin>>b[i];
    }

    ll mina = *min_element(a.begin(),a.end());
    ll minb = *min_element(b.begin(),b.end());

    ll suma = 0 , sumb = 0;
    ll ans = 0;
    for(ll i=0 ; i<n ; i++){
        // suma += a[i] - mina;
        // sumb += b[i] - minb;

        ll diff1 = a[i]-mina;
        ll diff2 = b[i] - minb;

        ll cc = min(diff1,diff2);
        ans+=cc + (diff1-cc) + (diff2-cc);
    }

    cout<<ans<<endl;

    
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) {
		solve();
	}
}