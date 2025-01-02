#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
const ll mod = 1e9 + 7;
#define fr first
#define sc second
#define pb push_back
#define inf (1LL<<62)
#define all(v) v.begin(), v.end()
#define all1(v) v.begin()+1, v.end()
#define done(x){ cout << x << endl;return;}
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i < n; i++)
#define rep(i, st, end) for(int i=st; i<end; i++)
#define rrep(i,st,end) for(int i=st; i>=end; i--)


const ll N = 2e5+ 5;
const ll INF=1e18;



void solve(void){
    
    
    ll a, b, k;
    cin>> a>> b>> k;

    ll ans = 0;

    ans += (k+ 1)/2;
    ans *= a;

    ans -= (k/2)*b;

    done(ans)

}

int main()
{
    ll t;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    t = 1;
    cin >> t;
    f(i, t) solve();
    return 0;
}