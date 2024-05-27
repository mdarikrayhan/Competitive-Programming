#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define mp make_pair
#define pii pair<int,int> 
#define pb push_back
#define pll pair<long long, long long>
#define fi first
#define se second
#define speedboost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int,int>, null_type,  less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef long long ll;
typedef long double ld;
ll mod = 1000000007;
int N = 200000;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
const char dir[4]{'D','R','U','L'};
#define all(x) begin(x), end(x)
string yes = "YES\n";
string no = "NO\n";
ll inf = 1e18;
ll V = 2e18;

void mult(ll &x, ll &y)
{
    ll maxmult = (V + x - 1) / x;
    if (y >= maxmult)
    {
        x =  INT64_MAX;
    }
    else
    {
        x *= y;
    }
}

int main()
{
    speedboost;
    ll n, k;
    cin >> n >> k;
    vll a(n + 1);
    vector<ll> notone;
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 1)
        {
            notone.pb(i);
        }
        pref[i] = pref[i - 1] + a[i];
    }
    V = pref[n] * k;
    notone.pb(n + 1);
    ll m  = notone.size();
    vll far(n + 2);
    for (int i = 1; i <= n; i++)
    {
        ll curp = 1;
        auto it = lower_bound(all(notone), i);
        ll index = it - notone.begin();
        ll curfar = i;
        while (notone[index] <= n)
        {
            mult(curp, a[notone[index]]);
            if (curp <= V)
            {
                curfar = notone[index];
                index++;
            }
            else
            {
                curfar = notone[index] - 1;
                break;
            }
        }
        far[i] = curfar;
    }
    //cout << "V " << V << endl;
    //for (int i = 1; i <= n; i++) cout << "FAR " << i << ' ' << far[i] << endl;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        //cout << "START AT IDX " << i << "\n";
        ll cur = i;
        ll curprod = a[i];
        while (cur <= far[i])
        {
            ll low = pref[cur] - pref[i - 1];
            ll nextval = *upper_bound(all(notone), cur);
            ll high = pref[nextval - 1] - pref[i - 1];
            if (curprod % k == 0)
            {
                ll need = curprod / k;
                if (low <= need && need <= high)
                {
                    //cout << "FOUND " << i << ' ' << cur << ' ' << nextval - 1 << ' ' << low << ' ' << high << "\n";
                    ans++;
                }
            }
            //cout << "current " << i << ' ' << cur << ' ' << curprod << ' ' << nextval << endl; 
            cur = nextval;
            mult(curprod, a[cur]);
        }
    }
    cout << ans << "\n";
}