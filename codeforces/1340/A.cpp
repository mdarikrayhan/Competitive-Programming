#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ff cout.flush()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FAST ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long
#define str string
using ld = long double;
#define pb push_back
#define pf push_front
#define pob pop_back()
#define pof pop_front()
#define in insert
#define fi first
#define se second
#define begin begin()
#define end end()
#define size size()
#define rend rend()
#define rbegin rbegin()
#define ret return
#define ull unsigned long long
#define all(a) a.begin , a.end
#define gcd(a , b) __gcd(a , b)
#define lcm(a , b) (a * b) / gcd(a , b)
#define friopen freopen ("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

///                         ERASE
/*




str --  a.erase(index nachala , kolichestvo simvolov);


deque , vector -- a.erase(a.begin + index nachala , a.begin + index konca + 1);




*/

const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ld esp = 0.0000001;

ll binpow(ll x , ll y)
{
    if (y == 0) ret 1;
    else if (y == 1) ret x;
    else if (y % 2 == 1) ret binpow(x , y - 1) * x;
    else ret binpow(x , y / 2) * binpow(x , y / 2);
}

ll pow_q(ll a23, ll n23) {
  if(n23 == 0){
    return 1;
  }
  if (n23 == 1) {
    return a23 % mod;
  } else if (n23 % 2 == 1) {
    return (a23 % mod * pow_q(a23, n23 - 1) % mod);
  } else {
    ll otvet = pow_q(a23, n23 / 2) % mod;
    return (otvet % mod * otvet);
  }
}


ll sum_ (ll x)
{
    ret x * (x + 1) / 2;
}


void kol_a()
{
    ll n , i , j , r;
    cin >> n;
    ll a[n + 12] = {};
    for (i = 1 ; i <= n ; i ++) cin >> a[i];
    for (i = 2 ; i <= n ; i ++)
    {
        if (a[i] - a[i - 1] > 1)
        {
            cout << "No\n";
            ret ;
        }
    }
    cout << "Yes\n";
}


main()
{
	FAST
	//friopen
    ll _ = 1;
    cin >> _;
    while(_ --) kol_a();
}

/*

*/
