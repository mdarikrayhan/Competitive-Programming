#include <bits/stdc++.h>
using namespace std;

typedef long long int ll; 
typedef __int128_t i128;
typedef long double ld;
typedef pair<ll, ll> pl;

#define N 200069 // 2e5 
#define L 20
//#define MOD 1000000007
//#define MOD 998244353

#define pb(i) push_back((i))
#define mp(i, j) make_pair((i), (j))

#define f(i, s, e, inc) for(ll i = (s); i < (e); i += (inc)) 
#define fd(i, s, e, dec) for(ll i = (s); i >= (e); i -= (dec))

#define p(x) cout << x << '\n'
#define tf(x) cout << ((x) ? "Yes" : "No") << '\n'

void ra(ll arr[], ll size)
{ for(ll i = 0; i < size; i++) cin >> arr[i]; }

void rv(vector<ll>& v)
{ ll n = v.size(); for(ll i = 0; i < n; i++) cin >> v[i]; }
 
void pa(ll arr[], ll size)
{ for(ll i = 0; i < size; i++) cout << arr[i] << " "; cout << '\n'; }

void pv(vector<ll>& v)
{ for(auto it: v) cout << it << " "; cout << '\n'; }

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve() 
{
    ll n, p, w, d; cin >> n >> p >> w >> d;
    ll g = __gcd(w, d);

    if(p % g != 0){
        p(-1);
    }
    else{
        ll a = w / g; ll b = d / g; ll c = p / g;
        ll xi, yi; gcd(a, b, xi, yi);

        i128 x = xi; i128 y = yi;
        x *= c; y *= c;
        

        if(y >= 0){
            i128 giveYMax = y / a;
            i128 addToXi = giveYMax * b;
            x += addToXi; y -= giveYMax * a; 
        }
        if(y < 0){
            i128 needTot = y * -1;
            i128 needMults = (needTot + a - 1) / a;
       
            y += needMults * a; x -= needMults * b;
        }


        
        if(x >= 0 && y >= 0 && x + y <= n){
            xi = x; yi = y;
            assert(xi * w + yi * d == p);
            cout << xi << " " << yi << " " << (n - xi - yi) << '\n';
        }
        else p(-1);  
    }
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    ll tt = 1; //cin >> tt; 
    f(i, 0, tt, 1) solve();
}