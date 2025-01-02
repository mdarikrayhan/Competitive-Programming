#include <bits/stdc++.h>
#include <assert.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// template<typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<typename Q> using priority_queue_r = priority_queue<Q, vector<Q>, greater<Q>>;
using ll = long long;using ld = long double;
#define el '\n'
#define S  second
#define sz(v) (ll)(v).size()
#define F  first
#define ZOON ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE freopen("inputf.txt", "r", stdin); freopen("outputf.txt", "w", stdout);
#define PI 3.14159265
int dx[]={1, -1, 0, 0, 1, 1, -1, -1}, dy[]={0, 0, 1, -1, 1, -1, -1, 1};
const int MOD =   1e9+7, N = 5e3+5;

bool check(ll &x, ll &y, ll &res)
{
    return y == res/x;
}

void updatSol(ll &sol, ll &t)
{
    sol = min(sol, t);
    ll g = __gcd(sol, t);
    sol/=g, t/=g;

    cout << sol << '/' << t;
}

void SOLVE(int test)
{
    ll t, a, b, sol=0, g, l;cin>>t>>a>>b;

    if(a > b)swap(a, b);

    sol += a-1;


    g = __gcd(a, b);
    ll bb = b/g;
    l = bb * a;

    if(!check(bb, a, l) || a>t || bb>(t+a-1)/a || b>t)
    {
        updatSol(sol, t);
        return;
    }

    sol += (t/l);

    sol += ((t/l) -1) * (a-1);

    sol += min(a-1, t%l);
    

    updatSol(sol, t);
}




int main()
{
    ZOON

    int test_cases = 1;
    // cin>>test_cases;
    for(int i = 1;i<=test_cases;i++)
    {
        SOLVE(i);
        // cout << el;
    }

//*/ 
    return 0;
}