#include <bits/stdc++.h>

#define fi first
#define se second
#define For(i, a, b) for (int i=a;i<=b;++i)
#define Ford(i, a, b) for(int i=a;i>=b;--i)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N=2*1e5+5;
const int oo=2*1e9;



ii EuEx(ll a, ll b) 
{
    if (!b) return {1, 0};
    ii x = EuEx(b, a%b);
    return {x.se, x.fi - a/b * x.se};
}

ll calc(ll a, ll b, ll c, ll max_x, ll max_y)
{
    ll g = __gcd(a, b);
    if (c % g != 0) {cout << -1; exit(0);}
    
    ii x = EuEx(a, b);

    x.fi *= c / g, x.se *= c / g;

    ll add_x = b / g, add_y = -a / g;
    if (add_x < 0) add_x *= -1, add_y *= -1;

    ll t;
    if (x.fi < max_x) t = (max_x - x.fi) / add_x;
    else t = - (x.fi - max_x + add_x - 1) / add_x;
    ii x1 = {x.fi + t * add_x, 
             x.se + t * add_y};

    if (x.se < max_y) t = (max_y - x.se) / add_y;
    else t = - (x.se - max_y + add_y - 1) / add_y;
    ii x2 = {x.fi + t * add_x, 
             x.se + t * add_y};

    if (x1.fi > 0 && x1.se <= max_y && x1.se > 0) return x1.fi;
    return x2.fi;
}

void solve()
{
	ll a, h, w;
	cin >> a >> h >> w;
	ll t = calc(-a-w, h+a, w-h, h/a, w/a);	
    
    if (t <= 0) {cout << -1; return;}

    double x = (1.0 * h - 1.0 * t * a) / (1.0 * t + 1.0);
    cout << fixed << setprecision(12) << x;
}

int main()
{
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	solve();

	return 0;
}
